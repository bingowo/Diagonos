#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{

    int T;
    scanf("%d",&T);
    getchar();
    for(int i=0;i<T;i++)
    {
        long long int n,maxlen=1,len;
        long long int a[100],b[100],h=0;
        scanf("%lld",&n);
        int j=0;
        while(n)
        {
            a[j]=n%2;
            n=n/2;
            j+=1;
        }

        long long int* p1,*p2;
        p1=a;
        p2=a;
        for(int k=0;k<j-1;k++)
        {
            p2++;
            if((*p2)==*(p2-1))
            {
                len=p2-p1;
                if(len>maxlen)maxlen=len;
                p1=p2;
            }
        }
        len=p2-p1+1;
        if(len>maxlen)maxlen=len;
        printf("case #%d:\n%lld\n",i,maxlen);
    }
    return 0;
}
