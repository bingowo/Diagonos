#include <stdio.h>
#include <string.h>

int pri[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149};

void carry(int *A)
{
    for(int i=999;i>0;i--)
    {
        A[i-1]+=A[i]/10;
        A[i]%=10;
    }
}

void mult(int *A,int count)
{
    for(int i=999;i>=0;i--)
    {
        A[i]*=pri[count];
    }
    carry(A);
}

void add(int *A, int num)
{
    int count= 999;
    while(num)
    {
        A[count--]+=num%10;
        num/=10;
    }
    carry(A);
}

int main()
{
    char s[10000];
    scanf("%s",s);
    int len=strlen(s);
    int count=0;
    int A[1000];
    int B[1000];
    int temp=0;
    for(int i=0;i<len;i++)
    {
        switch (s[i])
        {
            case ',':
                A[count++]=temp;
                temp=0;
                break;
            default:
                temp*=10;
                temp+=s[i]-'0';
                break;
        }
    }
    A[count]=temp;
    for(int i=0;i<=count;i++)
    {
        mult(B,count-i);
        add(B,A[i]);
    }
    count=0;
    while(!B[count]&&count!=999)
        count++;
    while(count<1000)
    {
        printf("%d",B[count++]);
    }
    return 0;
}