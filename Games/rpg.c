#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
  char name[30];
  int price;

  int heal;
  int damage;
  int xp;
} Item;

Item items[] = {
  {"Health-Potion", 15, 20, 0, 0},
  {"Iron-Sword", 50, 0, 5, 0},
  {"Rune", 30, 0, 0, 50},
};

typedef struct{
  char name[30];
  int lvl;
  int hp;
  int damage;
  int gold;
  int xp;

  Item inventory[10];
  int inventoryCount;
} Player;

typedef struct{
  char name[30];

  int hp;
  int damage;
  int xp;
  int gold;
} Enemy;

Enemy enemies[] ={
  {"Goblin", 20, 5, 5, 2},
  {"Spider", 25, 8, 10, 4},
  {"Skelet", 12, 10, 2, 10},
};

void printMenu(void){
  printf("=====================\n");
  printf("=   D U N G E O N   =\n");
  printf("=====================\n"); 
}

void waitForEnter(void){
  printf("\nPress ENTER to continue...");
  while(getchar() != '\n');
  getchar();
}

void printInventory(Player *player){
  int choice = 0;
  printf("+-----------+\n");
  printf("| INVENTORY |\n", player->gold);
  printf("------------+\n");
  
  for(int i = 0; i < player->inventoryCount; i++){
    printf("%d. %s\n", i + 1, player->inventory[i].name);
  }
  
  printf("> ");
  scanf("%d", &choice);
  
  if(choice < 1 || choice > player->inventoryCount){
    printf("Invalid input!\n");
    return;
  }

  Item *item = &player->inventory[choice - 1];

  if (item->heal > 0) {
    player->hp += item->heal;
    printf("You used %s\n", item->name);
  }

  if (item->damage > 0) {
    player->damage += item->damage;
    printf("You used %s\n", item->name);
  }

  if (item->xp > 0) {
    player->xp += item->xp;
    printf("You used %s\n", item->name);
  }
  for(int i = choice - 1; i < player->inventoryCount - 1; i++){
    player->inventory[i] = player->inventory[i + 1];
  }
  player->inventoryCount--;

  waitForEnter();
}

void printShop(Player *player){
  
  int choice = 0;

  Item potion = items[0];
  Item sword = items[1];
  Item rune = items[2];

  printf("+------------------------+\n");
  printf("| CURRENT GOLD: %-8d |\n", player->gold);
  printf("+------------------------+\n");
  printf("| 1 - %-13s: %1dG |\n",potion.name, potion.price);
  printf("| 2 - %-13s: %1dG |\n",sword.name, sword.price ); 
  printf("| 3 - %-13s: %1dG |\n",rune.name, rune.price );
  printf("| 4 - EXIT               |\n");
  printf("+------------------------+\n");

  printf("\n> ");
  scanf("%d", &choice);
  
  switch(choice){
    case 1:
      if(player->gold >= potion.price){
        player->gold -= potion.price;
        printf("You bought a health potion!\n");
        player->inventory[player->inventoryCount] = potion;
        player->inventoryCount++;
      }else{
        printf("You don't have enough gold!\n");
      }
      break;
    
    case 2:
      if(player->gold >= sword.price){
       player->gold -= sword.price;
        printf("You bought the sword!\n");
        player->inventory[player->inventoryCount] = sword;
        player->inventoryCount++;
      }else{
        printf("You don't have enough gold!\n");
      }
      break;

    case 3:
      if(player->gold >= rune.price){
       player->gold -= rune.price;
       printf("You bought the sword!\n");
       player->inventory[player->inventoryCount] = rune;
       player->inventoryCount++;
      }else{
        printf("You don't have enough gold!\n");
      }
      break;

    case 4:
      break;

    default:
      printf("Invalid choice!");
      break;
  }
  waitForEnter();
}

void playerStats(Player *player){
printf("+----------------------------+\n");
printf("| Hero: %-20s |\n", player->name);
printf("| LVL:  %-20d |\n", player->lvl);
printf("| HP:   %-20d |\n", player->hp);
printf("| DMG:  %-20d |\n", player->damage); 
printf("| XP:   %-20d |\n", player->xp);
printf("| GOLD: %-20d |\n", player->gold);
printf("+----------------------------+\n");
  waitForEnter();
}

void fightMonster(Player *player, Enemy *enemy){
  int choice;

  printf("A %s appeared!\n", enemy->name);

  while(player->hp > 0 && enemy->hp > 0){
    printf("\n1. Attack\n2. Run\n\n");
    printf("> ");
    scanf("%d", &choice);

    switch(choice){
      case 1:
        printf("\n-> You attack the %s", enemy->name);
        enemy->hp -= player->damage;
        
        printf("- %s HP: %d\n", enemy->name, enemy->hp);
        
        printf("-> %s attacks back!\n", enemy->name);
        printf("-> You took %d damage!\n", enemy->damage);
        player->hp -= enemy->damage;

        break;
      
      case 2:
      printf("-> You run!\n");
      return;
    }
  }
  if(enemy->hp <= 0){
    printf("-> You defeated the %s!\n\n", enemy->name);
    player->xp += enemy->xp;
    player->gold += enemy->gold;

    printf("!!REWARDS!!\n");
    printf("+------------+\n");
    printf("| XP  : +%-2d  |\n", enemy->xp);
    printf("| GOLD: +%-2d  |\n", enemy->gold);
    printf("+------------+\n");

    waitForEnter();

  } 
}

void explore(Player *player){
  
  int random = rand() % 3;
  Enemy enemy = enemies[random];

  printf("You walk through the forest...\n");
  fightMonster(player, &enemy);
}

int main(void){
  srand(time(NULL));

  Player player;
  
  player.lvl = 1;
  player.hp = 100;
  player.damage = 10;
  player.xp = 0;
  player.inventoryCount = 0;

  int choice = 0;
  
  printf("Please choose your name: ");
  scanf("%29s", player.name);

  do{
    system("clear");
    printMenu(); 

    printf("+--------------+\n");
    printf("| 1. Explore   |\n");
    printf("| 2. Inventory |\n");
    printf("| 3. Stats     |\n");
    printf("| 4. Shop      |\n");
    printf("| 5. EXIT      |\n");
    printf("+--------------+\n");

    while(1){
      printf("\n > ");
      scanf("%d", &choice);
      printf("\n");
      system("clear");

      if(choice >= 1 && choice <= 5){
        break;
      }
      else{
        printf("Invalid choice!\n");
      }
    }
    
    switch(choice){
      case 1:
        printf("--- Exploring ---\n\n");
        explore(&player);
        break;
      
      case 2:
        printInventory(&player);
        break;
      
      case 3:
        playerStats(&player);
        break;
      
      case 4:
        printShop(&player);
      
      case 5:
        break;

      default:
        printf("Invalid input!");
        break;
    }
    if(player.xp >= 100){
      player.lvl += 1;
      system("clear");
      printf("!!LEVEL-UP!!\n");
      printf("+----------+\n");
      printf("| LVL:  %d  |\n", player.lvl);
      printf("| HP : +5  |\n");
      printf("| DMG: +2  |\n");
      printf("+----------+\n");
      player.damage += 2;
      player.hp += 5;
      player.xp -= 100;
      printf("NEW-STATS: \n");
      playerStats(&player);
    }
  }while(choice != 5);
  system("clear");
  printf("Thanks for playing!\n");
}
