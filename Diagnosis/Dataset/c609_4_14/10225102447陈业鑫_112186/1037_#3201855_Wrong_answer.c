#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {

 char s[1000000] = { 0 };
 int i = 0;
 int p[1000000] = { 0 };
 while (1)
 {
  char a = getchar();
  if (a == '\n')
   break;
  int pp = a;
  if (p[pp] == 0)
  {
   s[i++] = a;
   p[pp] = 1;
  }
 }
 puts(s);
}