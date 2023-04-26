#include<stdio.h>
#include<math.h>
int main()
{
    long long int n;
    long long int x =0,y =0;
    long long int num = 1;
    scanf("%lld",&n);
    long long int i = n;
    if (n == 0) x = 0,y = 0;
    else
 {
     do{
       for (long long int temp = num, plus = pow(-1,num+1);temp != 0;temp--)
  {
       if (i == 0)
      break;
      y += plus;
      i--;
  }
  for (long long int temp = num,plus = pow(-1,num);temp != 0;temp--)
  {
         if (i == 0)
         break;
         x += plus;
        i--;
  }
  num++;
 }while (i != 0);
 }
 printf("(%lld,%lld)",x,y);
 return 0;
}