#include <stdio.h>
#include <string.h>
#include <string.h>

void printMenu(){
  printf("--- Hangman ---\n");
}

int main(){
  char word[10] = "Computer";
  char guess;
  char guessedLetters[100];

  int guessCount = 0;
  int wordLength = strlen(word);
  int gameWon = 0;

  printMenu();
  do{
    
    gameWon = 1;

    printf("Guess: ");
    scanf(" %c", &guess);
    guessedLetters[guessCount] = guess;
    guessCount++;

    for(int i = 0; i < wordLength;i++){

      int found = 0;

      for(int j = 0; j< guessCount; j++){
        if(word[i] == guessedLetters[j]){
          found = 1;
        }
      }
      if (found == 1){
        printf(" %c", word[i]);
      }
      else{
        printf("_ ");
        gameWon = 0;
      }
    }
    printf("\n");
    if (gameWon == 1){
      printf("You Won!\n");
    }
  }while(gameWon == 0);

  return 0;
}

