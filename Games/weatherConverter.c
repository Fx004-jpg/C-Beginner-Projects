#include <stdio.h>

float celToFahr(float a){
  return a * 9.0 / 5.0 + 32;
}

float fahrToCel(float a){
  return (a - 32) * 5 / 9.0;
}

int main(){

  int choice;
  float result, number;

  do {
    
    printf("1 - Celsius: \n2 - Fahrenheit: \n3 - Quit: \n");
    printf("> ");
    scanf("%d", &choice);
    
    if(choice == 1){
      printf("Value: ");
      scanf("%f", &number);
      result = celToFahr(number);
      printf("\nCell -> Fahrenheit: %.2f\n", result);
    }
    else if(choice == 2){
      printf("Value: ");
      scanf("%f", &number);
      result = fahrToCel(number);
      printf("\nFahr -> Celsius: %.2f\n", result);
    }
    else if (choice != 3){
      printf("Invalid input\n");
    }
  } while(choice != 3);
  printf("\nThank you :) \n");
 return 0;
}


