#include<stdio.h>
int main()
{
    int n;
    long long exchange[32];
    scanf("%d",&n);
    int i,j,index;
    for(i=0;i<n;i++)
    {
        unsigned long long num;
        j=0;
        scanf("%llu",&num);
        if(num==0)
        {
            exchange[0]=0;
            j=1;
        }
        while(num!=0)
        {
            exchange[j]=num%2333;
            num=num/2333;
            j++;
        }
        for(index=j-1;index>=0;index--)
        printf("%d ",exchange[index]);
        printf("\n");
    }
    return 0;
}