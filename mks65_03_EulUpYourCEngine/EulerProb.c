#include <stdio.h>

int prob1 () {
    int val=0, cnt;
    for(cnt=0;cnt<1000;cnt++){
        if(cnt%3==0||cnt%5==0){
            val += cnt;
        }
    }
    return val;
}

int prob5() {
    int cnt;
    for(int cnt=20;cnt<1e9;cnt+=20){
        int x=1;
        for(int i=2;i<=20;i++) {
            if(cnt%i!=0){
                x=0;
            }
        }
        if(x){
            return cnt;
        }
    }
    return 0;
}

int prob6() {
    int n = 1000;
    int sqsum = n*n*(n+1)*(n+1) / 4;
    int sumsq = n*(n+1)*(2*n+1)/6;
    if(sqsum>sumsq){
        return sqsum - sumsq;
    } else {
        return sumsq - sqsum;
    }
}

int main() {
    printf("Problem 1: %d\n", prob1());
    printf("Problem 5: %d\n", prob5());
    printf("Problem 6: %d\n", prob6());
}
