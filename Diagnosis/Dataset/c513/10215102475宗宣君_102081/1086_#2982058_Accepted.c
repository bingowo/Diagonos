#include <stdio.h>
#include <string.h>
#define L 500
void Input(int a[])
{
    char s[L+1];
    scanf("%s",s);
    int i = 0,j,k;
    while(s[i]&&s[i]!='.') i++;//定位小数点
    for(j = i-1,k = L;j>=0;j--,k--)
        a[k] = s[j]-'0';
    for(j = i+1,k = L+1;j<strlen(s);j++,k++)
        a[k] = s[j]-'0';
}
void sub(int a[],int b[],int N)
{
    int i;
    for(i = 2*L;i>L+N;i--)
    {
        a[i] -= b[i];
        if(a[i]<0)
        {a[i-1] -= 1;;
        a[i] += 10;}
    }
    if(a[i+1]>=5) a[i]++;
    for(i = L+N;i>0;i--)
    {
        a[i]-=b[i];
        if(a[i]<0)
        {a[i-1] -= 1;;
        a[i] += 10;}
    }
}
void output(int a[],int N)
{
    int i = 0;
    while(i<=L &&a[i]==0) i++;
    if(i>L) printf("0");
    else {
        while(i<=L) printf("%d",a[i++]);
    }
    printf(".");
    while(i<=L+N) printf("%d",a[i++]);
    printf("\n");
}
int cmp(int a[],int b[])
{
   int i;
   for(i = 0;i<2*L+1;i++)
   {if(a[i]==b[i]);
   else return a[i]-b[i];
   }
   return 0;
}
int main()
{
    int A[2*L+1] = {0},B[2*L+1] = {0},N;
    Input(A);Input(B);
    scanf("%d",&N);
    if(cmp(A,B)<0) {sub(B,A,N);printf("-");output(B,N);}
    else {sub(A,B,N);output(A,N);}
    return 0;
}
