#include <stdio.h>
#include <math.h>

int main()
{
    int a;
    while(scanf("%d",&a))
    {
        if(!a)
            return 0;
        double f=a*log10(a);
        f=f-(int)f;
        int b=pow(10,f);
        printf("%d\n",b);
    }
}
// 关键是运用数学知识，提出小数部分，大大简便了运算！
