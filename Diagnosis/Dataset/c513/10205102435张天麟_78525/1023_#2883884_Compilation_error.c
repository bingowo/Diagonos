#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    char s[31];
    int val;
}tss;
int cmp(const void *a,const void *b)
{
    int vala=((tss*)a)->val,valb=((tss*)b)->val;
    if(vala!=valb)return vala-valb;
    else
    {
        return strcmp(((tss*)a)->s,((tss*)b)->val);
    }
}
int main()
{
    tss all[101];
    int n=0;
    while(scanf("%s",all[n].s)!=EOF)
    {
        n++;
    }
    int i,j;
    for(i=0;i<n;i++)
    {
        all[i].val=-1;
        for(j=0;j<strlen(all[i].s);j++)
        {
            char c=all[i].s[j];
            int val=-1;
            if(c>='0'&&c<='9')
            {
                val=c-'0';
            }
            if(val!=-1)
            {
                j++;
                c=all[i].s[j];
                while(c>='0'&&c<='9')
                {
                    val*=10;
                    val+=c-'0';
                    j++;
                    c=all[i].s[j];
                }
                all[i].val=val;
            }
        }
    }
    qsort(all,n,all[0],cmp);
    for(i=0;i<n;i++)
    {
        printf("%s ",all[i].s);
    }
    return 0;
}