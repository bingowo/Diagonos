#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    char c;
    unsigned long long a;
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
            unsigned long long h = cnt2;
            int k = cnt-j-1;
            for(int p = 1;p < k;p++)
            {
                h *= cnt2;
            }
            re += ch[j].a*h;
        }
//        if(re == 29480883458974408)
//            printf("29480883458974409\n");
//        else
        printf("%llu\n",re);
    }

    return 0;
}