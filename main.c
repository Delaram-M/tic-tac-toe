#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void WelcomeScreen();
void PlayRound();
void ShowBoard(char board[]);
void Instructions();
void UserInput(char board[],char player[]);
int WinCheck(char board[]);
void NextRound();
void FinalScreen();

char player1[20];
char player2[20];
int player1Points;
int player2Points;
int roundCount;

int main() {

    WelcomeScreen();
    system("cls");
    PlayRound();
    system("cls");
    FinalScreen();

    return 0;
}

//welcome and player names input
void WelcomeScreen(){
    printf("What's your name player 1 ?:");
    scanf("%s",player1);
    printf("What's your name player 2 ?:");
    scanf("%s",player2);
    Sleep(700);
    printf("\nHi %s!",player1);
    Sleep(700);
    printf("\nHi %s!",player2);
    Sleep(700);
    printf("\nWelcome to Tic-Tac-Toe!");
    Sleep(700);
    printf("\n\nGet ready to play...\n");
    Sleep(3000);
}

//playing rounds
void PlayRound(){
    //playing for 1 round
    char board[10];
    for(int i=0;i<10;i++)
        board[i]=' ';
    int turn=1;
    int roundWinner=0;
    while(turn<10&&roundWinner==0){
        system("cls");
        Instructions();
        ShowBoard(board);
        if(roundCount%2==0){
            if(turn%2==1)
                UserInput(board,player1);
            else
                UserInput(board,player2);
        }
        else{
            if(turn%2==1)
                UserInput(board,player2);
            else
                UserInput(board,player1);
        }
        turn++;
        roundWinner=WinCheck(board);
    }
    //showing round results and deciding to continue or not
    printf("\n\nThis Round's Results:\n");
    Sleep(300);
    ShowBoard(board);
    Sleep(300);
    if(roundWinner==1) {
        printf("Congratulations %s!! You won this round!", player1);
        player1Points++;
    }
    else if(roundWinner==2) {
        printf("Congratulations %s!! You won this round!", player2);
        player2Points++;
    }
    else
        printf("Nobody won this round. :( ");
    Sleep(2000);
    NextRound();
}

//game title, scoreboard and instructions
void Instructions(){
    printf("\t\t !! Tic-Toc-Toe !!\n\n");
    printf("Round:%d\n",roundCount+1);
    printf("Scores:\t\t%s:%d\t\t%s:%d\n\n",player1,player1Points,player2,player2Points);
    printf("Instructions:\n");
    printf(" X : %s's symbol\n",player1);
    printf(" O : %s's symbol\n",player2);
    printf("1 |2 |3 \n");
    printf("__|__|__\n");
    printf("4 |5 |6 \n");
    printf("__|__|__\n");
    printf("7 |8 |9 \n");
    printf("  |  |  \n");
}

//graphical state of current game board
void ShowBoard(char board[]){
    printf("\nGame Board:\n");
    printf("  %c |%c |%c \n",board[1],board[2],board[3]);
    printf("  __|__|__\n");
    printf("  %c |%c |%c \n",board[4],board[5],board[6]);
    printf("  __|__|__\n");
    printf("  %c |%c |%c \n",board[7],board[8],board[9]);
    printf("    |  |  \n");
}

//taking user input
void UserInput(char board[],char player[]){
    int choice;
    printf("It's your turn: %s\n",player);
    printf("Choose a square no:");
    scanf("%d",&choice);
    if(choice>9||choice<1) {
        printf("\n!!!!!!Invalid square. Choose a number from 1 to 9!!!!!!\n\n");
        Sleep(500);
        UserInput(board,player);
    }
    else if(board[choice]=='X'||board[choice]=='O'){
        printf("\n!!!!!!This square is already filled!!!!!!!\n\n");
        Sleep(500);
        UserInput(board,player);
    }
    else if(strcmp(player,player1)==0)
        board[choice]='X';
    else if(strcmp(player,player2)==0)
        board[choice]='O';
}

//checing if anybody has won
int WinCheck(char board[]){

    char winner=' ';

    //check filled row
    if((board[1]=='X'&&board[2]=='X'&&board[3]=='X')||
       (board[4]=='X'&&board[5]=='X'&&board[6]=='X')||
       (board[7]=='X'&&board[8]=='X'&&board[9]=='X'))
        winner='X';
    if((board[1]=='O'&&board[2]=='O'&&board[3]=='O')||
       (board[4]=='O'&&board[5]=='O'&&board[6]=='O')||
       (board[7]=='O'&&board[8]=='O'&&board[9]=='O'))
        winner='O';

    //check filled column
    if((board[1]=='X'&&board[4]=='X'&&board[7]=='X')||
       (board[2]=='X'&&board[5]=='X'&&board[8]=='X')||
       (board[3]=='X'&&board[6]=='X'&&board[9]=='X'))
        winner='X';
    if((board[1]=='O'&&board[4]=='O'&&board[7]=='O')||
       (board[2]=='O'&&board[5]=='O'&&board[8]=='O')||
       (board[3]=='O'&&board[6]=='O'&&board[9]=='O'))
        winner='O';

    //check filled diagonal
    if((board[1]==board[5])&&(board[5]==board[9]))
        winner=board[1];
    if((board[3]==board[5])&&(board[5]==board[7]))
        winner=board[3];

    //return meanings:
    //0:no winner    1:player1(X) wins  2:player2(O) wins
    if(winner=='X')
        return 1;
    else if(winner=='O')
        return 2;
    else
        return 0;
}

//asking if users want to play another round
void NextRound(){
    printf("\n\nWould you play another round?\t type \"yes\" or \"no\"!\n");
    char answer[3];
    scanf("%s",answer);
    if(strcmp(answer,"yes")==0){
        roundCount++;
        PlayRound();
    }
    else if(strcmp(answer,"no")!=0){
        printf("\n!!!!Invalid answer!!!!\n ");
        Sleep(500);
        NextRound();
    }
}

//announcing final game results and saying goodbye
void FinalScreen(){
    printf("Final Scores:\n");
    Sleep(700);
    printf("%s:%d\n",player1,player1Points);
    Sleep(700);
    printf("%s:%d\n",player2,player2Points);
    Sleep(700);
    printf("And the winner of this game is...\n");
    Sleep(3000);
    if(player1Points>player2Points)
        printf("%s \nCongratulations!!\n",player1);
    else if(player1Points<player2Points)
        printf("%s \nCongratulations!!\n",player2);
    else
        printf("Nobody won this game! :(\n");
    Sleep(3000);
    printf("\n\nI hope you have enjoyed playing this game. ;)");
    Sleep(7000);
}