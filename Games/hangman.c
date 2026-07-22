#include <stdio.h>
#include <string.h>
#include <ctype.h>

void printMenu(){
  printf("--- Hangman ---\n");
}

int main(){
  char word[10] = "computer";
  char guess;
  guess = tolower(guess);
  char guessedLetters[100];

  int guessCount = 0;
  int wordLength = strlen(word);
  int gameWon = 0;
  int lives = 10;

  printMenu();
  do{
    gameWon = 1;
    
    printf("\nLives: %d\n", lives);

    printf("Guess: ");
    scanf(" %c", &guess);
    
    int correctGuess = 0;

    for(int i=0; i < wordLength; i++){
      if(word[i] == guess){
        correctGuess = 1;
        break;
      }
    }
    if(!correctGuess){
      lives--;
      printf("Wrong guess! Lives left: %d\n", lives);

    }

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
  }while(gameWon == 0 && lives > 0);
  if(lives == 0){
    printf("You lost!\nThe word was: %s\n", word);
  }

  return 0;
}

