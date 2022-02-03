#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define READ 0
#define WRITE 1

int main() {
    int toChild[2];
    int toParent[2];
    pipe(toChild);
    pipe(toParent);

    char line[4096];
    int f = fork();

    if (f) { // Parent
        // Close ends of pipes
        close(toChild[READ]);
        close(toParent[WRITE]);

        // Prompt User for Input
        char line[4096];
        while (1) {
            printf("Relay Message to Child: ");
            fgets(line, 4096, stdin);
            write(toChild[WRITE], line, sizeof(line)); // send input to child
            read(toParent[READ], line, sizeof(line)); // reads response from child
            printf("Message from Child: %s\n", line); // displays response to user
        }
    }

    else { // Child
        // Close ends of pipes
        close(toChild[WRITE]);
        close(toParent[READ]);

        // Prompt User for Input
        char line[4096];
        while (1) {
            read(toChild[READ], line, sizeof(line)); // reads from parent

            // process string to all lower
            for(int i=0; i<strlen(line); i++) {
                line[i] = tolower(line[i]);
            }
            write(toParent[WRITE], line, sizeof(line));  // send response to parent
        }
    }

    return 0;
}
