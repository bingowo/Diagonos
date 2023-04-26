#include <stdio.h>

main()
{
    char s[80] = {};
    scanf("0x%s",s);
    int stack[2000] = {0};
    int m = 0,n;
    for (n=strlen(s)-1;n>=0;n--)
    {
        int p = (s[n]>='0'&&s[n]<='9')?s[n]-'0':s[n]-'A'+10;
        for (int j=0;j<4;j++)
        {
            stack[m++] = p&1;
            p >>= 1;
        }
    }

    unsigned long long r=0, i=0, a=0, b=0, c=-1, d=1;
    while (m>0)
    {
        r = a*c-b*d+stack[--m];
        i = a*d+b*c;
        a = r, b = i;
    }
    if (i==0) printf("%llu\n",r);
    else if (r==0&&i==1) printf("i\n");
    else if (r==0&&i==-1) printf("-i\n");
    else if (i==1||i==-1) printf("%llu%ci\n",r,i>0?'+':'-');
    else if (r==0) printf("%di\n",i);
    else printf("%llu%c%llui\n",r,i>0?'+':'-',i>0?i:-i);
    return 0;
}