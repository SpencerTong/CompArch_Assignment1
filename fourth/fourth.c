#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int *createArr(int t){
    int *rtn = malloc((t)*(t)*(sizeof(int)));
    return rtn;
};

int main(int argc, char *argv[])
{

    if (argv[1] == NULL)
    {
        printf("error\n");
        return 1;
    }

    int x = atoi(argv[1]);
    if (x%2==0){
        printf("error\n");
        return 0;
    }

    int *arr = createArr(x);

    for (int i=0; i<x; i++){
        for (int j=0; j<x; j++){
            *(arr+i*x+j)=0;
        }
    }

    int mid = x/2;
    int row = 0;
    int col = mid;

    *(arr+mid) = 1;

    for (int i = 2; i<=x*x; i++)
    {
        int new_row = row;
        int new_col = col;
        if(new_row==0){
            new_row=x-1;
        } else {
            new_row--;
        }
        if (new_col==x-1){
            new_col=0;
        } else {
            new_col++;
        }

        int place = new_row*x + new_col;

        if (*(arr+place)!=0){ //issue, what is C pointer initialized to? 
            if (row==x-1){
                row=0;
            } else {
                row++;
            }
        place = row*(x)+col; 

        *(arr+place) = i;
 
        } else {
            *(arr+place) = i;
            row = new_row;
            col = new_col;
        }

    }
 


    for (int i=0; i<x; i++){
        for (int j=0; j<x; j++){
            printf("%d	", *(arr+i*x+j));
        }
        printf("\n");
    }

    free(arr);

    return 0;
}
