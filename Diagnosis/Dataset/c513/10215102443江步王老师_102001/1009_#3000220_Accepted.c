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
        int t1=cnt,t2=cnt_one;
        while(1)
        {
            r=t1%t2;
            if (!r) break;

            t1=t2;
            t2=r;
        }
        cnt/=t2;cnt_one/=t2;
        printf("%d/%d",cnt_one,cnt);
        putchar('\n');
    }

    return 0;
}