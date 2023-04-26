#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 110
int add1(char A[],int k)
{
    int i=k;
    while(i>=0)
    {
        A[i]+=1;
        if(A[i]<='9') return i;
        A[i]='0';
        i--;
    }
    return i;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int m=0;m<t;m++)
    {
        printf("case #%d:\n",m);
        char A[MAXN]={'0'};
        scanf("%s",A+1);
        int len=strlen(A);
        int i,j;
        add1(A,len-1);
        for(i=1;i<len;i++)
        {
            if(A[i]==A[i-1]) break;
        }
        if(i!=len)
        {
            i=add1(A,i);
            while(i>0)
            {
                if(A[i]!=A[i-1]) break;
                i=add1(A,i);
            }
            for(j=i+1;j<len;j++)
            {
                A[j]=(j-i+1)%2+'0';
            }
        }
        if(A[0]!='0') printf("%c",A[0]);
        printf("%s\n",A+1);
    }
    return 0;
}
