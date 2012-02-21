#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

const int BOARD_SIZE = 6;
typedef pair<int,int> loc;

enum {BLOCKED=-2, EMPTY=-1, START=-3, END=-4};
   // add OUT_OF_BOUNDS, can be returned from board object instead of checks
   //  to ensure we're in bounds as below

void print_board(int board[6][6], loc end) 
{
    int endi = end.first;
    int endj = end.second;
    int i;
    int j;
    printf("\n ");
    for(i=0; i<BOARD_SIZE; i++)
    {
        for(j=0; j<BOARD_SIZE; j++)
        {
            if (j==BOARD_SIZE-1)
            {
                if (i==endi && j == endj) printf("E\n ");
                if (board[i][j] == EMPTY) printf(" \n ");
                else if (board[i][j] == BLOCKED) printf("X\n ");
                else if (board[i][j] == START) printf("S\n ");
                else printf("%d\n ", board[i][j]);
            }
            else
            {
                if (i == endi && j == endj) printf("E | ");
                else if (board[i][j] == EMPTY) printf("  | ");
                else if (board[i][j] == BLOCKED) printf("X | ");
                else if (board[i][j] == START) printf("S | ");
                else printf("%d | ", board[i][j]);
            }
        }
        if (i != BOARD_SIZE-1)
            printf("------------------------\n ");
    }
}


int shortest_path(int board[6][6], loc start, loc end)
{
    queue<loc> q;

    board[start.first][start.second] = 0;

    q.push(start);

    while(!q.empty())
    {
        loc curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;

        //printf("curr = %d,%d, dist = %d\n", x, y, board[x][y]);

        if (x == end.first && y == end.second)
            return board[x][y];
        
        int dist = board[x][y]+1;

        if(x-1 >= 0 && board[x-1][y] == EMPTY)
        {
            board[x-1][y] = dist;
            q.push(loc(x-1,y));
        }
        if (x+1<BOARD_SIZE && board[x+1][y] == EMPTY)
        {
            board[x+1][y] = dist;
            q.push(loc(x+1,y));
        }
        if (y-1 >= 0 && board[x][y-1] == EMPTY)
        {
            board[x][y-1] = dist;
            q.push(loc(x,y-1));
        }
        if (y+1<BOARD_SIZE && board[x][y+1] == EMPTY)
        {
            board[x][y+1] = dist;
            q.push(loc(x,y+1));
        }
    }
    return -1;
}

int main(int argc, char* argv[])
{
    int board[BOARD_SIZE][BOARD_SIZE];
    int i, j;
    for(i=0; i<BOARD_SIZE; i++)
        for(j=0; j<BOARD_SIZE; j++)
            board[i][j] = EMPTY;

    loc end(4,4);
    loc start(1,1);

    board[2][3] = BLOCKED;
    board[3][3] = BLOCKED;
    board[0][0] = BLOCKED;
    board[1][0] = BLOCKED;
    board[3][5] = BLOCKED;
    board[5][2] = BLOCKED;
    board[3][4] = BLOCKED;

    board[1][1] = START;
    print_board(board, end);

    int dist = shortest_path(board, start, end);
    
    print_board(board, end);
    printf("shortest path was %d\n", dist);
}

