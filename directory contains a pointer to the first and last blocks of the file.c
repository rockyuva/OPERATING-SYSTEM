#include <stdio.h>
#include <stdlib.h>

// Define a structure for a disk block
struct DiskBlock {
    int blockNumber;
    struct DiskBlock* next;
};

// Define a structure for a file
struct File {
    char name[50];
    struct DiskBlock* firstBlock;
    struct DiskBlock* lastBlock;
};

// Function to create a new file
struct File* createFile(char* name) {
    struct File* newFile = (struct File*)malloc(sizeof(struct File));
    if (newFile == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newFile->name, name);
    newFile->firstBlock = NULL;
    newFile->lastBlock = NULL;
    return newFile;
}

// Function to add a block to a file
void addBlock(struct File* file, int blockNumber) {
    struct DiskBlock* newBlock = (struct DiskBlock*)malloc(sizeof(struct DiskBlock));
    if (newBlock == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newBlock->blockNumber = blockNumber;
    newBlock->next = NULL;

    if (file->lastBlock == NULL) {
        file->firstBlock = newBlock;
        file->lastBlock = newBlock;
    } else {
        file->lastBlock->next = newBlock;
        file->lastBlock = newBlock;
    }
}

// Function to display the blocks of a file
void displayFile(struct File* file) {
    printf("File: %s\n", file->name);
    struct DiskBlock* currentBlock = file->firstBlock;
    while (currentBlock != NULL) {
        printf("Block: %d\n", currentBlock->blockNumber);
        currentBlock = currentBlock->next;
    }
}

int main() {
    struct File* file1 = createFile("file1");
    struct File* file2 = createFile("file2");

    // Allocate blocks to files
    addBlock(file1, 1);
    addBlock(file1, 2);
    addBlock(file2, 3);
    addBlock(file1, 4);
    addBlock(file2, 5);

    // Display file contents
    displayFile(file1);
    displayFile(file2);

    return 0;
}

