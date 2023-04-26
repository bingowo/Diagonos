#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    int T;
    scanf("%d",&T);
    int x=0;
    for(int i=0;i<T;++i)
    {
        int M;
        char s[2001];
        scanf("%d",&M);
        gets(s);
        printf("case #%d:\n",i);
        int len=strlen(s);
        int wd_len,wd_cnt,sp_num;
        int bg,j;
        for(j=0;j==' ';++j);
        while(j<len)
        {
            bg=j;
            wd_len=0;
            wd_cnt=0;
            for(;wd_len+wd_cnt<=M&&j<len;)
            {
                int l,p;
                for(l=0,p=j;s[p]!=' '&&p<len;++p,++l);
                if(wd_len+wd_cnt+l<=M)
                {
                    wd_len+=l;
                    wd_cnt++;
                    for(j=p;s[j]==' ';++j);
                }
                else break;
            }
            sp_num=M-wd_len;
        int k=bg;
        wd_cnt--;
        while(k<j)
        {
            while(s[k]!=' '&&k<len) putchar(s[k++]);
            while(s[k]==' '&&k<len) k++;
            if(j==len&&wd_cnt) putchar(' ');
            else
            {
                int p;
                for(p=0;wd_cnt&&p<sp_num/wd_cnt;++p)
                {
                    putchar(' ');
                }
                sp_num-=p;
            }
            wd_cnt--;
        }
        putchar('\n');
        }
    }
    return 0;
}
