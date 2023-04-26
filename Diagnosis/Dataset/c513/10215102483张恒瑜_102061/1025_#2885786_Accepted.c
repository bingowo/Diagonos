#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    char ch[110];
    int cnt;
}STR;

int cmp(const void* a, const void* b)
{
    STR a0=*(STR*)a;STR b0=*(STR*)b;
    if(a0.cnt==b0.cnt) return strcmp(a0.ch,b0.ch);
    else return b0.cnt-a0.cnt;
}

int main()
{
    int T,t=0;
    scanf("%d",&T);
    while (T--)
    {
        int i,num;
        scanf("%d",&num);
        STR str[num];
        for(i=0;i<num;i++)
        {
            str[i].cnt=0;
            scanf("%s",&str[i].ch);
            int j;
            for(j=0;j<strlen(str[i].ch);j++)
            {
                int p,flag=0;
                for(p=0;p<j;p++)
                    if(str[i].ch[j]==str[i].ch[p])
                    {
                        flag=1;
                        break;
                    }
                if(flag==0) str[i].cnt++;
            }
        }
        qsort(str,num,sizeof(str[0]),cmp);
        printf("case #%d:\n",t);
        for(i=0;i<num;i++) printf("%s\n",str[i].ch);
        t++;
    }
    return 0;
}
