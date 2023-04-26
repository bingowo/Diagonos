#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A,B,i,s[32];char n[32];
    long long sum=0;
    char table_1[]="0123456789ABCDEF";
    char table_2[]="0123456789abcdef";
    scanf("%d%s%d",&A,n,&B);
    for(i=1;n[i]!='\0';i++);//i是数组n的长度
    for(int k=0;k<i;k++)
    {
        if(n[k]>=97)
        {
            for(int j=0;j<17;j++)
            {
                if(n[k]==table_2[j])
                    n[k]=j;
                else break;
            }
        }
        else
        {
            for(int m=0;m<17;m++)
            {
                if(n[k]==table_1[m])
                    n[k]=m;
                else
                    break;
            }
        }
    }
    printf("%s\n",n);
    char *p=n;
    while(*p)
    {
        sum=sum*A+n[*p++];
    }
    int t=0;
    do{
        s[t++]=sum%B;
        sum/=B;
    }while(sum);
    for(int t=t-1;t>=0;t--)
    {
        printf("%d",s[t]);
    }
    return 0;
}
