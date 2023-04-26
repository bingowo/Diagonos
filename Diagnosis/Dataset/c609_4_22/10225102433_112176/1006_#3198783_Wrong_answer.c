#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    char c;
    long long int a;
    int sig;
}node;

int main()
{
    int n;scanf("%d",&n);
    int hh;hh = getchar();
    for(int i = 0;i < n;i++)
    {
        printf("case #%d:\n",i);
        node ch[61];
        memset(ch,0,sizeof(ch));
        char c;
        int cnt = 0;
        while(1)
        {
            c = getchar();
            if(c == '\n')
                break;
            ch[cnt++].c = c;
        }
        int cnt2 = 0;
        for(int j = 0;j < cnt;j++)
        {
            if(ch[j].c == ch[0].c)
            {
                ch[j].a = 1;
                ch[j].sig = 1;
            }
        }
        for(int j = 1;j < cnt;j++)
        {
            if(ch[j].sig == 0)
            {
                ch[j].a = cnt2++;
                ch[j].sig++;
                if(cnt2 == 1)
                    cnt2++;
                for(int k = j+1;k < cnt;k++)
                {
                    if(ch[k].c == ch[j].c){
                        ch[k].a = ch[j].a;
                        ch[k].sig++;
                    }
                }
            }
            else
                continue;
        }//cnt2进制
        if(cnt2 <= 1)
            cnt2 = 2;
        unsigned long long re = 0;
        for(int j = 0;j < cnt;j++)
        {
            int k = cnt-j-1;
            unsigned long long ak = cnt2;
            for(int l = 1;l < k;l++)
            {
                ak *= cnt2;
            }
            re += ch[j].a*ak;
        }
        printf("%llu\n",re);
    }

    return 0;
}