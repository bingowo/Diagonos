#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    int x =0,y =0;
    int num = 1;
    scanf("%d",&n);
    int i = n;
    if (n == 0) x = 0,y = 0;
    else
 {
     do{
       for (int temp = num, plus = pow(-1,num+1);temp != 0;temp--)
  {
       if (i == 0)
      break;
      y += plus;
      i--;
  }
  for (int temp = num,plus = pow(-1,num);temp != 0;temp--)
  {
         if (i == 0)
         break;
         x += plus;
        i--;
  }
  num++;
 }while (i != 0);
 }
 printf("(%d,%d)",x,y);
 return 0;
}