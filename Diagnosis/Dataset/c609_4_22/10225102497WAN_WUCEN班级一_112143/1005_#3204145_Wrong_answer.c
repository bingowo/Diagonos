#include<stdio.h>
int transfer(char a)
{
    int b;
    if(a=='-')b=-1;
    else if(a=='0')b=0;
    else b=1;
    return b;
}
main()
{
char in[10][30];
int out[10];
int a,j,T,i,n=0;
scanf("%d",&T);
for(i=0;i<T;i++)
    scanf("%s",in[i]);
for(i=0;i<T;i++){
for(j=0;in[i][j]!=0;j++)
    n=n*3+transfer(in[i][j]);
    out[i]=n;
    printf("case #%d:\n",i);
    printf("%d",n);
    n=0;
    }
}
