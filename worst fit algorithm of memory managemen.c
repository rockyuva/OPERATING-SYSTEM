#include <stdio.h>

#define MEMORY_SIZE 100

// Structure to represent a memory block
struct MemoryBlock {
    int size;
    int allocated;
};

// Function to initialize memory blocks
void initializeMemory(struct MemoryBlock memory[], int size) {
    for (int i = 0; i < size; i++) {
        memory[i].size = 0;
        memory[i].allocated = 0;
    }
}

// Function to display the memory status
void displayMemory(struct MemoryBlock memory[], int size) {
    printf("Memory Status:\n");
    for (int i = 0; i < size; i++) {
        if (memory[i].allocated) {
            printf("Block %d: Allocated (Size: %d)\n", i, memory[i].size);
        } else {
            printf("Block %d: Free (Size: %d)\n", i, memory[i].size);
        }
    }
    printf("\n");
}

// Function to allocate memory using the Best Fit algorithm
void bestFit(struct MemoryBlock memory[], int size, int requestSize) {
    int bestFitIndex = -1;
    int bestFitSize = MEMORY_SIZE + 1; // Initialize with a large size

    for (int i = 0; i < size; i++) {
        if (!memory[i].allocated && memory[i].size >= requestSize && memory[i].size < bestFitSize) {
            bestFitSize = memory[i].size;
            bestFitIndex = i;
        }
    }

    if (bestFitIndex == -1) {
        printf("Memory allocation failed. No suitable block found.\n");
    } else {
        memory[bestFitIndex].allocated = 1;
        printf("Allocated %d units of memory in Block %d\n", requestSize, bestFitIndex);

        // If there's any remaining free space in the block, split it
        if (memory[bestFitIndex].size > requestSize) {
            memory[bestFitIndex].size -= requestSize;
            memory[bestFitIndex + 1].size = requestSize;
            memory[bestFitIndex + 1].allocated = 0;
        }
    }
}

int main() {
    struct MemoryBlock memory[MEMORY_SIZE];
    int requestSize;

    // Initialize memory blocks
    initializeMemory(memory, MEMORY_SIZE);

    // Display the initial memory status
    displayMemory(memory, MEMORY_SIZE);

    while (1) {
        printf("Enter the memory request size (or -1 to exit): ");
        scanf("%d", &requestSize);

        if (requestSize == -1) {
            break;
        }

        bestFit(memory, MEMORY_SIZE, requestSize);

        // Display the updated memory status
        displayMemory(memory, MEMORY_SIZE);
    }

    return 0;
}

