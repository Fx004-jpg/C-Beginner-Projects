#include <stdio.h>
#include <string.h>

#define RED "\e[0;31m"
#define BRED "\e[1;31m"
#define reset "\e[0m"

int main(){
  char file[250];
  char word[50];

  printf("File: ");
  scanf("%s", file);
  printf("Word: ");
  scanf("%s", word);

  
  FILE *fptr = fopen(file, "r");
  
  if(fptr == NULL){
    printf("Error: File not found or could not be opend!\n");
    return 1;
  }

  char buff[100];
  char *ptr;
  int counter = 0;
  int lenghtOfWord = strlen(word);

  while(fgets(buff, sizeof(buff), fptr)){
    ptr = strstr(buff, word);
    if (ptr != NULL){
      counter++;
      printf("-> %.*s", (ptr - buff), buff);
      printf(BRED "%.*s" reset, (int)lenghtOfWord, ptr);
      printf("%s\n", ptr + lenghtOfWord);
    }
  }
  printf("[Counter]: %d", counter);

  fclose(fptr);
  return 0;

}
