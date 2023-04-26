#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void*b)
{
    int c = *(int*)a;
    int d = *(int*)b;
    if(c<d)return -1;
    else return 1;
}
int main()
{
    int n,m,i,j,k,l,g;
    int s1[507]={0},s2[507]={0},ss[507]={0},sss[507]={0};
    int *ss2;
    scanf("%d",&n);
    for(i = 0; i < n; i++)scanf("%d",&s1[i]);
    scanf("%d",&m);
    for(i = 0; i < m; i++)scanf("%d",&s2[i]);

    for(i = 0,k = 0; i < n; i++)
        for(j = 0; j < m; j++)

     {   if(s1[i] == s2[j])
        {
            ss[k] = s2[j];
            k++;
            s2[j] = -1;
        }
         else if(s2[j] == -1)continue;
     }
     ss2 = (int*)malloc(m*sizeof(int));
     for(i = 0; i < m; i++)ss2[i] = s2[i];

    qsort(ss2,m,sizeof(ss2[0]),cmp);

    for(l = 0,g = 0;l < m; l++)
        if(s2[l] != -1)sss[g] = s2[l],g++;

    for(i = 0; i < k; i++)printf("%d ",ss[i]);
    for(i = 0; i < g; i++)printf("%d ",sss[i]);
    return 0;
}