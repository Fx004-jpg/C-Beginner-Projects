#include <stdio.h>
#include <string.h>

int checkPassword(char *input) {
  char password[] = "1234";
  return (strcmp(input, password) == 0);
}

int main(){
  char input[50];

  printf("Enter password: ");
  scanf("%s", input);
  
  if (checkPassword(input)) {
    printf("Access Granted\n");
  }
  else {
    printf("Acces denied!\n");
  }
  return 0;
}
