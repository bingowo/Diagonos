#include <stdio.h>
#include <string.h>

int main()
{
    long long int sum=0;
    long long int count=1;
    int len=0;
    char S[50];
    long long int A[50];
    char *p=S;
    long long int *p2=A;
    int Roma[128]={0};
    Roma['I']=1;Roma['V']=5;
    Roma['X']=10;Roma['L']=50;    Roma['C']=100;Roma['D']=500;
    Roma['M']=1000;
    scanf("%s",S);

    while(*p)
    {
        if(*p=='(') count*=1000;
        else if(*p==')') count/=1000;
        else
        {
            *p2=Roma[*p]*count;
            p2++;
            len++;
        }
        p++;
    }
    p2=A;
    while(p2<A+len)
    {
        if(*p2<*(p2+1)&&p2!=A+len-1)
        {
            sum=sum-*p2;
            p2++;
        }

        else if(p2==A+len-1)
        {
            sum+=*p2;
            p2++;
        }


        else
        {
            sum+=*p2;
            p2++;

        }


    }
    printf("%lld",sum);

}
