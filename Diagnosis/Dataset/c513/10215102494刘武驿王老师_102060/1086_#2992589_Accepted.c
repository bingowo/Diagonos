#include <stdio.h>
#include <string.h>
#define L 500

void Input(int a[])  
{
    char s[L+1];
    scanf("%s",s);
    int i=0,j,k;
    while(s[i] && s[i]!='.') i++; 
    for(j=i-1,k=L;j>=0;j--,k--)
         a[k] = s[j]-'0';  
    for(j=i+1,k=L+1;j<strlen(s);j++,k++)
         a[k] = s[j]-'0';  
}

int cmp(int a[],int b[])
{
    int i;
    for(i=0;i<=2*L;i++)
    {
        if(a[i]==b[i])
        continue;
        else if(a[i]>=b[i])
        {
            return 1;
        }
        else return -1;
    }
}

void minus(int a[],int b[],int N)
{   int i;
    for(i=2*L;i>=0;i--)
    {
        a[i] =a[i]-b[i];
    }
    for(i=2*L;i>=0;i--)
    {
        if(a[i]<0)
        {
            a[i]=a[i]+10;
            a[i-1]--;
        }
    }
    for(i=L+N;i>=0;i--)
    {
        if(a[i+1] >= 5&&i==L+N) a[i]++;
        if(a[i]>=10)
        {
            a[i]=a[i]-10;
            a[i-1]++;
        }
    }
}

void output(int a[],int N)
{
    int i=0;
    while(i<=L && a[i]==0) i++;  
    if(i>L) printf("0");   
    else
    {
        while(i<=L) printf("%d",a[i++]); 
    }
    printf(".");
    while(i<=L+N) printf("%d",a[i++]);
    printf("\n");
}


int main()
{
    int A[2*L+1]={0}, B[2*L+1]={0},N;
    Input(A);
    Input(B);
    if(cmp(A,B)==1)
    {
        scanf("%d",&N);
        minus(A,B,N);
        output(A,N);
    }
    else
    {
        scanf("%d",&N);
        minus(B,A,N); 
        printf("-");
        output(B,N);
    }

}
