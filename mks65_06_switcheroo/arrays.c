#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // #1
    int arr[10];

    // #2
    int i;
    arr[0] = 0;
    srand(time(NULL));
    for(i=1;i<10;i++){
        arr[i]=rand();
    }

    // #3
    for(i=0;i<10;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // #4
    int arr2[10];

    // #5
    int *ap = arr;
    int *a2p = arr2;

    // #6
    for(i=9;i>=0;i--){
        arr2[i]=arr[10-i-1];
    }
    for(i=0;i<10;i++){
        printf("%d ", arr2[i]);
    }

    for(i=9;i>=0;i--){
        *(a2p+i) = *(ap+10-i-1);
    }
    printf("\n");
    for(i=0;i<10;i++){
        printf("%d ", arr2[i]);
    }
    printf("\n");


    return 0;
}
