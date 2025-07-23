#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

int main (int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Error: Missing required arguments.\n");
        fprintf(stderr, "Usage: %s <writefile> <writestr>\n", argv[0]);
        exit(1);
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];

    // Open syslog with LOG_USER facility
    openlog("file_writer", LOG_PID | LOG_CONS, LOG_USER);

    // Attempt to create or overwrite the file
    FILE *fp = fopen(writefile, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not create file '%s'.\n", writefile);
        syslog(LOG_ERR, "Failed to create file '%s'", writefile);
        closelog();
        exit(1);
    }

    // Write string to file
    if (fprintf(fp, "%s", writestr) < 0) {
        fprintf(stderr, "Error: Failed to write to file '%s'.\n", writefile);
        syslog(LOG_ERR, "Failed to write to file '%s'", writefile);
        fclose(fp);
        closelog();
        exit(1);
    }

    // Log debug message to syslog
    syslog(LOG_DEBUG, "Writing '%s' to '%s'", writestr, writefile);

    // Cleanup
    fclose(fp);
    closelog();

    return 0;
}
