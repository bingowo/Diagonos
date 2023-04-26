#include <stdio.h>
#include <string.h>

char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void trans_1(int N,int R)
{
    if(N>0)
    {
        trans_1(N/R,R);
        putchar(table[N%R]);
    }
}

int trans_2(char N[],int R)
{
    int i;
    for(i=0;i<strlen(N)-1;i++)
    {
        if(N[i]>='A'&&N[i]<='Z')N[i]=N[i]-55+'0';

        else if(N[i]>='a'&&N[i]<='z')N[i]=N[i]-87+'0';

              else N[i]=N[i]+'0';
    }
    int sum=0;

    for(i=0;i<strlen(N)-1;i++)
    {
        sum=N[i]-'0'+sum*R;
    }

    return sum;
}

int main()
{
    int A,B;
    char n[100];
    scanf("%d",&A);
    scanf("%s",n);
    scanf("%d",&B);
    int M;
    M=trans_2(n,A);
    trans_1(M,B);
    return 0;
}
