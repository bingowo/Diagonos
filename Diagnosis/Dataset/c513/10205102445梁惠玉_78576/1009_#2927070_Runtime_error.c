#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GCD(int a,int b)
{
    int max=b;
    int min=a;
    while(max%min)
    {
        int temp=max%min;
        max=min;
        min=temp;
    }
    return min;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[121];
        scanf("%*[\n]", s);
        int ansA=0,ansB=0;
        for(int j=0;j<strlen(s);j++)
        {
            ansA+=8;
            unsigned char ch=s[j];
            for(int k=0;k<8;k++)
            {
                ansB+=ch%2;
                ch>>=1;
            }
        }
        int t=GCD(ansB,ansA);
        printf("%d/%d\n",ansB/t,ansA/t);
    }
}
