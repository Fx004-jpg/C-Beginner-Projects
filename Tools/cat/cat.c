#include <stdio.h>
#include <stdlib.h>

int main (){

  char file[200];

  printf("File: ");
  scanf("%s", file);

  FILE *fptr = fopen(file, "r");

  if (fptr == NULL){
    printf("Error: File could not be opend");
    return 1;
  }
  char buff[100];
  
  int line_number = 1;
  while(fgets(buff, sizeof(buff), fptr)){
    printf("%d: %s",line_number, buff);
    line_number++;
  }

  fclose(fptr);
  return 0;
}


