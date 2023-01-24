#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // as we are using boolean data type.
#include <math.h> // for sqrt

#define COLUMNS 6
int numInCol = 0; // to fix the side effect 

void print_number(int n){
  if (numInCol < COLUMNS )
  {
    printf("%10d ", n);
    numInCol++; 
  }
  else
  {
    printf("\n");
    numInCol = 0; 
  }
}

void print_sieves (int n){
    bool *bool_arr;              //the algorithm Sieve of Eratosthenes
    bool_arr = (bool *) malloc(sizeof(bool)*n); 
    for (int i = 1; i<=n; i++){
        bool_arr[i] = true; 
    }

    for (int i = 2; i<sqrt(n); i++){
        if (bool_arr[i]== true){
            for (int j = i*i; j<=n; j += i){
                bool_arr[j] = false; 
            }
        }
    }

    for(int i = 2; i<=n; i++)
    {
        if(bool_arr[i] == true){
            print_number(i); 
        }
    }

    free(bool_arr); 
    
}

int main(int argc, char *argv[]){
  if(argc == 2)
    print_sieves(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
}

