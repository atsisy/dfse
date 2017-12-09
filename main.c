#include <stdio.h>
#include <unistd.h>
#include "types.h"
#include "fileio.h"

static int main_loop(void);
stat_t proc_opt(int argc, char **argv);

#define CMD_BUFFER_SIZE 8192

int main(int argc, char **argv)
{
        proc_opt(argc, argv);
        main_loop();
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
                proc_dfse_sh_opt(argc, argv);
        }
}
