/*
* Student ID: 201319103
* Student Name: Jan Clare
* Email: j.a.clare@student.liverpool.ac.uk
*
* User: sgjclare
*
* Problem ID: 1086
* RunID: 16615
* Result: Output Limit Exceed
*/

#include <stdio.h>

void compress(void){

  char currentCHAR;
  char nextCHAR;
  int count = 1;

  while (1){

    /*scan next char*/
    scanf("%c", &nextCHAR);

    /*make sure next char is not end of input*/
    if (nextCHAR == EOF) {
      /*output last thing before breaking*/
      if (count > 1){
        printf("%c%c%d*",currentCHAR,currentCHAR,count);
      } else {
        printf("%c",currentCHAR);
      }
      break;
    }

    /*Check if next and current chars are the same*/
    if (nextCHAR == currentCHAR){
      /*if so start counting*/
      count++;
    } else {
      /*otherwise work out what to output*/
      if (count > 1){
        printf("%c%c%d*",currentCHAR,currentCHAR,count);
      } else {
        printf("%c",currentCHAR);
      }
      /*Make next char the current char and reset count*/
      currentCHAR = nextCHAR;
      count = 1;
    }

  }

}

void expand(void){

  char currentCHAR;
  char previousCHAR;
  int runCount;

  while(1){

    /*scan next char*/
    scanf("%c", &currentCHAR);

    /*Ensure haven't reached end of input*/
    if (currentCHAR == EOF){
      break;
    }

    /*output char specified number of times if read same chars twice*/
    if (currentCHAR == previousCHAR){
      scanf("%i%*c", &runCount);
      for (int i = 1; i<runCount; i++){
        printf("%c",currentCHAR);
      }
    } else {
      /*output only current char and set to previous char before reading next*/
      printf("%c", currentCHAR);
      previousCHAR = currentCHAR;
    }
  }

}

int main(void){

  char action;
  /*first character says what user intends to do*/
  scanf("%c", &action);

  if (action == 'C'){
    compress();
  }
  if (action == 'E'){
    expand();
  }

  return 0;
}
