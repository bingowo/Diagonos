#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a, const void*b)
{
    char c = *(char*)a;
    char d = *(char*)b;
    if(c<d)return -1;
    else return 1;
}

int main()
{
    int cas,i,j,k;
    char s[27],ss[27],ch,d;
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)
    {
        scanf("%s",s);
        int len = strlen(s);
        memset(ss,0,sizeof(ss));
        k = 26;
        ss[k--] = '\0';
        for(j = len-1; j > 0; j--)
        {
            if(s[j] <= s[j-1]){ss[k--] = s[j];}
            else {ss[k--] = s[j];ch = s[j-1];break;}
        }
        //qsort(ss,k,sizeof(ss[0]),cmp);
        if(j != 0)
        {
            d = ch;
            ch = ss[k+1];
            ss[k+1] = d;
            s[j-1] = '\0';
            printf("case #%d:\n%s%c%s\n",i,s,ch,ss+k+1);
        }
        else if(j == 0)
        {
            ss[k] = s[0];
            ch = ss[k];
            ss[k] = '0';
            printf("case #%d:\n%c%s\n",i,ch,ss+k);
        }
    }
    return 0;
}