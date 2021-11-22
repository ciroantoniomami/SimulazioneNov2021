#include <stdio.h>
#include <stdlib.h>

int conta_elementi(int* A, int dim){
  int count_elem = 0;
  for(int i=0;i < dim; i++){
    int count = 0;
    for(int j=0; j < i; j++){
      if(A[j] < A[i]) count++;
    }
    if(count == A[i]){
      printf("%d\n", A[i]);
      count_elem++;
    }

  }
  return count_elem;
}


int main(int argc, char **argv) {

int A[7] = {1,2,1,3,6,4,14};
printf("%d\n", conta_elementi(A, 7));

  return 0;
}