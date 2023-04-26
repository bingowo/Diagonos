#include<stdio.h>
#include<string.h>
#define MAXLENGTH 64
 
void Combine(const char str[])
{
 if (str == NULL || *str == 0)
  return;
 int len = strlen(str);
 bool used[MAXLENGTH] = { 0 };
 char cache[MAXLENGTH];
 char *result = cache + len;
 *result = 0;
 while (1)
 {
  int index = 0;
  while (used[index])
  {
   used[index] = false;
   ++result;
   if (++index == len)
    return;
  }
  used[index] = true;
  *--result = str[index];
  printf("%s ", result);
 }
}
 
int main()
{
 Combine("abc");
 printf("\n");
 return 0;
}