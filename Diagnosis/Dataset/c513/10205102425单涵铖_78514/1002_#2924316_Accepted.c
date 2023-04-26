#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
未来的某一天，人类登陆火星。在火星上发现一组由各种符号表示的神秘信息。研究发现：每种符号表示一个数码，神秘信息是一个整数。

但是不知道每个符号表示的是哪个数码，也不知道它是几进制数 (只知道不可能是一进制)，但知道相同的符号表示相同的数码，不同的符号表示不同的数码。

符号总计有 62 种，为方便起见，每种符号分别用大小写英文字母和数字 0-9 表示。

现在我们想要知道神秘信息表示的最小整数值。

例如 :

11001001 最小整数值和人类的二进制数一样，为 201；

cats 最小整数值为 75(设是 4 进制数，c 表示 1，a 表示 0，t 表示 2，s 表示 3)；

pig 最小整数值为 11(设是 3 进制数，p 表示 1，i 表示 0，g 表示 2)。

注意：神秘信息表示的数必须是有意义的，第一位不能为 0。
*/

typedef struct{
    char s[61];long long int res;
}Data;

int main()
{
    int n;
    scanf("%d",&n);
    Data S[11];

    for(int i = 0;i<n;i++)
    {
        scanf("%s",&S[i].s);
    }

    for(int i=0;i<n;i++)
    {
        int num[128];
        for(int j=0;j<128;j++)
        {
            num[j] = -1;
        }//初始化该字符串中每个字符所对应的数字；√

        int k = strlen(S[i].s);   //k为该字符串中的字符个数;√

        char *p=S[i].s;
        int digit = 0,N=1;
        num[*p]=1;
        while (*++p)
        {
            if (num[*p]==-1)
            {
                num[*p] = digit;
                digit = digit ? digit+1:2 ; N++;
            }
        }
        if(N<2) N=2;

        S[i].res = 0;
        p = S[i].s;
        while(*p)   S[i].res = S[i].res * N + num[*p++];
    }

    for(int i=0;i<n;i++)
    {
        printf("case #%d:\n",i);
        printf("%lld\n",S[i].res);
    }
    return 0;
}

