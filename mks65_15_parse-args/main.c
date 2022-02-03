#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char ** parse_args( char * line ) {
    char *curr = line;
    char *token;
    char ** args = malloc(5*sizeof(char *));

    int i=0;
    while((token = strsep(&curr," "))) {
        args[i] = token;
        i++;
    }
    return args;
}

int main () {
    char line[100] = "ls -a -l";
    char ** args = parse_args( line );
    execvp(args[0], args);

    return 0;
}
