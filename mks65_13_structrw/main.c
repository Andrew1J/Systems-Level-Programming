#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


struct pop_entry {
  int year;
  int population;
  char boro[15];
};

long long size_of_file(char *f) {
    struct stat stats;
    stat(f, &stats);
    return stats.st_size;
}

void read_csv(char *fin) {
    int err, file, i, filesize = size_of_file(fin);
    char data[filesize];

    // Open CSV file
    file = open(fin, O_RDONLY);
    if(file==-1){
        printf("Error:\n");
        printf("%s\n", strerror(errno));
        return;
    }

    // Read CSV file
    err = read(file, data, filesize);
    if(err==-1){
        printf("Error:\n");
        printf("%s\n", strerror(errno));
        return;
    }
    // Count Number of Lines
    int num_lines = 0;
    for(i=0;i<filesize+1;i++) {
        if (data[i]=='\n') num_lines++;
    }
    // Parse CSV Data
    int ind = 0, j;
    struct pop_entry entries[5*num_lines-5];
    char *boro[5] = {"Manhattan", "Brooklyn", "Queens", "Bronx", "Staten Island"};
    for(i=0;i<num_lines-1;i++){
        int line[6];
        while(data[ind]!='\n'){
            ind++;
        }
        ind++;
        sscanf(data+ind, "%d, %d, %d, %d, %d, %d\n", &line[0], &line[1], &line[2], &line[3], &line[4], &line[5]);
        for(j=1;j<6;j++){
            entries[5*i+j-1].year = line[0];
            strcpy(entries[(5*i)+j-1].boro, boro[j-1]);
            entries[(5*i)+j-1].population = line[j];
        }
    }

    // Open / Write To Out File
    int out = open("nyc_pop.data", O_CREAT | O_WRONLY, 0644);
    if(out==-1){
        printf("Error:\n");
        printf("%s\n", strerror(errno));
        return;
    }
    err = write(out, entries, sizeof(entries));
    if(out==-1){
        printf("Error:\n");
        printf("%s\n", strerror(errno));
        return;
    }
    printf("reading %s\n", fin);
    printf("wrote %lld bytes to %s\n",size_of_file("nyc_pop.data"), fin);
}

void read_data() {
    int filesize = size_of_file("nyc_pop.data");
    // Open Data File
    int file = open("nyc_pop.data", O_RDONLY);
    if(file==-1){
        printf("Error: \nData file doesn't exist, run -read_csv first.\n");
        return;
    }

    // Read Data File
    struct pop_entry *entries = malloc(file);
    int err = read(file, entries, filesize);
    if(err==-1){
        printf("Error:\n");
        printf("%s\n", strerror(errno));
        return;
    }

    // Print Data
    int i, num_entries = filesize / sizeof(struct pop_entry);
    for(i=0;i<num_entries;i++){
        printf("%d:\t year: %d\t boro: %s\t pop: %d\n", i, entries[i].year, entries[i].boro, entries[i].population);
    }
    free(entries);
}

void add_data() {
    struct pop_entry new;
    char input[100];

    // Command Line Input
    printf("Enter year boro pop:\n");
    fgets(input, sizeof(input), stdin);
    if(sscanf(input,"%d %1024[^0-9] %d", &new.year, new.boro, &new.population)!=3) {
        printf("Please enter it in correct format [int] [string] [int]\n");
        return;
    }

    // Open data file
    int file = open("nyc_pop.data", O_WRONLY | O_APPEND);
    if(file==-1){
        printf("Error: \nData file doesn't exist, run -read_csv first.\n");
        return;
    }

    // Write to data file
    int err = write(file, &new, sizeof(new));
    if(err==-1){
        printf("Error:\n");
        return;
    }
}

void update_data() {
    struct pop_entry new;
    int num_entries = size_of_file("nyc_pop.data") / sizeof(struct pop_entry);
    char input[100];
    read_data();

    // Command Line Input
    printf("Entry to update: ");
    int ind;
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &ind);
    if(ind>=num_entries || ind < 0){
        printf("Not a possible entry\n");
        return;
    }

    int year, pop;
    char *boro;
    printf("Enter year boro pop:\n");
    fgets(input, sizeof(input), stdin);
    if(sscanf(input,"%d %1024[^0-9] %d", &new.year, new.boro, &new.population)!=3) {
        printf("Please enter it in correct format [int] [string] [int]\n");
        return;
    }

    // Open data file
    int file = open("nyc_pop.data", O_RDWR);
    if(file==-1){
        printf("Error: \nData file doesn't exist, run -read_csv first.\n");
        return;
    }

    // Write to data file
    lseek(file, ind*sizeof(struct pop_entry), SEEK_SET);
    int err = write(file, &new, sizeof(new));
    if(err==-1){
        printf("Error:\n");
        return;
    }
    close(file);
}

int main(int argc, char *argv[]) {
    if (argv[1]==NULL) {
        printf("No commands given\n");
        return 0;
    } else if (strcmp(argv[1],"-read_csv")==0){
        read_csv("nyc_pop.csv");
    } else if (strcmp(argv[1],"-read_data")==0){
        read_data();
    } else if (strcmp(argv[1],"-add_data")==0){
        add_data();
    } else if (strcmp(argv[1],"-update_data")==0){
        update_data();
    } else {
        printf("Invalid command\n");
    }
    return 0;
}
