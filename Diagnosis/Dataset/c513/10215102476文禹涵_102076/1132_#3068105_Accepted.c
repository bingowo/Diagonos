#include <stdio.h>
#include <stdlib.h>

int main()
{
int T,i;
 scanf("%d",&T);
 char table1[] = "0123456789ABCDEF";
 for(i = 0;i < T;i++)
 {
 int n,r,cnt = 0,sum = 0;
scanf("%d %d",&n,&r);
 char change[34] = {0};
 while(n != 0)
 {
 sum = sum + n % r;
 n /= r;
 }
 while(sum != 0)
 {
 change[cnt++] = table1[sum % r];
 sum /= r;
}
 printf("case #%d:\n",i);
 for(int j = cnt - 1;j >= 0;j--)
printf("%c",change[j]);
 putchar('\n');
 }
 return 0;
}