#include <stdio.h>
#include <stdlib.h>

// The Function to print the Tic Tac Toe Board
void PrintBoard(char board [3][3]) 
{
    printf("\n");
    for (int i = 0; i < 3; i++) 
	{
        printf(" %c | %c | %c ", board [i][0], board [i][1], board [i][2]); // function to print on the screen
        if (i != 2)
            printf("\n---|---|---\n"); // function to print on the screen
    }
    printf("\n");
}

// Function to check if any player has Won the Game
int CheckWin(char board [3][3], char symbol) 
{
    for (int i = 0; i < 3; i++) 
	{
        if (board [i][0] == symbol && board [i][1] == symbol && board [i][2] == symbol)
            return 1;
			
        if (board [0][i] == symbol && board [1][i] == symbol && board [2][i] == symbol)	
            return 1;
    }
    if (board [0][0] == symbol && board [1][1] == symbol && board [2][2] == symbol)
        return 1;
	
    if (board [0][2] == symbol && board [1][1] == symbol && board [2][0] == symbol)
        return 1;
	
    return 0;
}

// Function to check if the Game was a Draw
int CheckDraw(char board [3][3]) 
{
    for (int i = 0; i < 3; i++) 
	{
        for (int j = 0; j < 3; j++) 
		{
            if (board [i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

// Function to play the game in the Multiplayer Mode
void MultiplayerMode() 
{
    char board [3][3] = 
	{
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int CurrentPlayer = 1;
    int choice, row, column;

    while (1) 
	{
        PrintBoard(board);

        printf("\nPlayer %d, Please enter your move (0-8) or (enter -1 to quit the game): ", CurrentPlayer); // function to print on the screen
        scanf("%d", &choice);

        if (choice == -1) 
		{
            printf("The Game has been ended by the player\n"); // function to print on the screen
            break;
        }
		
        column = choice % 3;
        row = choice / 3;

        if (board [row][column] != ' ') 
		{
            printf("Invalid input. Please try again.\n"); // function to print on the screen
            continue;
        }

        if (CurrentPlayer == 1)
            board [row][column] = 'X';
        else
            board [row][column] = 'O';

        if (CheckWin(board, CurrentPlayer == 1 ? 'X' : 'O')) 
		{
            PrintBoard(board);
			
            printf("\nPlayer %d wins!\n", CurrentPlayer); // function to print on the screen
            break;
        }

        if (CheckDraw(board)) 
		{
            PrintBoard(board);
			
            printf("\nIt's a draw!\n"); // function to print on the screen
            break;
        }
        CurrentPlayer = (CurrentPlayer == 1) ? 2 : 1;
    }
}

// Function to play the game in the Single player mode
void SinglePlayerMode() 
{
    char board [3][3] = 
	{
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int CurrentPlayer = 1;
    int choice, row, column, rand();

    while (1) 
	{
        PrintBoard(board);

        if (CurrentPlayer == 1) 
		{
        printf("\nPlayer, Please enter your move (0-8) or (enter -1 to quit the game): ", CurrentPlayer); // function to print on the screen
        scanf("%d", &choice);

        if (choice == -1) 
		{ 
            printf("The Game has been ended by the player\n"); // function to print on the screen
            break;
        }
		
        column = choice % 3;
        row = choice / 3;
        }
		
        else {
			printf("\nComputer's turn:\n"); // function to print on the screen
            do {
                row = rand() % 3;
                column = rand() % 3;
            } while (board [row][column] != ' ');
        }

        if (board [row][column] != ' ') 
		{
            if (CurrentPlayer == 1)
                printf("Invalid input. Please try again.\n"); // function to print on the screen
            continue;
        }

        if (CurrentPlayer == 1)
            board [row][column] = 'X';
        else
            board [row][column] = 'O';

        if (CheckWin(board, CurrentPlayer == 1 ? 'X' : 'O')) 
		{
            PrintBoard(board);
            if (CurrentPlayer == 1)
                printf("\nYou win!\n"); // function to print on the screen
            else
                printf("\nComputer wins!\n"); // function to print on the screen
            break;
        }

        if (CheckDraw(board)) 
		{
            PrintBoard(board);
            printf("\nIt's a draw!\n"); // function to print on the screen
            break; 
        }
        CurrentPlayer = (CurrentPlayer == 1) ? 2 : 1;
    }
}

int main() 
{
    int mode;

    // Choose the game mode you want to play
    printf("\nSelect the game mode:\n"); // function to print on the screen
    printf("1. Multiplayer\n"); // function to print on the screen
    printf("2. Single player\n"); // function to print on the screen
    printf("Please enter your choice (1-2): "); // function to print on the screen
    scanf("%d", &mode);

    if (mode < 1 || mode > 2) 
	{
        printf("Invalid input\n"); // function to print on the screen
        return 0;
    }
	
    if (mode == 1)
        MultiplayerMode();
    else
        SinglePlayerMode();
	
	int playAgain;
    printf("\nDo you want to play again? (1 -> Yes, 0 -> No): "); // function to print on the screen
    scanf("%d", &playAgain);
    
    if (playAgain) 
	{
        main(); // Restart the game
    } else 
	{
        printf("\nThanks for playing the Tic Tac Toe game!\n"); // function to print on the screen
    }

    return 0;
}
