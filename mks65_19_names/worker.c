#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

int main() {
    // Open Pipes
    int toParent = open("toParent",O_WRONLY);
    int toChild = open("toChild", O_RDONLY);

    // Prompt User for Input
    char line[4096];
    while (1) {
        read(toChild, line, sizeof(line)); // reads from parent

        // process string to all lower
        for(int i=0; i<strlen(line); i++) {
            line[i] = tolower(line[i]);
        }
        write(toParent, line, sizeof(line));  // send response to parent
    }
    return 0;
}
