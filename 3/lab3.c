//Dias Karshal CSCI151 LAB3
#include <stdio.h>
int main(){
    printf("==========================================\n");
    printf("==                 TASK 1:              ==\n");
    printf("==========================================\n");

    int n;
    printf("Enter starting number N: ");
    scanf("%d", &n);

    for(int i = 1; i<=n; i++){
        int sum = 0, copy = i, check = 1;
        
        while(copy>0){
            sum+=copy%10;
            copy/=10;
        }
        
        for(int j = 2; j*j<=sum; j++){
            if(sum%j==0){
                check = 0;
            }
        }

        if(check==1){
            printf("%d: Sum of digits = %d, which is a prime number.\n", i, sum);
        }
    }

    printf("==========================================\n");
    printf("==                 TASK 2:              ==\n");
    printf("==========================================\n");
    
    printf("\n\n==========================================\n");
    printf("  Welcome to the Treasure Hunt Adventure! \n");
    printf("==========================================\n");

    printf("Rules:\n");
    printf("- You cant go an adventurer on a 3x3 grid. Each position on the grid may contain a treasure, a trap, a potion, or be empty.\n");
    printf("- Your goal is to navigate through the grid, collect treasures, avoid traps, and reach the exit at the bottom-right corner.\n");
    printf("- You start with 100 Health Points (HP) and 0 points. Treasures increase your score, traps reduce your HP, and potions restore your HP.\n");
    printf("- You can move in four directions: Up (W), Down (S), Left (A), or Right (D\n");
    printf("- The game ends when you reach the exit (or user presses ‘E’ for quitting the game) or if your HP drops to 0.\n");
    printf("Let's begin! Your adventure starts now.\n");

    int ROW = 2, COLUMN = 2, HP = 100, SCORE = 0;

    while(1){
        char move;
        printf("Your move: ");
        scanf(" %c", &move);
        if(move == 'W'){
            if(ROW<=1){
                printf("You cant go outside of the 3x3 grid!\n");
                continue;
            }
            else{
                ROW-=1;
            }
        }
        else if(move == 'S'){
            
            if(ROW>=3){
                printf("You cant go outside of the 3x3 grid!\n");
                continue;
            }
            else{
                ROW+=1;
            }
        }
        else if(move == 'A'){
            
            if(COLUMN<=1){
                printf("You cant go outside of the 3x3 grid!\n");
                continue;
            }
            else{
                COLUMN-=1;
            }
        }
        else if(move == 'D'){
            if(COLUMN>=3){
                printf("You cant go outside of the 3x3 grid!\n");
                continue;
            }
            else{
                COLUMN+=1;
            }
        }
        else if(move == 'E'){
            printf("The game quits.\n");
            printf("HP: %d\n", HP);
            printf("Score: %d\n", SCORE);
            break;
        }
        else{
            printf("Wrong turn.\n");
            continue;
        }

        if((ROW==1 && COLUMN==1) || (ROW==1 && COLUMN==3) || (ROW==3 && COLUMN==2) || (ROW==2 && COLUMN==2)){
            printf("Output:\n");
            printf("Location (%d, %d): It's empty. Nothing happens.\n", ROW, COLUMN);
            printf("HP: %d\n", HP);
            printf("Score: %d\n", SCORE);
        }
        else if((ROW==1 && COLUMN==2)){
            if(HP-20>0){
                HP-=20;
                printf("Output:\n");
                printf("Locatoin (%d, %d): Oh no! You stepped on a trap! -20HP.\n", ROW, COLUMN);
                printf("HP: %d\n", HP);
                printf("Score: %d\n", SCORE);
            }
            else{
                printf("Your health has dropped to zero. Game over.\n");
                break;
            }
        }
        else if(ROW==2 && COLUMN==1){
            HP+=20;
            printf("Output:\n");
            printf("Locatoin (%d, %d): You found a potion! +20HP.\n", ROW, COLUMN);
            printf("HP: %d\n", HP);
            printf("Score: %d\n", SCORE);
        }
        else if(ROW==2 && COLUMN==3){
            if(HP-30>0){
                HP-=30;
                printf("Output:\n");
                printf("Locatoin (%d, %d): Oh no! You stepped on a trap! -30HP.\n", ROW, COLUMN);
                printf("HP: %d\n", HP);
                printf("Score: %d\n", SCORE);
            }
            else{
                printf("Your health has dropped to zero. Game over.\n");
                break;
            }
        }
        else if(ROW==3 && COLUMN==1){
            SCORE+=20;
            printf("Output:\n");
            printf("Locatoin (%d, %d): Congratulations! You found a treasure! +20 points.\n", ROW, COLUMN);
            printf("HP: %d\n", HP);
            printf("Score: %d\n", SCORE);
        }
        else if(ROW==3 && COLUMN==3){
            printf("Output:\n");
            printf("Locatoin (%d, %d): You've found the exit! The game ends.\n", ROW, COLUMN);
            printf("HP: %d\n", HP);
            printf("Score: %d\n", SCORE);
            break;
        }
    }

    printf("Final Output: Congratulations! You've completed the game. Final Score: %d, Final HP: %d", SCORE, HP);

    return 0;
}