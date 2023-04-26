#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#define L 500
void input(int a[])   //input a float number
{
    char s[L+1];
    scanf("%s ",s);
    int i=0,j,k;
    while(s[i] && s[i]!='.') i++; //定位小数点

    for(j=i-1,k=L; j>=0; j--,k--)
        a[k] = s[j]-'0';  //整数部分
    for(j=i+1,k=L+1; j<strlen(s); j++,k++)
        a[k] = s[j]-'0';   //小数部分

}
void add(int a[],int b[],int N)
{
    int i;
    for(i=2*L; i>L+N; i--)
    {
        a[i] += b[i];
        a[i-1] += a[i]/10;
        a[i] %= 10;
    }
    if(a[i+1] >= 5) a[i]++;
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
    int a[2*L+1]= {0},b[2*L+1]= {0},n;
    input(a);
    input(b);
    scanf("%d",&n);
    add(a,b,n);
    output(a,n);
    return 0;
}
