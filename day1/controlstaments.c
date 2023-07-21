#include <stdio.h>

int main(void) {
  int n ;
  printf("Type a number: \n");
  scanf("%d", &n);
  if(n>=18)
  {
    printf("you are eligible to vote");
  }
  else if (n > 0 && n < 18)
  {
      printf("Sorry..! , you are not eligible to vote");
  }
  else {
    printf(" invalid input");
  }
  return 0;
}
