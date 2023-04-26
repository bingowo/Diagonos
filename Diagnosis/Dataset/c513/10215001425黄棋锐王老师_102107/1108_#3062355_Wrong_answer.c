#include<stdio.h>
int main()
{
 int a[50];
 int m,n;
 printf("输入数字被除数m和除数n\n");
 scanf("%d %d",&m,&n);
 printf("%d.",m/n);       //将小数点前的部分商和“.”输出 。
 
 m=m%n;                   //第一次求出商的余数。
 int i,k,mark=0;     


 /*提示：可将商存放在一维数组中，进行除法运算时，可模拟人的手工操作，
 即每次求出商的一位后，将余数乘以10，再计算商的下一位。若某次余数为0，则为有限不循环小数。
 若某次计算后的余数与前面的某个余数相同时，则M／N是无限循环小数。*/
 for(k=0; ; k++)
 {
  if(k==20)  break;    //题目仅要求小数后20，小数位数超过20就跳出。
  m*=10;            
  a[k]=m/n;        
  
  for(i=0;i<k;i++)
  {
   if(a[i]==a[k])
   {
    mark=1;     //mark标记有相同的结果。
    break;
   }
  }                   //判断是否有与前面相同的结果，如果有则商为无限的。
  
  if(mark)  break;   //若mark==1时，已判断商是无限的小数，跳出循环。
  
  m=m%n;
  if(m==0)
  {         //如果余数为零，则商是有限的小数，跳出循环。
   break;
     }
 }
 
 if(mark)
 {
  for(i=0; i<k; i++)
  printf("%d",a[i]);
 }
 
 else
 {
  for(i=0; i<=k; i++)
  printf("%d",a[i]);
 }
 
 return 0; 
}

