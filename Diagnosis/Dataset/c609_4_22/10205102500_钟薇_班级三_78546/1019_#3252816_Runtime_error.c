#include<stdio.h>
#include<stdlib.h>
int main()
{
    long long int num[10000];
    long long int bit[10000];
    int i;

    char y;
    do
    {
        scanf("%lld",&num[i]);
        int temp=abs(num[i]);
        bit[i]=0;
        while (temp!=0)
        {
            temp=temp/10;
            bit[i]++;
        }        
        i++;
    } while (y=getchar()!='\n');

    int flag=0;
    int j;
    while (flag==0)
    {
        flag=1;
        for(j=0;j<i-1;j++)
        {
            if(bit[j]<bit[j+1])
            {
                int temp=bit[j];
                bit[j]=bit[j+1];
                bit[j+1]=temp;

                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;

                flag=0;
            }
        }
    }

    flag=0;
    while (flag==0)
    {
        flag=1;
        for(j=0;j<i-1;j++)
        {
            if(bit[j]==bit[j+1] && num[j]>num[j+1])
            {
                int temp=bit[j];
                bit[j]=bit[j+1];
                bit[j+1]=temp;

                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;

                flag=0;
            }
        }
    }
    for(j=0;j<i-1;j++)    printf("%lld ",num[j]);
    printf("%lld",num[i-1]);
    return 0;
}