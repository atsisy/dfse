#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "types.h"

stat_t create_disk_file(const char *disk_file_name)
{
        int fd;

        fd = open(disk_file_name, O_CREAT);

        if (fd == -1) {
                perror("create disk file");
                return 01;
        }

        return 0;
}
