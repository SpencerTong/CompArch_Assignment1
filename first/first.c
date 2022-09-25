#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

int main (int argc, char *argv[]){

    FILE * fpointer;
    fpointer = fopen(argv[1], "r");
    char nums[255];
    char *ptr;
    int trunc_prime;
    long num, lim, neg_check;
    int x = atoi(fgets(nums,255,fpointer));

    for (int i =0; i<x; i++)
    {
        num = strtol(fgets(nums,255,fpointer),&ptr,10); //reads in number
        neg_check = num;
        trunc_prime = 1;
        while(floor(num)>2&&trunc_prime==1){

          lim =  floor(sqrt(num));
          for (int j=2; j<=lim; j++)
          {
            if (num%j==0)
          {
            trunc_prime = 0;
            break;
          } 
          }
          num/=10;
        }
          if (trunc_prime==1&&neg_check>2){
            printf("yes\n");
        } else {
            printf("no\n");
        }
      }
    




    fclose(fpointer);
    

    return 0; //how operating system knows program successfully executed

}
