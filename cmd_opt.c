#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "version.h"
#include "types.h"

char ** cmdtok(const char *str, int *argcp, char ***argvp);

stat_t put_vinfo(void)
{
        if (printf("version %d.%d\n",
               (int)MAJOR_VERSION,
               (int)MAJOR_VERSION
                    ) <= 0) {
                /*
                 * EOF value is epending on processing system.
                 * 0 or -1
                 */
                return -1;
        }

        return 0;
}

stat_t proc_opt(int argc, char **argv)
{
        int opt;

	while ((opt = getopt(argc, argv, "v")) != -1) {
		switch (opt) {
                case 'v': return put_vinfo();
                default: // Invalid argument
                        printf("Bad command line argument.\n"); return -1;
		}
	}

        return -1;
}

stat_t proc_dfse_sh_opt(int argc, char **argv)
{
        int opt;

        return 0;
}

int cntword(const char *str, char key)
{
        char flag = 0;
        int count = 0;
        char *p = str;

        if (!p) {
                return -1;
        }

        while (*p++) {
                if (*p == key) {
                        flag = 0;
                }

                if(!flag && *p != key) {
                        flag = 1;
                        ++count;
                }
        }

        return count;
}


char ** spilit(int count, const char *str, char ***strsp)
{
        if (count <= 0 || !str) {
                return NULL;
        }

        char *strp = str;
        char **result, **resultp;
        result = resultp = (char **)malloc(sizeof(char *) * count);

        if (!resultp) {
                perror("memory alloc error.");
                return NULL;
        }

        *resultp = strtok(strp, " ");
        --count;

        while (count--) {
                *(++resultp) = strtok(NULL, " ");
        }

        *strsp = result;
        return *strsp;
}

char ** cmdtok(const char *str, int *argcp, char ***argvp)
{
        if ((*argcp = cntword(str, ' ')) == -1) {
                return NULL;
        }

        if (!spilit(*argcp, str, argvp)) {
                return NULL;
        }

        return *argvp;
}
