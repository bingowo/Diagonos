#include <stdio.h>

int main()
{
    int T,i=0,j=0;
    scanf("%d",&T);//问题数

    for(;i<T;i++)
    {
        char s[61];
        scanf("%s",s);//输入字符串
        int a[128];
        for (;j<128;j++)
            a[j] = -1;
       int digit = 0 , N = 1;
       char *p = s;
       a[*p] = 1;
       while(*++p)
       {
           if(a[*p] == -1)
           {
               a[*p] = digit;
               digit = digit ? digit + 1 : 2;//第一位是1，第二位是0，第三位开始从2递增
               N++;
           }
       }
       if(N<2)
            N=2;

       long long int ans = 0;
       p = s;
       while(*p)
            ans = ans*N + a[*p++];

    printf("case #%d:\n",i);
    printf("%lld\n",ans);

    }

}
