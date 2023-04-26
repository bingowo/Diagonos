#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 500
void Input(int a[])   //input a float number
{
    char s[L+1];
    scanf("%s",s);
    int i=0,j,k;
    while(s[i] && s[i]!='.') i++; //定位小数点

    for(j=i-1,k=L;j>=0;j--,k--)
         a[k] = s[j]-'0';  //整数部分
    for(j=i+1,k=L+1;j<strlen(s);j++,k++)
         a[k] = s[j]-'0';   //小数部分
}

void jian(int a[],int b[],int N)
{   int i,x=0,c;
    for(i=2*L;i>L+N;i--)
    {
        c=a[i] - b[i]-x;
        if(c<0){x=1;a[i]=c+10;}
        else{a[i]=c;x=0;}

    }
    if(a[i+1] >= 5) a[i]++;  //a[L+N+1]>=5?  进位
     for(i=L+N;i>0;i--)
    {
        c=a[i] - b[i]-x;
        if(c<0){x=1;a[i]=c+10;}
        else{a[i]=c;x=0;}
    }

}

void output(int a[],int N)
{
    int i=0;
    while(i<=L && a[i]==0) i++; //跳过前置0

    if(i>L){printf("0");}   //整数部分为0
    else
    {
        while(i<=L){
            printf("%d",a[i]);i++;
        } //整数部分
    }
    printf(".");
    while(i<=L+N){printf("%d",a[i]);i++;}  //小数部分

}
int cmp(int a[],int b[])
{
    int i,j;
    for(i=0;i<L*2+1;i++){if(a[i]!=0) break;}
    for(j=0;j<L*2+1;j++){if(a[j]!=0) break;}
    if(j<i) return 1;
    else return 0;

}

int main()
{

    int A[2*L+1]={0}, B[2*L+1]={0},N;
    Input(A);
    Input(B);
    scanf("%d",&N);
    if(cmp(A,B)==1){jian(B,A,N);printf("-");output(B,N);}
    else{jian(A,B,N); //A+=B
    output(A,N);}


}
