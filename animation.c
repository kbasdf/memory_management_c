#include <stdio.h>

int main(){

printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
printf("");
    int count=0;

    while(1){
    //("count :: %d\n", count);
    int count_1=4000;
    printf("  <3\n");
    printf(" 0 ");
    printf("\n");
    if (count>=1){
        printf("/|\\_");
        printf("\n");
    }
    else{
        printf("/|\\ ");
        printf("\n");
    }
    printf(" |");
    printf("\n");
    printf("/ \\");

    count++;
    if (count==2){
            count=0;}

    printf("\n");
    while(count_1 >0){
        count_1--;
        printf("****");
        printf("\b\b\b\b");

    }
    printf("\033[A");
    //printf("\b\b\b");
    printf("\033[A");
    printf("\033[A");
    printf("\033[A");
    printf("\033[A");
    }

return 0;}
