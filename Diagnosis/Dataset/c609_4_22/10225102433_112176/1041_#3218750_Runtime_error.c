#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char s[17];
}node;

char *trans(char *s)
{
    int cnt = 0;
    int a[128] = {0};
    while(*s)
    {
        a[*s++]++;
    }
    for(int i = 0; i < 128;i++)
    {
        if(a[i] != 0)
        {
            char c = i;
            s[cnt++] = c;
        }
    }
    s[cnt] = '\0';
    return s;
}

int cmp(const void *a,const void *b)
{
    return strcmp(((node*)a)->s,((node*)b)->s);
}

int main()
{
    int n;scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        printf("case #%d:\n",i);
        char s[20] = {0};
        scanf("%s",s);
        char *k = trans(s);
        int len = strlen(k);
        int num1 = (int)pow(2,len)-1;
        node ch[num1];
        memset(ch,'\0',sizeof(ch));
        int num = (1<<len)-1;
        for(int j = 1;j <= num;j++)
        {
            int p = j;
            int ans = 0;
            char res[17] = {0};
            for(int h = 0;h < len;h++)
            {
                if(p&1)
                    res[ans++] = k[h];
                p = p>>1;
            }
            strcpy(ch[j-1].s,res);
        }
        qsort(ch,num1,sizeof(ch[0]),cmp);
        for(int j = 0;j < num1;j++)
        {
            printf("%s\n",ch[j].s);
        }
    }
    return 0;
}