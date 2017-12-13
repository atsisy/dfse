#include "fileio.h"
#include "linux.h"

struct block *block_init(struct block *block, u64 size)
{
        /*
         * allocate memory of struct block
         */
        block = kmalloc(sizeof(struct block));

        if (!block)
                return NULL;

        /*
         * allocate memory of block->buffer
         * type of buffer is u8 *. one byte * size
         */
        block->buffer = kmalloc(size);

        if (!block->buffer)
                return NULL;

        return block;
}


struct disk *disk_init(struct disk *disk, u64 dbsize)
{
        /*
         * allocate memory of struct disk
         */
        disk = (struct disk *)kmalloc(sizeof(struct disk));

        if (!disk)
                return NULL;

        /*
         * set block size of disk
         */
        disk->dbsz = dbsize;

        return disk;
}
