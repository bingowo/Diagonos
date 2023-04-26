#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char s[200];
    int s1[200];
    unsigned long long res;
} r;
int cmp(const void*p1,const void*p2)
{
    r p_1 =*(r*)p1;
    r p_2 =*(r*)p2;
    if(p_1.res>p_2.res) return 1;
    else if(p_1.res ==p_2.res)return strcmp(p_1.s,p_2.s);
    else return -1;

}
int main()
{
    int t ;
    scanf("%d",&t);
    r* anw = (r*)malloc(sizeof(r)*20000);
    for(int k=0;k<t;k++)
    {
    anw[k].res =0;
    memset(anw[k].s1,0, sizeof(anw[k].s1));
    scanf("%s",anw[k].s);
    int n =0;
    for(int i=0;i<strlen(anw[k].s);i++)
    {
        if(anw[k].s1[anw[k].s[i]]==0)
        {
            n++;
            if(i==0)anw[k].s1[anw[k].s[i]] = 1;
            else if(n==2)anw[k].s1[anw[k].s[i]] = -1;
            else if(n>2)anw[k].s1[anw[k].s[i]]=n-1;
        }
    }
    for(int q=0;q<strlen(anw[k].s);q++)
    {
        int mid = anw[k].s1[anw[k].s[q]];
        if(mid == -1)mid+1;
        anw[k].res = anw[k].res*n+mid;
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
