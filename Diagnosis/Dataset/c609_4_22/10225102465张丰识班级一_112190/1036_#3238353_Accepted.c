#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int search(char *s)
{
 int count = 0;
 for(int i = 0;i < strlen(s);i++)
 {
  if(s[i] == '(') count++;
  else count--;
  if(count == 0) return i;
 }
}

int sum(char *s)
{
 int pos = search(s);
 if(strlen(s) == 2) return 1;
 if(pos == strlen(s)-1)
 {
  s[pos] = '\0';
  return 2*sum(s+1);
 }
 else if(pos > 1)
 {
  s[pos] = '\0';
  return 2*sum(s+1) + sum(s+pos+1);
 }
 else
 {
  s[pos] = '\0';
  return 1+sum(s+pos+1);
 }
}

int main()
{
 char *s = (char*)malloc(51*sizeof(char));
 scanf("%s",s);
 printf("%d",sum(s));
 free(s);
 return 0; 
}