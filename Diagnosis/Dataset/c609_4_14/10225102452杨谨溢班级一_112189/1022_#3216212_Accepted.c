// 定义超大内存空间 局部变量 字节不超百万级 10^6 字节
//  放不下 使用动态内存分配 动态分配又分配
// 内存分布 静态 动态 
/*
char **email;
email = (char**)malloc(n*sizeof(char*));
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*a,const void *b)
{
    char *p1,*p2,*domain1,*domain2;
    int i = 0;
    p1 = *((char**)a);  p2 = *((char**)b);
    while(*(p1+i)!='@') ++i;
    domain1 =p1 + i + 1;
    i = 0;
    while(*(p2+i)!='@') ++i;
    domain2 =p2 + i + 1;
    if (strcmp(domain1,domain2)==0)  return strcmp(p2,p1);
    return strcmp(domain1,domain2);
}

int main()
{
    char **email,*p;
    int n;
    scanf("%d",&n);
    email = (char**)malloc(n*sizeof(char*));
    char str[1000005];
    for (int i = 0;i<n;++i)
    {
        scanf("%s",str);
        p = (char *)malloc((strlen(str)+1)*sizeof(char));
        strcpy(p,str);
        *(email+i) = p;
    }
    qsort(email,n,sizeof(char*),cmp);
    for (int i = 0;i<n;++i)
    {
        printf("%s\n",email[i]);
        p = email[i];
        free(p);
    }
    free(email);
    return 0;
}
