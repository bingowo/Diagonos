#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,n,q;
    scanf("%d",&T);
    int a[2000]={0};
    for(int i=0;i<T;i++)
    {
        scanf("%d",&n);
        for(q=0;n!=0;q++)
        {
            a[q]=n%2;
            n=n/2;
        }
        int length=1;
        int max=1;
        for(int i=1;i<q;i++)
        {
            if(a[i]!=a[i-1])
                length++;
            else
            {
                if(a[i]==0)
                    length=1;
                else length=1;
            }
            if(max<length)
                max=length;
        }
        printf("case #%d:\n",i);
        printf("%d\n",max);
    }
    return 0;
}
