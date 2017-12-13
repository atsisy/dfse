#ifndef __DFSE_FILEIO_H
#define __DFSE_FILEIO_H

#include <stddef.h>
#include "types.h"

struct block {

        /*
         * Size of a block of disk
         */
        u64 bsz;

        /*
         * block buffer
        */
        u8 *buffer;

};

/*
 * disk_struct.c
 * block_init
 * author: Akihiro Takai
 * date: H29/12/13
 */
struct block *block_init(struct block *block, u64 size);


struct disk {

        /*
         * file descriptor
         */
        int fd;

        /*
         * Number of block disk has
         */
        u64 dbsz;

};

/*
 * disk_struct.c
 * disk_init
 * author: Akihiro Takai
 * date: H29/12/13
 */
struct disk *disk_init(struct disk *disk, u64 dbsize);


/*
 * diskio.c
 * create_disk
 * author: Akihiro Takai
 * date: H29/12/10
 */
stat_t create_disk(const char *file_name, size_t size);

/*
 * cmd_opt.c
 * cmdtok
 * author: Akihiro Takai
 * date: H29/12/9
 */
char ** cmdtok(const char *str, int *argcp, char ***argvp);

/*
 * cmd_opt.c
 * proc_dfse_sh_opt
 * author: Akihiro Takai
 * date: H29/12/9
 */
stat_t proc_dfse_sh_opt(int argc, char **argv);

/*
 * cmd_opt.c
 * rm_tail_nl
 * author: Akihiro Takai
 * date: H29/12/10
 */
stat_t rm_tail_nl(char *str, size_t size);

#endif
