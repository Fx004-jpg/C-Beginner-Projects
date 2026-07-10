#include <stdio.h>
#include <string.h>

int check_password(char *input){
  return strcmp(input, "Apple") == 0;
}

int main(){
  
  char str[100]; 
  
  do {
    printf("password: ");
    scanf("%99s", str);

    if (check_password(str)){
      printf("Acces Granted!\n");
    }
  else {
      printf("Access denied!\n");
    }
  } while(!check_password(str)); 
}
