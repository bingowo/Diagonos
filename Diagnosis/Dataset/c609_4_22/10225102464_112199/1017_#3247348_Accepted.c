#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int s[110];
int cmp_1(const void *a, const void *b){
        return *(int *)a-*(int *)b;}
int cmp_2(const void *a, const void *b){
        return *(int *)b-*(int *)a;}
int main()
{
    char aa;int i=0;
    aa=getchar();
    getchar();
    memset(s,0,sizeof(s));
    while(scanf("%d",&s[i++])!=EOF)
        ;
    if(aa=='A') qsort(s,i-1,sizeof(int),cmp_1);
        else qsort(s,i-1,sizeof(int),cmp_2);
    printf("%d ",s[0]);
    for(int j=1;j<i-1;j++){
        if(s[j]==s[j-1]) continue;
            else printf("%d ",s[j]);
    }
    return 0;
}

