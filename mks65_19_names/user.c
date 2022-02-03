#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    // Create both pipes
    mkfifo("toChild",0644);
    mkfifo("toParent",0644);

    // Open pipes
    int toParent = open("toParent",O_RDONLY);
    int toChild = open("toChild", O_WRONLY);

    // Prompt Input
    char line[4096];
    while (1) {
        printf("Relay Message to Worker: ");
        fgets(line, 4096, stdin);
        write(toChild, line, sizeof(line)); // send input to child
        read(toParent, line, sizeof(line)); // reads response from child
        printf("Message from Worker: %s\n", line); // displays response to user
    }
    return 0;
}
