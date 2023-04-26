#include<stdio.h>

int main()
{
    int count,count1,num=1,max=1;
    long long int x;
    int A[32];
    int *p=A;
    scanf("%d",&count);
    count1=count;
    while(count--)
    {
        scanf("%d",&x);
        for(int i=0;i<32;i++)A[i]=-1;
        while(x)
        {
            if(x%2==1)
            {
                *p=2;
            }
            else
            {
                *p=1;
            }
            x=x/2;
            p++;
        }
        p=A;
        while(*p)
        {
            if(*p!=*(p+1)&&(*(p+1)!=-1))
            {
                num++;
            }
            else if(max<num)
            {
                max=num;num=1;
            }
            else
            {
                num=1;
            }
            p++;
        }
        printf("case #%d:\n",count1-count-1);
        printf("%d\n",max);
        num=1;
        max=1;
        p=A;

    }
}