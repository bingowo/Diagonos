#include <stdio.h>
#define L 500

void add(int *a,int *b,int n)
{   int i;
    for(i=2*L;i>L+n;i--) {  a[i] += b[i];  a[i-1] += a[i]/10;  a[i] %=10; }
    if(a[i+1] >= 5) a[i]++;
    for(i=L+n;i>0;i--)  { a[i] += b[i]; a[i-1] += a[i]/10; a[i] %= 10; }
}

void Input(int *a)   //input a float number
{  char s[L+1];  int i=0,j,k; scanf("%s",s);
    while(s[i] && s[i]!='.') i++; //定位小数点
    for(j=i-1,k=L;j>=0;j--,k--)  a[k] = s[j]-'0';  //整数部分
    for(j=i+1,k=L+1;j<strlen(s);j++,k++)  a[k] = s[j]-'0';   //小数部分
}

void output(int *a,int n)
{ int i=0;
    while(i<=L && a[i]==0) i++;  //跳过前置0
    if(i>L) printf("%d",0);   //整数部分为0
    else while(i<=L) printf("%d",a[i++]); //整数部分
    printf(".");
    while(i<=L+n) printf("%d",a[i++]);  //小数部分
    printf("\n");
}

int main()
{   int A[2*L+1]={0}, B[2*L+1]={0},n;
     Input(A); Input(B);scanf("%d",&n);
     add(A,B,n); //A+=B
     output(A,n);
     return 0;
}