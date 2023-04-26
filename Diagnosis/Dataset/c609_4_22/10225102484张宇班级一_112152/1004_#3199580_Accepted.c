#include<stdio.h>
#include <ctype.h>
char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void trans2(int y,int B)
{
    if(y>0)
    {
        trans2(y/B,B);
        putchar(table[y%B]);
    }
}
int main()
{
    int A,B;char n[100];
    scanf("%d%s%d",&A,n,&B);
    int x=0;
    for(int i=0;n[i]!=0;i++)
  {
    if(n[i]>64&&n[i]<97)
        x=x*A+(n[i]-55);
    else if(n[i]<65) x=x*A+(n[i]-48);
    else x=x*A+(n[i]-87);
  }
    if(x==0)printf("0");
    trans2(x,B);
    return 0;


}
