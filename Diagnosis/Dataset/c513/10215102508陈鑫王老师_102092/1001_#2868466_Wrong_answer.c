#include<stdio.h>
#include<stdlib.h>
void itor(int x,char s[1000],int y)
{
    char L[1000];
    int i=0,sign,j,a;
    sign=1;
    if(x<0)
    {
        s[0]='-';
        sign=(-1);
        x=sign*x;
    }
    while(x>0)
    {
        if(x%y<=9)
            L[i++]=x%y+48;
        else L[i++]=x%y+55;
        x=x/y;
    }
    a=i;
    for(j=(sign==1)?0:1;j<=a;j++,i--)
    {
        s[j]=L[i-1];
    }
}
int main()
{
 int t;
 scanf("%d",&t);
 int a[t][2];
 int c=0;
 while(c<t)
 {
     scanf("%d%d",&a[c][0],&a[c][1]);
     c+=1;
 }
 for(int j=0;j<t;j++)
 {
     char s[1000]={};
     itor(a[j][0],s,a[j][1]);
     printf("%s\n",s);
 }
 return 0;
}
