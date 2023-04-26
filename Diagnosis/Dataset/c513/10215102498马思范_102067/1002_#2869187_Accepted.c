#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a;
    scanf("%d",&a);
    for(int j=0;j<a;j++)
    {
        char s[70];
        scanf("%s",s);
        int a[123];
        for(int q=0;q<123;q++)
        {
            a[q]=-1;
        }
        int x=0;
        char*k=s;
        a[*k]=1;
        int jz=1;
        while(*k)
        {
            if(a[*k]==-1)
            {
                a[*k]=x;
                if(x==0)
                    x=2;
                else
                    x++;
                    jz++;
            }
            *k++;
        }
        if(jz<2) jz=2;
        long long int sum=0;
       k=s;
       while(*k)
       {
           sum=sum*jz+a[*k++];
       }
        printf("case #%d:\n",j);
        printf("%lld\n",sum);
    }
    return 0;
}
