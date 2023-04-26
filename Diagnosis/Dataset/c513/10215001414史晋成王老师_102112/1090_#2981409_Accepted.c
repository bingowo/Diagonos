#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int N=11000;
int main()
{ int a,i,j,n;
double f,m;
while(scanf("%d",&a)!=EOF)
{
    if(a==0) break;
    else{
    f=a;
    m=f*log10(f);
    m-=(int)m;
    i=pow(10,m);
    printf("%d\n",i);
}

    
}
    
}