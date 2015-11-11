#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void GenerateString(int n, char* string)
{
    int i = 0;
    char s[] = " ";
    strcat(string, "a");
    for (i = 1; i < n; i++)
      {
          s[0]='a' + i;
          strncat (string, s, 1);
          strncat (string, string, strlen(string) - 1);
      } 
  return;      
}  

int main() 
{
  int n;
  scanf("%d", &n);
  char* string = (char*)malloc(((1<<n) - 1) * sizeof(char));
  GenerateString(n, string);
  printf("%s \n", string);
  free(string);
  return 0;
}
