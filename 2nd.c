#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    // Open the source file for reading
    int source_fd = open("source.txt", O_RDONLY);
    if (source_fd == -1) {
        perror("Failed to open source.txt");
        exit(EXIT_FAILURE);
    }

    // Open or create the destination file for writing
    int dest_fd = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (dest_fd == -1) {
        perror("Failed to open destination.txt");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    ssize_t bytes_read;

    // Read from the source file and write to the destination file
    while ((bytes_read = read(source_fd, buffer, sizeof(buffer))) > 0) {
        if (write(dest_fd, buffer, bytes_read) != bytes_read) {
            perror("Write error");
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read < 0) {
        perror("Read error");
        exit(EXIT_FAILURE);
    }

    // Close the files
    close(source_fd);
    close(dest_fd);

    printf("File copy successful.\n");

    return 0;
}
