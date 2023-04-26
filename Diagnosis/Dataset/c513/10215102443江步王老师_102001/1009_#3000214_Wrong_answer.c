#include<stdio.h>

int main()
{
    int t;
    scanf("%d\n",&t);

    for (int i=0;i<t;++i)
    {
        char s[121];
        gets(s);
        int cnt=0;
        int cnt_one=0;
        char *p=s;

        while (*p)
        {
            cnt+=8;
            int temp=1;
            int j=0;
            while (j<8)
            {
                if (temp&(*p))
                {
                    cnt_one++;
                }
                temp=temp<<1;
                j++;
            }
            p++;
        }

        int r;
        while(1)
        {
            r=cnt%cnt_one;
            if (!r) break;

            cnt=cnt_one;
            cnt_one=r;
        }

        printf("%d/%d",cnt_one,cnt);
        putchar('\n');
    }

    return 0;
}