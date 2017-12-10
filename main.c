#include <stdio.h>
#include <unistd.h>
#include "types.h"
#include "fileio.h"

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

        while (1) {
                printf(">>> ");
                fgets(cmd, CMD_BUFFER_SIZE, stdin);
                cmdtok(cmd, &argc, &argv);
                if (proc_dfse_sh_opt(argc, argv)) {
                        return -1;
                }
        }

        return 0;
}
