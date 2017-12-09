#include <stdio.h>
#include <unistd.h>
#include "version.h"
#include "types.h"

stat_t put_vinfo(void)
{
        if (printf("version %d.%d\n",
               (int)MAJOR_VERSION,
               (int)MAJOR_VERSION
                    ) <= 0) {
                /*
                 * EOF
                 * Depending on processing system.
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
