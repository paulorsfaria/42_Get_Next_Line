# get_next_line

Welcome to `get_next_line` – a function that reads a line from a file descriptor! 

## About

`get_next_line` is a C function designed to read a line from a file descriptor, handling multiple file descriptors simultaneously. It allows for reading, buffering, and handling of lines of varying lengths from different file descriptors.

## Features

- **Reading from File Descriptor:** Reads a line from a file descriptor without losing the reading thread's position.
- **Buffering:** Handles varying line lengths and manages reading from multiple file descriptors.
- **Dynamic Memory Allocation:** Allocates memory as needed for reading lines of arbitrary lengths.
- **Supports Multiple File Descriptors:** Supports reading from multiple file descriptors concurrently.

## Usage

To use `get_next_line` in your project, include the `get_next_line.h` header file and add the `get_next_line.c` file to your project. Call the function with the file descriptor and a pointer to a character buffer to store the read line.

Example usage:

```c
#include "get_next_line.h"

int main() {
    int fd;
    char *line;

    fd = open("example.txt", O_RDONLY);
    while (get_next_line(fd, &line) > 0) {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return 0;
}
