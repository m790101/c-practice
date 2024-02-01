#include <stdio.h>

void genBoard(char board[][3]);
void updateBoard(char board[][3], int pickA);
int playOneRound(int pickA, char playerA, char board[][3]);
void initalGame(char board[][3]);
int checkWin(char board[][3]);

int main()
{
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}};
    char playerA = 'A';
    int pick;
    int times = 0;
    int result = 0; // 0 means no one wins, 1 means someone wins

    initalGame(board);

    while (result == 0)
    {
        result = playOneRound(pick, playerA, board);
        times++;
    }

    return 0;
}

void genBoard(char board[][3])
{
    int i;
    int j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j == 2)
            {
                printf("%c\n", board[i][j]);
            }
            else
            {
                printf("%c | ", board[i][j]);
            }
        }
    }
}

void updateBoard(char board[][3], int pick)
{
    char mark = 'X';

    if (pick == 1)
    {
        board[0][0] = mark;
    }
    else if (pick == 2)
    {
        board[0][1] = mark;
    }
    else if (pick == 3)
    {
        board[0][2] = mark;
    }
    else if (pick == 4)
    {
        board[1][0] = mark;
    }
    else if (pick == 5)
    {
        board[1][1] = mark;
    }
    else if (pick == 6)
    {
        board[1][2] = mark;
    }
    else if (pick == 7)
    {
        board[2][0] = mark;
    }
    else if (pick == 8)
    {
        board[2][1] = mark;
    }
    else if (pick == 9)
    {
        board[2][2] = mark;
    }
}

int playOneRound(int pickA, char playerA, char board[][3])
{
    printf("Player A, please enter a number from 1-9: ");
    while(scanf("%d", &pickA)!=1 || pickA<1 || pickA>9){

        printf("Please enter a valid number: ");
        while(getchar()!='\n');
    }
    printf("Player %c, you have selected %d\n\n\n", playerA, pickA);
    updateBoard(board, pickA);
    genBoard(board);
    printf("\n\n\n");
    int result = checkWin(board);
    if (result == 1)
    {
        printf("Player %c wins!\n\n", playerA);
        printf("-----------Thanks for playing!-------------\n\n");
        return 1;
    }

    return 0;
}

void initalGame(char board[][3]){
    printf("-----------Welcome to Tic-Tac-Tok--------------\n");
    printf("this is the board:\n");
    genBoard(board);
    printf("\n\n\n\n\n");
}

int checkWin(char board[][3])
{
    int i;
    int j;
    int win = 0;

    for (i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            win = 1;
        }
    }

    for (j = 0; j < 3; j++)
    {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j])
        {
            win = 1;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        win = 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        win = 1;
    }

    return win;
}