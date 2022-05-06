#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

float getnum2root(int argc, char *argv[]);
float algorithm(long num2root);

int main(int argc, char *argv[]) {
  char strnum2root[64];
  char *ptr;
  long num2root;
  float solution;
  
  num2root = getnum2root(argc, argv);
  solution = algorithm(num2root);

  printf("The solution is %.4f\n", solution);

  return (1);
}


float algorithm(long num2root) {
 // printf("%ld\n", num2root - 10); 
  float counter, biggest, smallest, guess;
  smallest = 0;
  biggest = 1000;
  
  for (counter = 0; counter <= 50; counter++) {
    guess = (smallest + biggest) / 2;
    
    //printf("Guess: %f, Smallest: %f, Largest: %f\n", guess, smallest, biggest);
    
    if (pow(guess, 2) == num2root) {
      return guess;
    } else if (pow(guess, 2) > num2root) {
        biggest = guess;
      } else {
        smallest = guess;
      }
    }
    return (guess);
  }



float getnum2root(int argc, char *argv[]) {
  char strnum2root[64];
  char *ptr;
  long num2root;

  if (argc >= 2) {
    strcat(strnum2root, argv[2]);
  } else {
    printf("Enter the number to root: ");
    fgets(&strnum2root, 10, stdin);
  }
  
  num2root = strtol(strnum2root, &ptr, 10);

  return (num2root);
  }
