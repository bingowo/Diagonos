#include <stdio.h>
#include <stdlib.h>

int r=2333;
int main()
{
  int a[50];
int n;
   int T;int i=0;
   scanf("%d",&T);
   while(T>0)
   {
       scanf("%d",&n);
    int p=n;
       while(p>0){
        a[i]=p%r;
        p=p/r;
        i++;
       }
       i=i-1;
       while(i>=0){
        printf("%d ",a[i]);
        i--;
       }
       i=0;
       T--;
   }
   return 0;
}
