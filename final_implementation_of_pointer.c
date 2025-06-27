#include <stdio.h>
#include<string.h>

int count[10]={0,0,0,0,0,0,0,0,0,0};
int utilization[10]={123,123,123,123,123,123,123,123,123,123};
char memory[1];
char to_optimize_list[10][20]={"null","null","null","null","null","null","null","null","null","null"};
int inter_function_travel =0; //flag
/* the type of to_optimize_list
remains char,
but, it can be displayed via %d after performing tooptimize_l()  function */

// interpretation of data in below variable = 123 is null character.
// shoud be replaced back by 123 when not in use.

int to_optimize_list_int[10] ={123,123,123,123,123,123,123,123,123,123};
// capture index 0 to 9 for values, where utilization is
//   >= or  <= certain number

int opl[] = {0,0,0,0,0,0,0,0,0,0};
int oph[] = {0,0,0,0,0,0,0,0,0,0};
int cluster_coordinates[10][2] = {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
extern int addition_pointer=1; //point to start of raw memory



int memset1(int z,int number){
    printf(" initializing the memory");
    int i=addition_pointer;
    /*initializaing memory unit,
    placing nulls characters in memory units
    */
    memory[32]='\0';
    while (1){
         if (i == (addition_pointer - number)){
                break;
         }
         int uu=i-1;
         memory[uu] ='\0';
         printf("\n this is value of memory unit # %d --->>> >> %c %d %s",i-1,memory[i-1],memory[i-1],memory[i-1]);
         i--;
    }
    return 0;
}
void memorymap(){
    printf("inside memory map");
    int i=0;
    int counter=0;
    int flag=1;
    printf("\n");
    while (i< addition_pointer){
            if(i== addition_pointer-1){
                break;
            }

            if ((i)%8==0){
                counter++;
                flag=1;
                printf("\n");
            }
        if (flag==1){
            printf("memory ::  %2d  :: ",counter);
            }
        flag=0;
        printf("  %3d  ", memory[i]);
        i++;
    }
}
int memdeclaration(int n){
    char x[2];
    x[0] = 'a';
    x[1] = 'b';
    int y=0;
    while (count[y] !=0){
        y++;
    }
    count[y] = n;
    addition_pointer = addition_pointer + count[y];
    memory[addition_pointer] = 'a';
    memory[addition_pointer +1] = 'b';
    return y;

}

void memoryanalysis(){
    int i=9;
    int y=addition_pointer;
        i=9;
    while (1){
        while(i>=0){
            printf("\n \n entered loop..this is value of i now %d", i);
                if(count[i]==0){
                        if (i==0){
                             printf("\n No memory units found");
                            break;
                        }
                        else{
                            printf("\n analyzing memory unit number %d",i);
                        }
                        i--;
                        continue;
                }
            printf("\n analyzing memory unit number %d", i);
            int dumbvalue=count[i];
            int countnulls=0;
            while(dumbvalue>0){
                if (memory[y-1]=='\0'){
                    countnulls++;
                }
                dumbvalue--;
            }
            y=addition_pointer-count[i];
            utilization[i]=(100-(countnulls/count[i])*100);
            printf("\n **COUNTNULLS VALUE FOR MEM UNIT %d is %d  .. utilization is %d",i,countnulls, utilization[i]);
            i--;
    }
    break;
    }
    printf("\n \n analysis completed");

}
/*
function to optimize memory units with specific utilization number
passed an int as parameter to function
returns list of memory units to be optimized*/

int tooptimize_l(int n){
    int i=0;
    int count1=0;
    while(1){
        if (utilization[i] <=n){
            to_optimize_list_int[count1]=i;
            //that means to_optimize_list_int captures
            //only index values

            count1++;
        }
        if(i==9){
            break;
        }
        i++;
    }

    return (0);
}
/*on returning end, shunt off 123 from list*/

int checkeligibility(int x,int y, int z){
    int mid_point_of_mem = count[z]/2;
    int mid_value_of_cluster= (x-y)/2;
    int mid_point_of_cluster = x-mid_value_of_cluster;
    printf("\n these are values passed %d %d %d %d %d", x,y,z, mid_point_of_mem,mid_point_of_cluster);
    if(mid_point_of_cluster >= mid_point_of_mem){
        printf("\n found eligibility");
        return 0;}
    else{
        printf("\n found non eligibility");
        return 1;
    }
}

int find_biggest_cluster(int n){
    printf("I am in biggest cluster with val n %d", n);
    /*should fulfill the criteria that cluster
    is on right side of direction of entry of data
    into the memory units
    ..
    also, the cluster should atleast form 80%
    of entier countnulls
    */

    /*find last filled count index */
    int y=1; // <----- starting pointer;;
    /*fin the summation to subtract from addition_pointer pointer
    in ordcer to find the place of first and last occurance unit
    of n memory unit in memory map */
    int count_count;
    for(count_count =0;count_count <=n;count_count++){
        y = y+count[count_count];
    }

    int pointer;
    int place_of_first_occurance;
    int size_of_cluster;

    pointer = y-1;
    place_of_first_occurance=y-count[n]; //points to place of first data unit of the memory unit
    size_of_cluster =  (((100-utilization[n])/100)*count[n]);
    size_of_cluster = (size_of_cluster*80)/100;
    printf("|...\n|...\n|...\n|...\n ******** \n these are values place of first occurance %d y pointer %d  pointer %d \n *****|\n|\n|\n",place_of_first_occurance,y,pointer);
    printf("\n\|\n|  values of count %d %d %d %d %d %d %d.. \n",count[0],count[1],count[2],count[3],count[4],count[5],count[6]);

    while(1){
        if(pointer == place_of_first_occurance){
            break;
        }
        int summation1=0;
        if((memory[pointer] == '\0') && (pointer == place_of_first_occurance)){
            printf("\n No cluster found !!");
            goto bosch;
        }
        else if((memory[pointer] == '\0') && (pointer > place_of_first_occurance)){
                summation1++;  //basically a count
                int start=pointer;
                printf("\n this is value of start %d and pointer %d", start,pointer);
                int eligible=1;
                while(1){
                    if(summation1==size_of_cluster){
                        printf("\n this is value of n %d",n);
                        printf("\n \n ** Yaay !! cluster found with end coordinates:: %d  %d",start,pointer);
                        eligible=checkeligibility(start,pointer,n);
                        //checkeligibility() should set set flag
                       // the flag to 0 after success

                       if (eligible ==1){
                            goto bosch;
                        }
                        cluster_coordinates[n][0] = start;
                        cluster_coordinates[n][1] = pointer;
                        printf("\n cluster_coordinates updated %d %d", cluster_coordinates[n][0],cluster_coordinates[n][1]);
                        goto end;
                    }
                    else if(memory[pointer] == '\0' && pointer > place_of_first_occurance){
                            summation1++;
                            pointer--;
                    }
                    else {
                        break;}
                    }
                }
        else{
            pointer--;
        }

    }
    end:
        return 0;
    bosch:
        return 1;
}

// expanding the left end coordinates of the cluster

int expand_coordinates(int nx,int n){
    //finding left-end coordinates of cluster
    //and expanding it
    int i = cluster_coordinates[n][1]-1;
    int left_end= nx-count[n]+1;
    int count=0;
    while(i>=left_end){
        if (memory[i] == '\0'){
                i--;
                count++;
        }
        else{
            break;
        }
    }
    cluster_coordinates[n][1]=cluster_coordinates[n][1]-count;
}

int move_left(int pointer,int left_end, int *abc){
    *abc=0;
    *(abc+1)=0;
    *(abc+2)=0;
    *(abc+3)=0;
    *(abc+4)=0;
    *(abc+5)=0;
    *(abc+6)=0;
    *(abc+7)=0;
    *(abc+8)=0;
    *(abc+9)=0;
    *(abc+10)=0;
    *(abc+11)=0;
    int count_left_10=0;
    int count_left_10_coor[5]={0,0,0,0,0};
    while((pointer -4)>=left_end){
        if (memory[pointer]=='\0' && memory[pointer-1]=='\0' && memory[pointer-2]=='\0'&& memory[pointer-3]=='\0'&& memory[pointer-4] =='\0'){
            *(abc+ 1+ *abc)=pointer;
            *abc++;
            pointer=pointer-5;
        }
        else{
            pointer=pointer-5;
        }

    }
    int i=0;
    while(*(abc+1+i) != 0 && *(abc+2+i) != 0 && (i+1)<=4){
        if (( *(abc+1+i)- *(abc+2+i) ) ==5){
            *(abc+ 7+ *(abc+6)) = *(abc+1+i);
            *(abc+6) = *(abc+6) + 1;
        }
            i++;
    }
    return 0;
}


int move_right(int pointer,int right_end, int *abc){
    *abc=0;
    *(abc+1)=0;
    *(abc+2)=0;
    *(abc+3)=0;
    *(abc+4)=0;
    *(abc+5)=0;
    *(abc+6)=0;
    *(abc+7)=0;
    *(abc+8)=0;
    *(abc+9)=0;
    *(abc+10)=0;
    *(abc+11)=0;
    while((pointer +4)<=right_end){
        if (memory[pointer]=='\0' && memory[pointer+1]=='\0' && memory[pointer+2]=='\0'&& memory[pointer+3]=='\0'&& memory[pointer+4] =='\0'){
            *(abc +1 + *abc) = pointer +4; //count_right_5_coor[count_right_5] =pointer +4; // moving pointer to right side, +4
            *(abc)++; //count_right_5++;
            pointer=pointer + 5;
        }
        else{
            pointer=pointer+5;
        }
    }
    int i=0;
    while(*(abc +1 +i) != 0 && *(abc +2 +i)!=0 && i+1 <=4){
            if ((*(abc+2+i) - *(abc+1+i))==5 ){// count_right_5_coor[i+1] - count_right_5_coor[i]) == 5){
                *(abc+7+ *(abc+6) ) = *(abc+2+i);//count_right_10_coor[count_right_10] = count_right_5_coor[i+1];
                *(abc+6) = *(abc+6) +1;
        }
        i++;
    }
    return 0;
}


// FSNBIMU stands for find small null blocks in  in memory units // find space blocks of 1
int fsnbimu(int n, int *ptr1, int *ptr2,int *extra_ptr){
    printf("\n \n \n *** entering function fsnbimu \n\n\n");
    while (1){
        int nx = addition_pointer;
        int i=9;
        int summation=0;
        while(1){
                if(count[i] == 0){
                    i--;
                }
                else{
                    break;
                }
        }
        while(i>n){
                summation=summation+count[i];
                i --;
        }
        nx = nx - summation -1;
        int boundary_r = nx;
        int boundary_l = nx - count[n]+1;     // extra_ptr  extra_ptr+4
        *extra_ptr = boundary_r;   //         |-----------||---------||
        *(extra_ptr+1)=boundary_l;  //        |boundary   ||boundary ||
                                    //        |___ right__||_left____||

        printf("this is value n %d boundary_l %d boundary_r %d", n,boundary_l, boundary_r);

        // Now, nx is pointing to last bit of the memory unit //Reverse diredtion

        //from here we will start reading in reverse direction

        // all memory unit pointers are counted starting reverse direction from
        // 100 to 0
        i=10;  // this is mode.. Mode : 10  Mode 5

        expand_coordinates(nx,n);
        int pointer=cluster_coordinates[n][1];
        int left_end = boundary_l;
        int right_end = boundary_r;
        int aa,bb;
        while(cluster_coordinates[n][1] >=left_end || cluster_coordinates[n][0]<= right_end){
                aa=move_left(cluster_coordinates[n][1],left_end,ptr1);
                bb=move_right(cluster_coordinates[n][0],right_end,ptr2);
                break;
        }
        printf("this is value n %d boundary_l %d boundary_r %d", n,boundary_l, boundary_r);
        printf("\n \n \n *** leaving function fsnbimu \n\n\n");
        return 0;
        // format of result_l or result_r = {variable,pointer,variable,pointer}
    }

    /*
    int  1 byte
    character 1byte
    -43489384577
    space characters
    */

}

void register1 (int pointer, int pos, char *char_f,int *c_count, char *c_p_next){
    printf("\n \n \n *** entering function register1 \n\n\n");
    printf("this is value of pointer %d", pointer);
    printf("\n this is value of pos %d", pos);
    int char_val=memory[pointer];
    char_val=char_val-32;  // like space == charval = 0;
    *(c_count + char_val) = *(c_count+char_val) + 1;
    *(char_f + char_val) = '1';
    if (*(char_f+ char_val) =='1'){
        goto skip;
    }

    char *tmp_ptr;
    tmp_ptr = &pos;
    *(c_p_next + 12*(char_val) )= *tmp_ptr;
    *(c_p_next + 12*(char_val) + 1)= *(tmp_ptr+1);
    *(c_p_next + 12*(char_val) + 2)= *(tmp_ptr+2);
    *(c_p_next + 12*(char_val) + 3)= *(tmp_ptr+3);

    // nullifying the memory unit /  now.......
    // nullifying .....
    memory[pointer] = '\0';
    goto last;


    skip:;
        char *array1;
        array1=malloc(12);
        memset(array1,0,12);
        memset(array1,pos,4);
        char **random_ptr, *c;

        random_ptr= c_p_next + 12*(char_val) +4;
        c = random_ptr;

        while (1){
            if (*c == NULL){
            random_ptr = array1+4;
            c = random_ptr;
            break;
            }
            random_ptr=*random_ptr;
            c = random_ptr;
    }
    last:;
        printf("\n \n \n *** leaving function register1 \n\n\n");
        printf("printing nothing here");

    }



int compress(int n, int *ptr1,int *ptr2, int *extra_ptr,char *c_ptr_f, int *c_count, char *c_p_next){

 printf("\n \n \n *** entering function compress \n\n\n");
 int boundary_r;
 int boundary_l;
 boundary_r =*(extra_ptr);
 boundary_l = *(extra_ptr+1);
printf(" *** entering function compress ");
 int pointer;
 pointer = boundary_r;
 int how_many=126-32;
  // creating a data  structure here for registering characters

 int i;
 here:

 while(pointer >= boundary_l && memory[pointer] != '\0'){
        //just outsourcing functionlality to other function.. that's it !
        // that's it....
        int position=boundary_r-pointer+1;
        printf("\nthis is value of pointer %d", pointer);
        register1(pointer,position,c_ptr_f,c_count,c_p_next);
        pointer--;
 }

    if (pointer==boundary_l){
            goto end;
        }
    if(pointer == cluster_coordinates[n][0]){

            pointer=cluster_coordinates[n][1];
            goto here;
        }
    else if(pointer == *(ptr2+7) || *(ptr2+7+1) || *(ptr2+7+2) || *(ptr2+7+3) ||*(ptr2+7+4)  ){
            pointer=pointer-9;

            goto here;
    }
    else if(pointer == *(ptr2+1) || *(ptr2+2) || *(ptr2+3) || *(ptr2+4) ||*(ptr2+5)   ){
            pointer=pointer-4;

            goto here;
    }
    else if(pointer == *(ptr1+7) || *(ptr1+7+1) || *(ptr1+7+2) || *(ptr1+7+3) ||*(ptr1+7+4)  ){

            pointer=pointer-9;

            goto here;
    }
    else if(pointer == *(ptr1+1) || *(ptr1+2) || *(ptr1+3) || *(ptr1+4) ||*(ptr1+5)   ){
            pointer=pointer-4;

            goto here;
    }
    else {
        pointer--;
        goto here;
    }
    end:;
    printf("\n \n \n *** leaving function compress \n\n\n");
    return 0;

}
int optimize_l(int n,int code, char **malloc_ptr, int *my_count){
    printf("\n \n \n *** entering function optimize_l \n\n\n");

    // cod 0 stands for a list
    // code 1 stands for single entry
    printf("\n\n\n\n\n***ENTERED OPTIMIZE L\n\n\n\n\n\n");
    printf("\n these are values of n and code %d %d", n,code);

         char characters[126-32];
         char characters_flag[126-32];
         int characters_count[126-32];
         char c_pos_next[126-32][12];
         char *c_ptr, *c_ptr_f;
         int *c_count;
         char *c_p_next;
         int i;

         c_ptr=&characters;
         c_ptr_f=&characters_flag;
         c_count=&characters_count;
         c_p_next=&c_pos_next;

         int count_for_n =0;

        // initializing the structure below ----->>>>>
         for (i=32; i<=126;i++){
                characters[i-32] = i;
                characters_flag[i-32] = '0';
                characters_count[i-32]= 0;
                int y;
                for (y=0;y<=12;y++){
                        c_pos_next[i-32][y]=0;
         }}

    if (code ==0){
        int i=0;
        while(to_optimize_list_int[i] != 123){  // **Limitation Here, the index of to_optimize_list_int has to be less than 123
            printf("*** ***** **** \n I am in loop at optimize, wiht i value %d\n**** ****  **** ",i);
            printf("*** ***** **** \n this is to_optimize_int %d %d %d %d %d ...\n**** ****  **** ",to_optimize_list_int[0],to_optimize_list_int[1],to_optimize_list_int[2],to_optimize_list_int[3],to_optimize_list_int[4]);

            count_for_n++;
            *my_count=count_for_n;

            if (count_for_n >=1){
                int iii;
                 for (iii=32; iii<=126;iii++){
                        characters[iii-32] = i;
                        characters_flag[iii-32] = '0';
                        characters_count[iii-32]= 0;
                        int y;
                        for (y=0;y<=12;y++){
                                c_pos_next[iii-32][y]=0;
                 }}}

            int z;
            int *result2;
            n = to_optimize_list_int[i];
            z =find_biggest_cluster(n);

            //provisioning ptr1;ptr2;extra ptr

            int result_l[12]={0,0,0,0,0,0,0,0,0,0,0,0};
            int result_r[12]={0,0,0,0,0,0,0,0,0,0,0,0};
            int *ptr1, *ptr2;
            ptr1=&result_l;
            ptr2=&result_r;
            int boundary[2] = {0,0};
            int *extra_ptr;
            extra_ptr=&boundary;
            int var_for_result;


            result2=fsnbimu(n,ptr1,ptr2,extra_ptr);
            var_for_result=compress(n,ptr1,ptr2,extra_ptr, c_ptr_f,c_count,c_p_next);

            i++;


            //done ! Now the malloc part !
            // malloc --> transferring all arrays to malloc defined
            // address
            //------------------//

            int i_126_32 = 126-32;
            char *map_in_memory;
            map_in_memory=malloc(i_126_32*2 + i_126_32*12 +i_126_32*4);

            // structure === char - char - int - char*12
            int cc =0;
            int ii;
            for (ii=32; ii<=126;ii++){

                memset(map_in_memory+cc,ii,1);
                memset(map_in_memory+cc+i_126_32,characters_flag[ii-32],1);
                memset(map_in_memory+(4*cc)+2*(i_126_32),characters_count[ii-32],4);
                int y=0;
                while(y<12){
                    memset(map_in_memory+2*(i_126_32)+4*(i_126_32)+12*cc +y,c_pos_next[ii-32][y],1);
                    y++;
                }
                cc++;
            }
                malloc_ptr = malloc_ptr +  count_for_n -1;
                *malloc_ptr=map_in_memory;

    }}
    else{

        int z;
        int *result2;
        z =find_biggest_cluster(n);

        int result_l[12]={0,0,0,0,0,0,0,0,0,0,0,0};
        int result_r[12]={0,0,0,0,0,0,0,0,0,0,0,0};
        int *ptr1, *ptr2;
        ptr1=&result_l;
        ptr2=&result_r;
        int boundary[2] = {0,0};
        int *extra_ptr;
        extra_ptr=&boundary;
        result2=fsnbimu(n,ptr1,ptr2,extra_ptr);
        int var_for_result;
        var_for_result= compress(n,ptr1,ptr2,extra_ptr, c_ptr_f,c_count,c_p_next);


        // malloc --> transferring all arrays to malloc defined
        // address

        int i_126_32 = 126-32;
        char *map_in_memory;
        map_in_memory=malloc(i_126_32*2 + i_126_32*12 +i_126_32*4);

        // structure === char - char - int - char*12
        int cc =0;
        for (i=32; i<=126;i++){

                memset(map_in_memory+cc,i,1);
                memset(map_in_memory+cc+i_126_32,characters_flag[i-32],1);
                memset(map_in_memory+(4*cc)+2*(i_126_32),characters_count[i-32],4);
                int y=0;
                while(y<12){
                    memset(map_in_memory+2*(i_126_32)+4*(i_126_32)+12*cc +y,c_pos_next[i-32][y],1);
                    y++;
                }
                cc++;
         }
         *malloc_ptr=map_in_memory;
         printf("\n \n \n *** leaving function optimize_l \n\n\n");
         printf("____***this is value of map_in_memory malloc :: %d ___***\n", map_in_memory);
         printf("____***this is value of malloc_ptr:: %d ___***\n", malloc_ptr);
         return 0;

         }

                // NOTE - extra ptr refers to exact boundaries
            // of the memory unit - the 1st and last unit address;


        // the value of *extra_ptr is being ful
        // filled by the fsnbimu function.


        /*  WIP need to extract the results from
         the resule here
         after receiving the coordinates, we need to
         send the coordinates to a function,
         so it can delete nulls one by one
         */

    printf("\n \n \n *** leaving function optimize_l \n\n\n");
    return 0;
}
int main(){
    memset(count,0,sizeof(count));
    memory[0] = '@';
    printf("\n___________\n___________\n");
    /*
    declaration part
    */
    int y=0;
    while (1){
            if (y==5){
                break;
            }
        int i;
        i = memdeclaration(100);
        /*
        memory implementation here
        allocating a big memory play area of size 100 bytes
        function to  initialize memory play ground;
        */
        int result = 1;
        result  = memset1(i,100);
        printf("\nthis is result %d", result);
        y++;
    }
    printf("\n \n\n\nprinting count now.....\n\n\n\n");
    memorymap();
    memoryanalysis();

    /*lets find memory units with 20% and
    lesser utilization
    for this we need to initialize a list of 10 charactsrs*/
    int *listyy;

    listyy = tooptimize_l(20);
    /*
    Now.. listyy needs to be interpreted.. 0 value acts as null value... and 0
    */

    // to optimize memory units with low utilization, 20% and lower
    //tooptimize_h(80);  // to optiize memory units with high utilization, 80% and higher
    int result1;
    printf("\n this is address of to_optimize_list_int %d \n", to_optimize_list_int);
    int number_1=(sizeof(to_optimize_list_int)/4);
    char *result_ptr[number_1];
    result_ptr[0]=&result_ptr;
    int my_count=0;
    int code =0;
    if (code ==1){
      result1=optimize_l(2,1,result_ptr[0],&my_count);
    }
    else if (code==0){

            // 1st argument below can
            // be anything.. .anything.. .13,4,4,5,6,7,... so on..
        result1=optimize_l(0,0,result_ptr,&my_count);
    }


    printf("\n \n \n ***** returned from optimize_l");
    printf("\n\n\ all done ! \n\n\n");
    printf("Now. let's look at malloc structure\n");
    int random_num = 126-32+1;
    int calculated_num=random_num*2 +random_num*4 +random_num*12;
    int yallow;
    int count_for_group_8=0;
    printf("\n\n\n__**this is value of result ptr in main() :: %d __**\n\n\n\n",result_ptr[0]);
    if (code==1){
            for(yallow=1;yallow<=calculated_num;++yallow){
            if(count_for_group_8%8==0){
                printf("\n");
            }
            printf("  %c ",*(result_ptr[0]+ yallow-1));
            count_for_group_8++;
    }}
    else if (code==0){
            int count_4=0;
            int *rand_ptrr;
            rand_ptrr=result_ptr[count_4];
            //printf("these are values of result_ptr %d %d %d %d %d %d",result_ptr[0],result_ptr[1],result_ptr[2],result_ptr[3],result_ptr[4],result_ptr[5]);

            while(*rand_ptrr != NULL){
                    printf("this is  val of count_5 %d", count_4);
                count_for_group_8=0;
                for(yallow=1;yallow<=calculated_num;++yallow){
                if(count_for_group_8%8==0){
                    printf("\n");
                }
                printf("  %c ",*(result_ptr[count_4]+ yallow-1));
                count_for_group_8++;
                }
            printf("\n______________ _______________\n");
            count_4++;
            rand_ptrr=result_ptr[count_4];
    }}
    return 0;
        }

    //code above represents == 0= list ; 1=single int (index memory unit)

    //feed it the memory unit // pass memory unit number as parameter
    //optimize_h();
    /*

    */

    /*
    Operation on to_optimize_list_int
    */

// limitations
// the size of memory unit has to be small.. also, while
//optimizing the memory unit on right and left side, the
//system will not be able to handle capture more than 5 blocks
//of 5x 5-unit nulls and 5x 10-unit nulls

//this can be corrected in move_left and move_right section;
//has limitation that only 5 units of 5 nulls can be recorded
