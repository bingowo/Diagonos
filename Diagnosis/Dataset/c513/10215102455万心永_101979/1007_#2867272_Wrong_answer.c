#include<stdio.h>

void binary(int a);

int main()
{
    int n,a;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {   scanf("%d",&a);
        printf("case #%d:\n",i);
        binary(a);
    }
    return 0;
}

void binary(int a)
{
    
    char b[32];
    int r=0,i=0;
    do
    {
        r=a%2;
        a=a/2;
        b[i]=r+'0';
        i++;
    }   while(a!=0);
    int count1=0,count2=0;
    for (int j=0;j<i;)
    {
        int k=j;
        for (;k<i;k++)
        {
            if (b[k]==b[k+1])
                break;
            count1++;
        }
        if (count1>count2)
        {
            count2=count1;
            count1=0;
        }
        j=k+1;
    }
    printf("%d\n",count2);
    
}