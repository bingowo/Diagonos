#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int GCD(long long int a,long long int b)
{
    long long int max=b;
    long long int min=a;
    while(max%min)
    {
        long long int temp=max%min;
        max=min;
        min=temp;
    }
    return min;
}

int main()
{
    char s[31];
    scanf("%s",s);
    int p=0;
    long long int ansA=0,ansB=0,ansC=1;
    for(;p<strlen(s);p++)
    {
        if(s[p]=='.')
        {
            break;
        }
        ansA*=3;
        if(s[p]=='1')
        {
            ansA+=1;

        }
        else if(s[p]=='2')
        {
            ansA-=1;
        }

    }
    p++;
    for(;p<strlen(s);p++)
    {
        ansB*=3;
        if(s[p]=='1')
        {
            ansB+=1;
        }
        else if(s[p]=='2')
        {
            ansB-=1;
        }
        ansC*=3;
    }
    if((ansA>0||ansA<0)&&ansB<0)
    {
        ansA--;
        ansB=ansC+ansB;
    }
    else if(ansA<0&&ansB>0)
    {
        ansA++;
        ansB=ansC-ansB;
        if(ansA==0)
        {
            ansB=-ansB;
        }
    }
    if(ansB==0)
    {
        printf("%lld\n",ansA);
    }
    else{

    long long int t=GCD(abs(ansB),abs(ansC));
        if(ansA!=0)
        {
            printf("%lld ",ansA);
        }
        printf("%lld %lld\n",ansB/t,ansC/t);
    }
    return 0;
}
