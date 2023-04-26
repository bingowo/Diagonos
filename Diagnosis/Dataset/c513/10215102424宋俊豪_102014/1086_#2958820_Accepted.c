#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#define L 500
int input(int a[])   //input a float number
{
    char s[L+1];
    scanf("%s ",s);
    int i=0,j,k;
    while(s[i] && s[i]!='.') i++; //定位小数点

    for(j=i-1,k=L; j>=0; j--,k--)
        a[k] = s[j]-'0';  //整数部分
    for(j=i+1,k=L+1; j<strlen(s); j++,k++)
        a[k] = s[j]-'0';   //小数部分
    return i;

}
void time(int a[],int b[],int N)
{
    int i;
    for(i=2*L; i>L+N; i--)
    {
        a[i] -= b[i];
        if(a[i]<0)
        {
            a[i-1]--;
            a[i]+=10;
        }
    }
    if(a[i+1] >= 5) a[i]++;
    for(i=L+N; i>0; i--)
    {
       a[i] -= b[i];
        if(a[i]<0)
        {
            a[i-1]--;
            a[i]+=10;
        }
    }
}

void output(int a[],int N)
{
    int i=0;
    while(i<=L && a[i]==0) i++;  //跳过前置0
    if(i>L) printf("%d",0);   //整数部分为0
    else
    {
        while(i<=L) printf("%d",a[i++]); //整数部分
    }
    printf("%c",'.');
    while(i<=L+N) printf("%d",a[i++]);  //小数部分
    printf("\n");
}
int main()
{
    int la,lb,a[2*L+1]= {0},b[2*L+1]= {0},n;
    la=input(a);
    lb=input(b);
    scanf("%d",&n);
    if(la>lb)
    {
        time(a,b,n);
        output(a,n);
    }
    else if(la<lb)
    {
        time(b,a,n);
        printf("-");
        output(b,n);
    }
    else
    {
      if(a[501-la]>=b[501-la])
      {
          time(a,b,n);
        output(a,n);
      }
      else
      {
           time(b,a,n);
        printf("-");
        output(b,n);
      }
    }
    return 0;
}
