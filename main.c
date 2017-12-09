#include <stdio.h>
#include "types.h"
#include <unistd.h>

static int main_loop(void);
stat_t proc_opt(int argc, char **argv);

int main(int argc, char **argv)
{
        proc_opt(argc, argv);
        main_loop();
}

static int main_loop(void)
{
        while (1) {
                return 0;
        }
}
