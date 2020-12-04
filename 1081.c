/*
* Student ID: 201319103
* Student Name: Jan Clare
* Email: j.a.clare@student.liverpool.ac.uk
*
* User: sgjclare
*
* Problem ID: 1081
* RunID: 16614
* Result: Accepted
*/

#include <stdio.h>

/*Make rows, columns and steps global variables so all functions can use it*/
int rows;
int columns;
int steps;
/*for storing adjacent squares to a particular square*/
int neighbours[8][2];

/*Prints board*/
void printBoard(char board[rows][columns]){
  /*Goes through board and prints every item in format detailed in spec*/
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < columns; j++){
      printf("%c", board[i][j]);
    }
    printf("\n");
  }
}

/*takes x and y co-ordinate and fills "adjacent" array with co-ordinates of adjacent squares*/
void findNeighbours(int x,int y){
  neighbours[0][0] = x-1; neighbours[0][1] = y+1;
  neighbours[1][0] = x;   neighbours[1][1] = y+1;
  neighbours[2][0] = x+1; neighbours[2][1] = y+1;
  neighbours[3][0] = x-1; neighbours[3][1] = y;
  neighbours[4][0] = x+1; neighbours[4][1] = y;
  neighbours[5][0] = x-1; neighbours[5][1] = y-1;
  neighbours[6][0] = x;   neighbours[6][1] = y-1;
  neighbours[7][0] = x+1; neighbours[7][1] = y-1;
}

int main(void){
  /*take user inputs*/
  scanf("%i %i %i", &rows, &columns, &steps);

  /*Create board*/
  char board[rows][columns];

  /*Fill board with user's inputs*/
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < columns; j++){
      char c;
      scanf(" %c", &c);
      board[i][j] = c;
    }
  }

  /*for each step*/
  for (int s =0; s < steps; s++){
    /*create new board*/
    char newBoard[rows][columns];

    /*go through every square in board array*/
    for (int i = 0; i < rows; i++){
      for (int j = 0; j < columns; j++){

        /*identify neighbours' co-ordinates*/
        findNeighbours(j, i);

        /*for each neighbour, count alive ones*/
        int aliveNeighbours = 0;
        for (int k = 0; k < 8; k++){
          if (neighbours[k][0] < 0 || neighbours[k][0] >= columns || neighbours[k][1] < 0 || neighbours[k][1] >= rows){
            /*i.e if neighbour's co-ordinate out of board's co-ordinate range: ignore*/
            continue;
          } else {
            if (board[neighbours[k][1]][neighbours[k][0]] == 'X'){
              aliveNeighbours++;
            } else {
              continue;
            }
          }
        }

        /*After alive neighbours counted, work out status in new board according to rules in spec*/
        if (board[i][j] == 'X' && (aliveNeighbours == 2 || aliveNeighbours == 3)){
          newBoard[i][j] = 'X';
        } else {
          if (board[i][j] == '.' && aliveNeighbours == 3) {
            newBoard[i][j] = 'X';
          } else {
            newBoard[i][j] = '.';
          }
        }
      }
    }

    /*update old board to new board at the end of each step*/
    for (int l = 0; l < rows; l++){
      for (int m = 0; m < columns; m++){
        board[l][m] = newBoard[l][m];
      }
    }
  }

  printBoard(board);

  return 0;
}
