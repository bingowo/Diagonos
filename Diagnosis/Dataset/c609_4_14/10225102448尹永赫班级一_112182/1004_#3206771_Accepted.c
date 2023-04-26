#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int binary_search(char a[], char k, int n)
{
 int left = 0;
 int right = n - 1;
 int flag = 0;
 while (left <= right)
 {
  int mid = left + (right - left) / 2;
  if (a[mid] > k)
  {
   right = mid - 1;
  }
  else if (a[mid] < k)
  {
   left = mid + 1;
  }
  else
  {
   return mid;
   break;
  }
 }
}

int main(){
char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int aa,bb;
char str[100];
scanf("%d %s %d",&aa,str,&bb);

int i=0,j=0,a[1000]={0};
int m=strlen(str);
for (;i<m;)
{
    if (str[i]>=97&&str[i]<=122)
        {str[i]=str[i]-32;}
        a[j]=binary_search(table,str[i],36);
    j+=1;
    i+=1;
}
j=j-1;
i=i-1;

int pp=0;
int h=0;
int v=j;
while (h<=v)
{
    pp=pp+a[h]*pow(aa,j);
    h=h+1;
    j=j-1;
}
char dd[100];
int k=0;
do
    {
    dd[k++]=table[pp%bb];
    pp/=bb;

}
while (pp!=0);

dd[k+1]=table[pp%bb];
for(int f=k-1;f>=0;f--)
{
printf("%c",dd[f]);}
return 0;
}
