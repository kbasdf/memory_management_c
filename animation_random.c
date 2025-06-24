#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("\n\n\n\n\n\n\n\n\n\n");
    int count1=1;
    int zool=0;
    int distance=20;


    here:;
    int new_line=0;
    printf("count :::: %d",count1);
    printf("\n");
    new_line++;
    printf("\n");
    new_line++;
    printf("\n");  // <----- pointer is here
    new_line++;
    int count=200000000;

    if((count1%3)==0){
        printf("\033[A");
        new_line--;
        printf(" <3");
        printf("\n");
        new_line++;
        zool=1;
    }
    else if (zool==1){
            printf("\033[A");
            new_line--;
            printf("\r");
            printf("\033[A");
            new_line--;
            printf("\r");
         printf("\033[1;31m <3\033[0m");
        //printf(" <3");
        printf("\n");
        new_line++;
        printf("\n");
        new_line++;
        zool=0;


    }
    printf(" 0");
    int y=0;
    //distance
    while (y !=distance){
        printf(" ");
        y++;
    }
    y=0;
    //other figure
    printf(" 0");

    printf("\n");
    new_line++;
    if (count1%2==0){
        printf("/|\\_");

        //distance
        while (y !=distance-2){
            printf(" ");
            y++;
        }
        y=0;
        //other figure
        printf("/|\\ ");


        printf("\n");
        new_line++;
    }
    else{
        printf("/|\\ ");


        //distance
        while (y !=distance-2){
            printf(" ");
            y++;
        }
        y=0;
        //other figure
        printf("/|\\ ");


        printf("\n");
        new_line++;
    }
    printf(" |");

    //distance
        while (y !=distance){
            printf(" ");
            y++;
        }
        y=0;
        //other figure
        printf(" |");


    printf("\n");
    new_line++;
    printf("/ \\");

    while (y !=distance-1){
            printf(" ");
            y++;
        }
        y=0;
        //other figure
        printf("/ \\");

    // moving the cursor back to original position
    // -----
    while(count!=0){
        count--;
    }
    int ff=new_line;
    while(ff>0){
    printf("\033[A");
    ff--;
    }
    int i=0;
    while(i !=new_line){
        printf("     \n");
        i++;
    }

    //printf("\033[A");

    while(new_line !=0){
         printf("\033[A");
         new_line--;
    }
    printf("\r");
        //printf("\033[A");
    //printf("\033[A");

    count1++;
    goto here;
    return 0;
}

