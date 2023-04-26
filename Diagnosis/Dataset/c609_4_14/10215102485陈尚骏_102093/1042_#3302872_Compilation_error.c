#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve()
{
    char s[2001];
    int M,i=0,j,p,l,wd_len,wd_cnt,sp,bg,len;
    scanf("%d ",&M);
    gets(s);
    len=strlen(s);
    while(i<len)
    {
        while(s[i]==' ')
            i++;
        bg=i;
        wd_cnt=0,wd_len=0;
        while(wd_cnt+wd_len<=M)
        {
            for(p=i,l=0;s[p]!=' '&&p<len;p++,l++);
            if(wd_cnt+wd_len+l<=M)
            {
                wd_cnt++;
                wd_len+=l;
                for(i=p;s[i]==' '&&i<len;i++);
            }
            else
                break;
        }
        sp=M-wd_len;
        j=bg;
        wd_cnt--;
        while(j<i)
        {
            while(s[j]!=' '&&j<i)
                putchar(s[j++]);
            for(;str[j]==' '&&j<i;j++);
            if(i==len&&wd_cnt)
                putchar(' ');
            else
            {
                for(p=0;wd_cnt&&p<sp/wd_cnt;p++)
                    putchar(' ');
                sp-=p;
            }
            wd_cnt--;
        }
        printf("\n");
    }
}


int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        solve();
    }
}

