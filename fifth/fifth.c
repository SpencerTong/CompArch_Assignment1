#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int** createArray(int dim){
    int** arr = malloc(dim*sizeof(int*));
    for (int i = 0; i < dim; i++){
        arr[i] = malloc(dim * sizeof(int));
    }
    return arr;
}



void free_mem(int** arr, int x){
    for (int i = 0; i<x; i++){
        free(arr[i]);
    }
    free(arr);
}

int calc_det(int** arr, int dim, int sum, int start){
    if (dim==2){
        return arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0]; 
    } else {
        while(start<=dim){
            int curr_part = pow((-1), start-1)*arr[0][start-1]; 
            int **new_arr = createArray(dim-1);
            int row = 0;
            int column = 0;
            for (int i =1; i<dim; i++){
                for (int j = 0; j<dim; j++){
                    if(j!=start-1){
                        new_arr[row][column]=arr[i][j];
                        if(column==dim-2){
                            column=0;
                            row++;
                        } else {
                            column++;
                        }
                    }
                }
            } 
            
            curr_part= curr_part*calc_det(new_arr,dim-1,0,1);
            sum=sum+curr_part; 
            free_mem(new_arr, dim-1);
            start++;
        }
    }
    return sum;
   

}

int main(int argc, char *argv[])
{
    FILE *fpointer;
    fpointer = fopen(argv[1], "r");
    char nums[255];

    if (fpointer == NULL)
    {
        printf("error\n");
        return 1;
    }

    int x = atoi(fgets(nums,255,fpointer));
    int ** arr = createArray(x);
    for (int i = 0; i<x; i++){

        fgets(nums,255,fpointer);
		char *token = strtok(nums, "	");
		int j = 0;
		while(token!=NULL){
			arr[i][j] = atoi(token);
			j++;
			token=strtok(NULL, "	");
		}
    }
    
    int start = 1;
    int sum = 0;
    if (x==1){
        printf("%d\n", arr[0][0]);
        free_mem(arr, x);
        return 0;
    } else {
        sum = calc_det(arr, x, sum, start);
    }

printf("%d\n", sum);
free_mem(arr, x);

fclose(fpointer);
return 0;
}
