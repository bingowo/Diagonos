#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct{int num,ss[107];}jihe;

int cmp(const void*a,const void*b)
{
    jihe c = *(jihe*)a;
    jihe d = *(jihe*)b;
    return d.num-c.num;
}

int cmp2(const void*a,const void*b)
{
    int c = *(int*)a;
    int d = *(int*)b;
    return c-d;
}

int main()
{
    int cas,i,j,k,h,g,r = 0;
    jihe s[107];
    int str[107],ans[107][107];
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)
    {
        scanf("%d",&s[i].num);
        for(j = 0; j < s[i].num; j++)scanf("%d",&str[j]);
        qsort(str,s[i].num,sizeof(int),cmp2);
        for(j = 0; j < s[i].num; j++)s[i].ss[j] = str[j];
    }
    qsort(s,cas,sizeof(s[0]),cmp);
    for(i = 0; i < s[0].num; i++)ans[0][i] = s[0].ss[i];
    k = s[0].num;
    for(i = 1,h = 0; i < cas; i++)
       {
           h = 0;
           r++;
           for(g = 0; g < s[i].num; g++)
              for(j = 0; j < k; j++)
                 if(s[i].ss[g] == ans[r-1][j])
                 {
                     ans[r][h++] = s[i].ss[g];
                     break;
                 }
           k = h;
       }
    for(i = 0; i < h; i++)printf("%d ",ans[r][i]);
    return 0;
}
