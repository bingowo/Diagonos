#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T,i;
    scanf("%d ",&T);
    for(i=0;i<T;i++)
    {
        char c[1000];
        scanf("%s",c);
        int j,k,l1,l=0;
        j=strlen(c)-1;
        for(;j>=0;j--)
        {
            l1=0;
            for(k=j-1;k>=0;k--)
            {
                if(c[j]==c[k])
                l1=l1+1;
            }
            if(l1==0)
                l=l+1;//计算一共有多少个不同的字符，也就是多少进制
        }      //最终可知要想要最小，需要是l进制
        if(l<2)
            l=2;//比如1111这种，因为我们没有1进制，所以算2进制
        char* p=c;
        int a[127];//ASCII中一共有128个字符，我们让每一个字符所代表的整数对应的数组的值都等于-1，然后再让输入的字符串的数组对应的值改变
        int m,n=0;
        for(m=0;m<128;m++)
            a[m]=-1;
        a[*p]=1;
        while(*++p)
        {
            if(a[*p]==-1)
                {
                    a[*p]=n;
                    n=n?n+1:2;//因为1已经被a[*p]占了，所以之后是0,2,3这样排，如果n非零，就加1，如果为0，就变成2
                }
        }
        long long int smsz=0;
        p=c;
        while(*p)
            smsz=smsz*l+a[*p++];
        printf("case #%d:\n%lld\n",i,smsz);
    }
}
