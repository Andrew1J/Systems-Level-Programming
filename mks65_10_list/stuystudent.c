#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct stuystudent {
    char name[20];
    int hours_asleep;
    struct stuystudent *next;
};

void print_student(struct stuystudent *s) {
    printf("Stuy student %s sleeps for %d hours.\n", s->name, s->hours_asleep);
}

struct stuystudent * make_student(char *n, int h, struct stuystudent *st) {
    struct stuystudent *s = malloc(sizeof(struct stuystudent));

    strcpy(s->name,n);
    s->hours_asleep = h;
    s->next = st;

    return s;
}

void print_list(struct stuystudent *s) {
    while(s) {
        print_student(s);
        s = s->next;
    }
}

struct stuystudent * insert_front(struct stuystudent *s, char *n, int h) {
    struct stuystudent *front = make_student(n,h,s);
    return front;
}

struct stuystudent * free_list(struct stuystudent *s) {
    struct stuystudent *temp;
    while (s) {
        temp = s->next;
        free(s);
        s = temp;
    }
    return temp;
}

struct stuystudent * remove_student(struct stuystudent *front, int data) {
    struct stuystudent *temp, *beg=front;
    if (front->hours_asleep==data) beg = front->next;
    while(front!=NULL && front->hours_asleep != data) {
        temp = front;
        front = front->next;
    }
    if(front!=NULL){
        temp->next = front->next;
        free(front);
    }
    return beg;
}
