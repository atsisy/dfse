#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "types.h"
#include "fileio.h"
#include "magic.h"

static int main_loop(void);
stat_t proc_opt(int argc, char **argv);

#define CMD_BUFFER_SIZE 8192

int main(int argc, char **argv)
{
        int fin_stat;

        proc_opt(argc, argv);

        if (fin_stat = main_loop()) {
                fprintf(stderr, "Abnormal termination.");
                fprintf(stderr, "error code: %d\n", fin_stat);
        }

        return 0;
}

static int main_loop(void)
{
        char cmd[CMD_BUFFER_SIZE];
        int argc;
        char **argv;
        stat_t fin_stat;

        while (1) {
                memset(cmd, 0, CMD_BUFFER_SIZE);
                printf(">>> ");
                fgets(cmd, CMD_BUFFER_SIZE, stdin);
                rm_tail_nl(cmd, CMD_BUFFER_SIZE);
                cmdtok(cmd, &argc, &argv);
                fin_stat = proc_dfse_sh_opt(argc, argv);

                switch (fin_stat) {
                case _MAG_QUIT:
                        goto out;
                default:
                        break;
                }
        }

out:
        return 0;
}
