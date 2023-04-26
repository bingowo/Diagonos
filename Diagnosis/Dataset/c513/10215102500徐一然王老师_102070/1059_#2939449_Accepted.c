#include <stdio.h>
#include <stdlib.h>

int GCD(int a,int b)
{
    int temp;
    if(a<b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    while(b!=0)
    {
        temp=a%b;
        a=b;b=temp;
    }
    return a;
}

int main()
{
    int n,s,min=9999999;
    int A[2000];
    int flag=0,count=0,count1=0;
    int temp;
    scanf("%d %d",&n,&s);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
        if(min>A[i])
        {
            min=A[i];
        }
    }
    while(s)
    {
        for(int j=0;j<n&&s>0;j++)
        {
            if(A[j]==min)
            {
                A[j]++;
                s--;
                count++;
            }
        }
        if(s!=0)
        {
            count=0;
        }
        min++;
    }

    for(int j=0;j<n;j++)
        {
            if(A[j]<min)
            {
                flag=1;
                count++;
                count1++;
            }
        }

    if(flag==0)
    {
        printf("%d",min);
    }
    else
    {
        if(min-1==0)
        {
            temp=GCD(count,count-count1);
            printf("%d/%d",(count-count1)/temp,count/temp);
        }
        else
        {
            printf("%d+",min-1);
            temp=GCD(count,count-count1);
            printf("%d/%d",(count-count1)/temp,count/temp);
        }

    }

}
