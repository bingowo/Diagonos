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
        for(j = len-1,k = 0; j > 0; j--)
        {
            if(s[j] <= s[j-1]){ss[k++] = s[j];}
            else
                {
                    ss[k++] = s[j-1];
                    ch = s[j];
                    break;
                }
        }
        ss[k] = '\0';
        if(j != 0)
        {
            s[j-1] = '\0';
            qsort(ss,k,sizeof(ss[0]),cmp);
            printf("case #%d:\n%s%c%s\n",i,s,ch,ss);
        }
        else if(j == 0)
        {
            ch = s[0];
            ss[k] = '0';
            ss[k+1] = '\0';k++;
            qsort(ss,k,sizeof(ss[0]),cmp);
            printf("case #%d:\n%c%s\n",i,ch,ss);
        }
    }
    return 0;
}