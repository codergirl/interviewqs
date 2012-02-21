#include <stdio.h>
#include <stdlib.h>

typedef enum game_state_e {
    WINNER_X,
    WINNER_O,
    STALEMATE,
    NONE
} game_state;

game_state get_winner(char c) 
{
    return c == 'X' ? WINNER_X : WINNER_O;
}

game_state check_for_winner(char board[3][3], int turn)
{
    // check diagonals
    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
        return get_winner(board[1][1]); 

    // check rows
    int i;
    for(i=0; i<3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return get_winner(board[i][0]);
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return get_winner(board[0][i]);
    }

    return NONE;
}

void print_board(char board[3][3])
{
    int i;
    int j;
    printf("\n");
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            if (j!=2)
            {
                printf(" %c |", board[i][j]);
            }
            else
            {
                printf(" %c\n", board[i][j]);
            }
        }
        if (i!=2)
        {
            printf("-----------\n");
        }
    }
}

void do_turn(char board[3][3], int move, char player)
{
    int row; int col;
    move--;
    row = move/3;
    col = move%3;

    board[row][col] = player;

}

char next_player(char c)
{
    return c == 'X' ? 'O' : 'X';
}

int main(int argc, char* argv[])
{
    char board[3][3] = {
                         { '1','2', '3' },
                         { '4', '5', '6' },
                         { '7', '8', '9' }
                       };

    char player = 'X';
    game_state state = NONE;
    int i;
    int move;
    for(i=0; i<9; i++)
    {
        print_board(board);

        printf("\nPlayer %c please enter your move: ", player);
        scanf("%d", &move);
        do_turn(board, move, player);
        

        player = next_player(player);
        state = check_for_winner(board, player);
        if (state == WINNER_X)
        {
            printf("X wins!\n"); print_board(board); break;
        }
        else if (state == WINNER_O)
        {
            printf("O wins!\n"); print_board(board);  break;
        }
    }
    

}
