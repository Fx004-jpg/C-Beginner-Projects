#include <stdio.h>

void encrypt(char text[], int shift)
{
  shift %= 26;

  for(int i = 0; text[i] != '\0'; i++){
    if(text[i] >= 'A' && text[i] <= 'Z'){
      text[i] += shift;

      if(text[i] > 'Z'){
        text[i] -= 26;
      }
    }
    else if (text[i] >= 'a' && text[i] <= 'z'){
      text[i] += shift;

      if(text[i] > 'z'){
        text[i] -= 26;
      }
    }
  }
  printf("Encrypted: %s\n", text);

}

void decrypt(char text[], int shift)
{
  shift %= 26;

  for(int i = 0; text[i] != '\0'; i++){
    if(text[i] >= 'A' && text[i] <= 'Z'){
      text[i] -= shift;

      if(text[i] < 'A'){
        text[i] += 26;
      }
    }
    
    if(text[i] >= 'a' && text[i] <= 'z'){
      text[i] -= shift;

      if(text[i] < 'a'){
        text[i] += 26;
      }
    }
  }
  printf("Decrypt: %s\n", text);

}
  
int main()
{
  char message[100];
  int shift, choice;

  do
  {
    printf("1 - Encrypt \n2 - Decrypt\n3 - Quit\n\n> ");
    scanf("%d", &choice);
    
    switch(choice){
      case 1:
        getchar();

        printf("Message: ");
        fgets(message, sizeof(message), stdin);
        
        printf("Shift: ");
        scanf("%d", &shift);

        encrypt(message, shift);
        break;
      
      case 2:
        getchar();

        printf("Message: ");
        fgets(message, sizeof(message), stdin);

        printf("Shift: ");
        scanf("%d", &shift);

        decrypt(message, shift);
        break;

      case 3:
        printf("Goodbye!\n");
        break;

      default:
        printf("Invalid choice.\n");
        break;
    }

  }while (choice != 3);
  return 0;

}
