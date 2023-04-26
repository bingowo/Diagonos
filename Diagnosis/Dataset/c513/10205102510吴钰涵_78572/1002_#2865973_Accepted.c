#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for (int n=0;n<T;n++)
    {
        char s[61]; //输入一个表示神秘信息的字符串
        scanf("%s",s);
        int a[128]; //储存每一个元素的对应值
        for(int i=0;i<128;i++)
            a[i]=-1; //对每一个元素赋值为-1
        int digit=0,N=1;
        char *p=s; //指针指向数组首地址
        a[*p]=1; //第一位不能使0，所以从1开始值最小
        while(*++p) //指针下移
        {
            if(a[*p]==-1) //指针所指向的元素没有被赋值
            {
                a[*p]=digit;
                digit=digit?digit+1:2; //如果digit=0，则加2；否则加1
                N++; //计算数组长度（记录进制）
            }
        }
        if(N<2) //只有一位，只能二进制（不可能是一进制）
            N=2;
        long long int plus=0;
        p=s;
        while(*p)
            plus=plus*N+a[*p++];
        printf("case #%d:\n",n);
        printf("%lld\n",plus);
    }
    return 0;
}