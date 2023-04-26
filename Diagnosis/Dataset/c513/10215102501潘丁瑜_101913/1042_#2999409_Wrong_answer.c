#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct str
{
    char s[20];
};

int scmp(const void *a,const void *b)
{
    char *m = (char *)a;
    char *n = (char *)b;
    return strcmp(m,n);
}

int Scmp(const void*a,const void*b)
{
    struct str *m = (struct str *)a;
    struct str *n = (struct str *)b;
    return strcmp(m->s,n->s);
}

int main()
{
    char s1[20]={0};
    int N;
    int len,t;
    char ch;
    int i,j=0,k=0;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        char s[20]={0};
        char a[2]={0};
        char temp[200]={0};
        scanf("%s",s1);
        //ÅÅÐò
        len = strlen(s1);
        qsort(s1,len,sizeof(s1[0]),scmp);
        //È¥ÖØ
        for(j=0;j<len;j++)
        {
            ch = s1[j];
            a[0] = s1[j];
            if(temp[ch] == 0)
                strcat(s,a);
            temp[ch] = '1';
        }

        printf("case #%d:\n",i);
        struct str S[100000]={0};
        int r=0;
        for(j=0;j<len;j++)
        {
            a[0]=s[j];
            strcpy(S[r].s,a);
            for(t=r;t>=0;t--)
            {
                if(s[j+1])
                {
                    a[0] = s[j+1];
                    strcpy(S[++r].s,S[t].s);
                    strcat(S[r].s,a);
                }
            }
            //if(s[j+2])
                r++;
        }
        qsort(S,r,sizeof(S[0]),Scmp);
        //j++;
        k=0;
        while(S[k].s[0])
            printf("%s\n",S[k++].s);
    }
    return 0;
}