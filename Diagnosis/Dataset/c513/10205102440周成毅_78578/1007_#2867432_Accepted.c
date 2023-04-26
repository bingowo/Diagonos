#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main()
{
    int T;int num;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d",&num);
        int *p;
        p = (int *)malloc(sizeof(int)*32);
        for(int j=0;j<32;j++)
            p[j]=0;
        int k=31;
        while(num)
        {
            p[k--] = num%2;
            num=num/2;

        }
        int length=0;
        int temp=1;
        int l=0;
        while(p[++l]==0) ;
        for(;l<31;l++)
        {
            if(p[l]!=p[l+1])
                temp++;
            else
            {
                if(temp>length)
                {
                    length=temp;
                }
                temp=1;
            }
        }
        if(temp>length)
            length=temp;
        printf("case #%d:\n%d\n",i,length);
        free(p);
    }
    return 0;
}