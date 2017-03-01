#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int main(int argc, char *argv[]){
  FILE *input = fopen(argv[1], "r");
  if(input == NULL){
    printf("Filenot found!\n");
  }

  int readn, count;
  int sum = 0;
  int max = INT_MIN;
  int min = INT_MAX;
  while(fscanf(input, "%d\n", &readn) != EOF){
    if(readn < min){
      min = readn;
    }
    if(readn > max){
      max = readn;
    }

    sum += readn;
    count++;
  }

  FILE *out = fopen("out1.txt", "w+");
  fprintf(out, "Hi i\'m %d and my parent is %d", getpid(), getppid());
  fprintf(out, "The sum is %d\n", sum);
  fprintf(out, "The min is %d\n", min);
  fprintf(out, "The max is %d\n", max);
}
