#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <syslog.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *dir, *writefile, *writestr;
    int fd;
    ssize_t wr;
    struct stat sb;

    if (argc != 3) {
        syslog(LOG_ERR, "Wrong number of arguments");
        return 1;
    }

    writefile = argv[1];
    writestr = argv[2];

    fd = open(writefile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        syslog(LOG_ERR, "Error opening '%s': %s", writefile, strerror(errno));
        return 1;
    }

    wr = write(fd, writestr, strlen(writestr));
    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);
    if (wr == -1) {
        syslog(LOG_ERR, "Error writing into '%s': %s", writefile, strerror(errno));
        return 1;
    }

    close(fd);

    return 0;
}
