#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int length;
    char s[15];
}WORD;

int cmp(const void*pa,const void*pb)
{
    WORD a=*(WORD*)pa,b=*(WORD*)pb;
    return b.length-a.length;
}

int main()
{
    int n=0,l=0;
    scanf("%d",&n);
    WORD alpha[4000]={0,{0}};
    for(int i=0;i<n;i++)
    {
        scanf("%s",alpha[i].s);
        alpha[i].length=strlen(alpha[i].s);
    }
    qsort(alpha,n,sizeof(alpha[0]),cmp);
    char s[5001]={0};
    scanf("%s",s);
    char r[10000]={0};
    for(int i=0;i<strlen(s);)
    {
        int sign=0;//标识有没有分割出完整单词
        for(int t=0;t<n;t++)
        {
            for(int j=i,m=0;j<i+alpha[t].length;j++,m++)
            {
                if(s[j]!=alpha[t].s[m]) break;
                else if(m+1==alpha[t].length&&s[j]==alpha[t].s[m])
                {
                    strcat(r,alpha[t].s);
                    strcat(r," ");
                    sign=1;
                    i=i+alpha[t].length;
                }
            }
            if(sign) break;
        }
        if(sign==0)
        {
            r[strlen(r)]=s[i];
            strcat(r," ");
            i+=1;
        }
    }
    r[strlen(r)]=0;
    printf("%s",r);
    return 0;
}