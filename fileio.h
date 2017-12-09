#ifndef __DFSE_FILEIO_H
#define __DFSE_FILEIO_H

/*
 * create_disk.c
 * create_disk_file
 * author: Akihiro Takai
 * date: H29/12/9
 */
stat_t create_disk_file(const char *disk_file_name);

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

#endif
