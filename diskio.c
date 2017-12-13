#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "types.h"

int create_disk_file(const char *disk_file_name)
{
        int fd;

        fd = open(disk_file_name, O_CREAT | O_RDWR, 0755);

        if (fd == -1) {
                perror("create disk file");
                return -1;
        }

        return fd;
}

stat_t mkzero(int fd, size_t size)
{
        char zero[1024] = { 0 };

        while (size--) {
                if (write(fd, zero, 1024) != 1024) {
                        return -1;
                }
        }

        return 0;
}


stat_t create_disk(const char *file_name, size_t size)
{
        int fd;

        fd = create_disk_file(file_name);

        if (fd == -1) {
                return -1;
        }

        if (mkzero(fd, size) == -1) {
                return -1;
        }

        close(fd);

        return 0;
}

stat_t generic_write_disk(const char *buf, size_t count)
{
        
}
