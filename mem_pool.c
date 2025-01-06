#include "mem_pool.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

static mem_block_t* gPool = NULL;

int alloc_mem_pool(int numBlocks, size_t blockSize) {
    // Allocate blocks of memory from the heap for the memory pool
    gPool = malloc(numBlocks * sizeof(mem_block_t));

    if (gPool == NULL) {
        printf("[!] Failed to initialise memory pool\n");
        return -1;
    }

    for (int i = 0; i < numBlocks; i++) {
        // Allocate memory for each memory block
        gPool[i].ptr = malloc(blockSize);
        gPool[i].size = blockSize;
        gPool[i].isFree = false;

        if (gPool[i].ptr == NULL) {
            printf("[!] Memory pool ptr is null\n");
            return -1;
        }

        printf("[*] Block at %p, size is %zu\n", gPool[i].ptr, gPool[i].size);
    }

    printf("[*] Allocated memory pool\n");

    return 0;
}

void free_mem_pool(int numBlocks) {
    for (int i = 0; i < numBlocks; i++) {
        printf("[*] Freed block at %p with a size of %zu\n", gPool[i].ptr, gPool[i].size);
        gPool[i].isFree = true;
        free(gPool[i].ptr);
    }

    free(gPool); // Finally, free the pool
    printf("[*] Freed memory pool\n");
}

int main(void) {
    int numBlocks;
    printf("[>] Enter number of blocks for pool: ");
    scanf("%d", &numBlocks);

    size_t blockSize;
    printf("[>] Enter size of each block: ");
    scanf("%zu", &blockSize);

    printf("[*] Allocating memory pool...\n");
    if (alloc_mem_pool(numBlocks, blockSize) == -1) {
        return -1;
    }

    free_mem_pool(numBlocks);

    return 0;
}


