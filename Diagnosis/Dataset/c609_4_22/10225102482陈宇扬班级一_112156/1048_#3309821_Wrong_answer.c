#include <stdio.h>
#define LL long long
LL f_arr(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    else
    {
        LL a0 = 0;
        LL a1 = 1;
        LL a2 = 0;
       while(n >= 2)
       {
           a2 = a1 + a0;
           a0 = a1;
           a1 = a2;
           n--;
       }
        return a2;
    }

}
int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        //输入
        int n;
        scanf("%d", &n);

        //输出
        printf("case #%d:\n", i);
        printf("%lld", f_arr(n));
        printf("\n");
    }
    return 0;
}
