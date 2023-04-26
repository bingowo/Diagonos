#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    int cmp(const void*,const void*);
    scanf("%d",&n);
    char **adrs = (char **)malloc(n*sizeof(char*));
    char s[1000001],*p;
    for(int i = 0;i<n;i++){
        scanf("%s",s);
        p = (char *)malloc(strlen(s) + 1);
        strcpy(p,s);
        *(adrs+i) = p;
    }
    qsort(adrs,n,sizeof(char *),cmp);
    for(int i = 0;i<n;i++){
        printf("%s\n",*(adrs+i));
    }
    for(int i = 0;i<n;i++){
        free(*(adrs+i)); //先释放存放在空间中的空间
    }
    free(adrs);//再释放最外层的空间
    return 0;
}
int cmp(const void *a,const void *b)
{
    char *pa,*pb,*maina,*mainb;//pa(pb)指向用户名（降序），maina(mainb)指向域名（升序）
    pa = *(char **)a;
    pb = *(char **)b;
    int i = 0;
    while(*(pa+i) != '@') i++;
    maina = pa + i + 1;
    i = 0;
    while(*(pb+i) != '@') i++;
    mainb = pb + i + 1;
    if(strcmp(maina,mainb) == 0) return -strcmp(pa,pb);
    return strcmp(maina,mainb);
}