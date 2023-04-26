#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char s[200];
    int s1[200];
    int res[200];
    int length;
    int n;
} r;
int cmp(const void*p1,const void*p2)
{
    r p_1 =*(r*)p1;
    r p_2 =*(r*)p2;
    if(p_1.n>p_2.n) return 1;
    else if(p_1.n ==p_2.n)
    {
        for(int i=0;i<p_1.length;i++)
        {
            if(p_1.res[i]>p_2.res[i])return 1;
            else if(p_1.res[i]<p_2.res[i])return -1;
        }
        return strcmp(p_1.s,p_2.s);
    }
    else return -1;

}
int main()
{
    int t ;
    scanf("%d",&t);
    r* anw = (r*)malloc(sizeof(r)*20000);
    for(int k=0;k<t;k++)
    {
    memset(anw[k].res,0,sizeof(anw[k].res));
    memset(anw[k].s1,0, sizeof(anw[k].s1));
    scanf("%s",anw[k].s);
    anw[k].n=0;
    anw[k].length =0;
    int n =0;

    for(int i=0;i<strlen(anw[k].s);i++)
    {
        if(anw[k].s1[anw[k].s[i]]==0)
        {
            anw[k].n++;
            if(i==0)anw[k].s1[anw[k].s[i]] = 1;
            else if(anw[k].n==2)anw[k].s1[anw[k].s[i]] = anw[k].n-2;
            else anw[k].s1[anw[k].s[i]]=anw[k].n-1;
        }
        anw[k].res[anw[k].length] = anw[k].s1[anw[k].s[i]];
        anw[k].length++;
    }

    }
   qsort(anw,t,sizeof(r),cmp);
//   printf("\n");
    for(int z=0;z<t;z++)
    {
        printf("%s\n",anw[z].s);
    }
    free(anw);
    return 0;
}
