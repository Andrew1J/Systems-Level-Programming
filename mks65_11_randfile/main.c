#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

unsigned int rand_num(int data) {
    // read data into ret
    unsigned int ret;
    int err = read(data, &ret, sizeof(ret));
    if(err == -1) {
        printf("Error:\n");
        printf("%s\n", strerror(errno));
        return 0;
    }
    return ret;
}

int main() {
    // POPULATING ARRAY FROM "/dev/random"
    int data = open("/dev/random",O_RDONLY);
    unsigned int arr[10], i, err;

    printf("Generating random numbers:\n");
    for(i=0;i<10;i++){
        arr[i] = rand_num(data);
        printf("\trandom %d: %u\n",i, arr[i]);
    }

    // WRITE TO NEW FILE
    printf("\nWriting numbers to file...\n\n");
    // create and open out.txt
    int file = open("out.txt",O_CREAT | O_WRONLY | O_EXCL, 0644);
    if(file==-1){
        printf("Error:\n");
        printf("%s\n", strerror(errno));
        return 0;
    }

    // write to out.txt
    err = write(file, arr, sizeof(arr));
    if(err==-1){
        printf("Error:\n");
        printf("%s\n", strerror(errno));
        return 0;
    }

    // READ FROM NEW FILE
    printf("Reading numbers from file...\n\n");
    // open out.txt
    file = open("out.txt",O_RDONLY);
    if(err == -1) {
        printf("Error:\n");
        printf("%s\n", strerror(errno));
        return 0;
    }

    // read out.txt
    unsigned int arr2[10];
    err = read(file,arr2,sizeof(arr2));
    if(err == -1) {
        printf("Error:\n");
        printf("%s\n", strerror(errno));
        return 0;
    }

    // PRINT NEW FILE
    printf("Verification that written values were the same:\n");
    for(i=0;i<10;i++){
        printf("\trandom %d: %u\n",i, arr2[i]);
    }

    return 0;
}
