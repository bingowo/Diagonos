#include <stdio.h>

int main()
{
    int t , i;
    long long ans = 0;
    scanf("%d",&t);
    for(int j = 0; j < t; j++)
    {
        char s[60];
        int tmp = 0 , n =1;
        scanf("%s",s);//输入神秘信息
        int a[128];//对应128个ascii表里的字符
        for(i = 0; i<128; i++)  a[i] = -1;//对数组初始化
        char *p = s;//使指针的地址值与s相同
        a[*p] = 1;//第一位是1
        while(*++p)//如果p的后一位有意义
        {
            if(a[*p] == -1)
            {
                a[*p] = tmp;
                if(tmp == 0)    tmp = 2;//第二位为0
                else tmp++;
                n++;//记录进制
            }
        }

        if(n < 2)   n = 2;//至少是二进制

        p = s;//修改p的地址
        while(*p)   ans = ans * n + a[*p++];

        printf("case #%d:\n", j);
        printf("%lld\n",ans);
    }



}
