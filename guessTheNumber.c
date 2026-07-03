#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void printMenu( int *guess){
 
  printf("Guess: ");
  scanf("%d", guess);
}
void printWinScreen(int counter){
  printf("Congrats, you won!\n");
  printf("You took: %d tries\n", counter);
}

int main(void){
  srand(time(NULL));
  int guess, randomNumber, counter = 0;
  
  randomNumber = rand() % 10 +1;

  do{
  printMenu(&guess);
  counter += 1;
  printf("%d\n", randomNumber);

  if (guess > randomNumber){
      printf("Too high!\n");
    }
  else if (guess < randomNumber){
      printf("Too low!\n");
    }

  }while (guess != randomNumber);
  printWinScreen(counter);
  return 0;
}
