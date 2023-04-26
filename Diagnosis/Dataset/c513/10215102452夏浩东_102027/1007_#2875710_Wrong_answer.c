#include <stdio.h>
#include <math.h>
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        int num=0;
        int k=0,res=1,result=1;
        int L[32];
        scanf("%d",&num);
        while(num>0)
        {
            L[k]=num%2;
            num=num/2;
            k++;
        }
        for(int t=0;t<k;t++)
        {
            if(L[k]!=L[k+1]) res++;
            else
            {
                result=result>res ? result:res;
                res=1;
            }
        }
        result=result>res? result:res;
        printf("case #%d:\n",i);
        printf("%d\n",result);
    }
    return 0;
}