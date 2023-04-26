#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int T,j,i,n;int digit[31],maxlen=0,len=1;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        printf("case #%d:\n",i);
        scanf("%d",&n);
        for(j=0;n>0;j++)
        {
            digit[j]=n%2;
            n/=2;
            if(j!=0)
            {
                if(digit[j]!=digit[j-1])
                {
                    len=len+1;
                    if(maxlen<len)maxlen=len;
                }
                 else len=2;
                
            }
        }
        printf("%d\n",maxlen);
    }
}