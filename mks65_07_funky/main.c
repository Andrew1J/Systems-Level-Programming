#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1
void printArr (int *arr, int l) {
    int i;
    printf("%c ", '[');
    for(i=0;i<l;i++){
        printf("%d ", *(arr+i));
    }
    printf("%c\n", ']');
}

// 2
double avgArr (int *arr, int l) {
    int i;
    double sum=0;
    for(i=0;i<l;i++){
        sum += *(arr+i);
    }
    return sum/l;
}

// 3
void copyArr(int *arr1, int *arr2, int l) {
    int i;
    for(i=0;i<l;i++){
        *(arr2+i) = *(arr1+i);
    }
}


int main () {
    // Array with random elements
    int l = 10;
    int arr[l], i;
    srand(time(NULL));
    for(i=0;i<10;i++){
        arr[i]=rand();
    }

    // Test print function
    printArr(arr, l);

    // Test average function
    printf("Average: %f\n", avgArr(arr,l));

    // Test copy function
    int arr2[l];
    copyArr(arr,arr2,l);
    printArr(arr, l);
    printArr(arr2, l);

    return 0;
}
