#include <stdio.h>
#define ROWS 3
#define COLUMNS 3

void printBoard(char board[ROWS][COLUMNS]) {
  int i, j;

  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLUMNS; j++) {
      printf("|%c|", board[i][j]);
    }
    printf("\n");
  }
}

int checkWin(char board[ROWS][COLUMNS]) {
  int i, j;
  
  for (i = 0; i < ROWS; i++) {    // Check rows
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return 1;
    }
  }
  for (j = 0; j < COLUMNS; j++) {   // Check columns
    if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
      return 1;
    }
  }

  // Check diagonal
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return 1;
  }
  if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ') {
    return 1;
  }
  return 0;
}

int main(){
  int i, j, x, y, moveCount = 0;
  char player = 'X', board[ROWS][COLUMNS];

  // Initialize the board
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLUMNS; j++) {
      board[i][j] = ' ';
    }
  }

  while (1) {
    printf("Player %c, enter your move: Row SPACE Column): ", player);
    scanf("%d%d", &x, &y);
    x--; y--; //substracts 1 from each input so it can be used as coordinates for the 2d array

    if (x >= 0 && x < ROWS && y >= 0 && y < COLUMNS && board[x][y] == ' ') {
      board[x][y] = player;
      moveCount++;
      if (checkWin(board)) {
        printf("Player %c wins!\n", player);
        printBoard(board);
        break;
      }
      if (moveCount == ROWS * COLUMNS) {
        printf("Draw.\n");
        printBoard(board);
        break;
      }
      player = (player == 'X') ? 'O' : 'X';   //switches players
    } else {
      printf("Invalid move.\n");
    }
    printBoard(board);
  }
}