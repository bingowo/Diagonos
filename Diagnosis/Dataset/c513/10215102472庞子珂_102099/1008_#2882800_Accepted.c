#include<stdio.h>
int main()
{
 int T;
 scanf("%d",&T);
 while(T--){
 int m = 0, n = 0, x = 0, y = 0;
 int i = 0, count = 0;
 //printf("请输入m和n:\n");
 scanf("%d%d", &m, &n);
 for (i = 0; i < 32; i++)
 {
  x = (m >> i) & 1;
  y = (n >> i) & 1;
  if (x != y)
   count++;
     }
 printf("%d\n", count);

  system("pause");}
 return 0;
}

