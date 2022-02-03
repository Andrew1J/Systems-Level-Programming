#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct stuystudent {
    char name[20];
    int hours_asleep;
    double gpa;
};

void print_student(struct stuystudent *s) {
    printf("Stuy student %s sleeps for %d hours and has a gpa of %lf\n", s->name, s->hours_asleep, s->gpa);
    return;
}

struct stuystudent * make_student(char *n, int h, double g) {
    struct stuystudent *s = malloc(sizeof(struct stuystudent));

    strcpy(s->name,n);
    s->hours_asleep = h;
    s->gpa = g;

    return s;
}

int main() {
    int i;
    srand(time(NULL));
    for(i=0;i<5;i++){
        char name[4] = {'B','o','b', (rand()%10)+'0'};
        int hours_asleep = rand() % 5;
        int gpa = 70 + (rand()%10);
        struct stuystudent *s = make_student(name,hours_asleep,gpa);
        print_student(s);
        free(s);
    }
    return 0;
}
