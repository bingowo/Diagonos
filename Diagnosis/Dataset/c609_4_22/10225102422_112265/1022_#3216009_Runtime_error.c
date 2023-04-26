/*超范围的两种情况一种n1但是地址很长还有一种n很大，字符指针数组把它char (*p)[]也放在malloc*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * domain(char *addr)
{
    int i;
    for(i=0;addr[i]!='@';i++)
    return addr+i+1;
}
int cmp(const void *e1,const void* e2)
{
    char *addr1=(char**)e1;char *addr2=(char**)e2;
    int delta=strcmp(domain(addr1),domain(addr2));
    if(delta) return delta;
    return (-1)*strcmp(addr1,addr2);
}
int main()
{
    int n;char **a;
    scanf("%d",&n);
    a=(char **)malloc(sizeof(char*)*n);
    int i;
    for(i=0;i<n;i++)
    {
        char *s=(char*)malloc(sizeof(char)*1000001);
        scanf("%s",s);
        a[i]=(char*)malloc((strlen(s)+1)*sizeof(char));
        strcpy(a[i],s);
        free(s);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(i=0;i<n;i++)
    {
        printf("%s\n",a[i]);
        free(a[i]);
    }
    free(a);
    return 0;
}