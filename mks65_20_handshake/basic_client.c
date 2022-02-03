#include "pipe_networking.h"


int main() {

    int to_server;
    int from_server;

    // Starts the handshake
    from_server = client_handshake( &to_server );
    printf("shook hands!!!\n");

    // Prompt Client for Input
    while (1) {
        char line[BUFFER_SIZE];
        printf("Relay Message to Server: ");
        fgets(line, BUFFER_SIZE, stdin);
        int err = write(to_server, line, sizeof(line)); // send data to server
        if(err == -1) {
            printf("Error: %s\n", strerror(errno));
            return 0;
        }
        err = read(from_server, line, sizeof(line)); // reads processed data from server
        if(err == -1) {
            printf("Error: %s\n", strerror(errno));
            return 0;
        }
        printf("Response From Server: %s\n", line); // displays processed data to server
    }
}
