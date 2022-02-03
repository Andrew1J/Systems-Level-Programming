#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "stuystudent.h"

int main() {
    int i,j,n=5;
    srand(time(NULL));
    struct stuystudent *linked_list = 0;
    for(i=0;i<n;i++){
        char name[5];
        for(int j=0;j<4;j++){
            name[j] = rand()%10 + 48;
        }
        int hours_asleep = rand()%6+1;
        linked_list = insert_front(linked_list,name,hours_asleep);
    }
    printf("Linked List:\n");
    print_list(linked_list);
    printf("Removed Node List #1:\n");
    linked_list = remove_student(linked_list, 3);
    print_list(linked_list);
    printf("Removed Node List #2:\n");
    linked_list = remove_student(linked_list, 2);
    print_list(linked_list);
    printf("Printing Freed List:\n");
    linked_list = free_list(linked_list);
    print_list(linked_list);
    return 0;
}
