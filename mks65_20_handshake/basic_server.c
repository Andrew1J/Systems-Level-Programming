#include "pipe_networking.h"


int main() {

    int to_client;
    int from_client;

    while (1) { // Continually starts handshake even after client disconnects
        from_client = server_handshake( &to_client );

        char line[BUFFER_SIZE];
        while (1) { // Prompt client for input
            int err = read(from_client, line, sizeof(line)); // reads data from client
            if(err == -1) {
                printf("Error: %s\n", strerror(errno));
                return 0;
            }

            // process string to all lower
            for(int i=0; i<strlen(line); i++) {
                line[i] = tolower(line[i]);
            }
            err = write(to_client, line, sizeof(line)); // send data to client
            if(err == -1) {
                printf("Error: %s\n", strerror(errno));
                return 0;
            }
        }
    }
}
