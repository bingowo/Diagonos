#include <stdio.h>
#include <stdlib.h>
int main(){
int T,j=0;
scanf("%d",&T);
while (j<T){
int a[1000]={0};
int c;
scanf("%d",&c);
int i=0;
if (c==0)
{
    printf ("%d",0);
}
else while (c!=0)
{
a[i]=c%2333;
c/=2333;
i+=1;
}
while (i>0)
{
    printf("%d",a[i-1]);
    printf(" ");
    i-=1;
}
j+=1;
printf("\n");
}
return 0;
}
