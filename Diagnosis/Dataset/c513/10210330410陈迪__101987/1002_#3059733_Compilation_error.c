#include <stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0; cas<T; cas++)
    {
        char s[61]; scanf("%s",s);
        int a[128]; for(int i=0; i<128; i++) a[i]=-1;
        int R=0;
        char *p=s;  //指针p指向字符串第一个字符
        a[*p]=1;    //左边第一次字符对应数码为1
        while (*++p)
            if(a[*p]==-1)
            {
                a[*p]=R;
                R=R?R+1:2;
            }
        if (R<2)  R=2; //不可能是一进制
        long long N=0;
        p=s;
        while(*p)       //霍纳规则计算多项式
            N=N*R+a[*p++];
        printf("case #%d:\n%lld\n",cas,N);
    }
    return 0;
}
}