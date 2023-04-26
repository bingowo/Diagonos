#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        char s[61];scanf("%s",s);
        int a[128];for(int i=0;i<128;i++)
            a[i]=-1;
        nt R=0;
        char *p=s;
        a[*p]=1;
        while(*++p)
            if(a[*p]==-1)
            {
                a[*p]=R;
                R=R?R+1:2;
            }
        if(R<2) R=2;
        long long N=0;
        p=s;
        while(*p)
            N=N*R+a[*p++];
        printf("case #%d:\n%lld\n",cas,N);
    }
    return 0;
}
//给每一个新出现字符赋值，字符对应ascii码值初始全部赋值’-1’
//扫描到新字符后+1重新赋值