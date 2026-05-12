#include <stdio.h>

int main() {
  char firstName[30];

  printf("Enter your first name and press enter: \n");

  scanf("%s", firstName);

  printf("Olá, %s", firstName);
  
  return 0;
}
