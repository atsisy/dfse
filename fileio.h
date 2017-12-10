#ifndef __DFSE_FILEIO_H
#define __DFSE_FILEIO_H

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
