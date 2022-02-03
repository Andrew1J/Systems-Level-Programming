struct stuystudent {
    char name[20];
    int hours_asleep;
    struct stuystudent *next;
};

void print_student(struct stuystudent *s);

struct stuystudent * make_student(char *n, int h, struct stuystudent *st);

void print_list(struct stuystudent *s);

struct stuystudent * insert_front(struct stuystudent *s, char *n, int h);

struct stuystudent * free_list(struct stuystudent *s);

struct stuystudent * remove_student(struct stuystudent *front, int data);
