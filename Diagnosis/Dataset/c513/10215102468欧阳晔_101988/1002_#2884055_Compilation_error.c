#include <stidio.h>
int main()
{
    int T;
    scanf("%d", &T);
    for(int cas=0; cas < T; cas++)
    {
        char s[61];
        scanf("%s", s);  //输入
        int a[128];
        for(int i=0; i < 128; i++)
        int R=0;
        char *p=s;   //指针指向字符串第一个字母
        a[*p]=1;
        while(*++p)
            if(a[*p]==-1)
            {
                a[*p]=R;
                R=R?R+1:2;   //这几步不太懂，是老师的解答
            }
        if (R<2) R=2;
        long long N=0;
        p=s;
        while(*p)
            N=N*R+a[*p++];
        printf("case #%d:\n%lld\n", cas, N);
    }
    return 0;
}
