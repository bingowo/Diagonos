#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* domain(char* addr)
{
    int i;
    for(i=0;addr[i]!='@';i++);
    return addr+i+1;
}
int cmp(const void* a,const void* b)
{
    char *addr1=*(char**)a,*addr2=*(char**)b;
    int delta=strcmp(domain(addr1),domain(addr2));
    if(delta)
        return delta;
    return -1*strcmp(addr1,addr2);
}
int main()
{
    int i,n;
    char **a;
    scanf("%d",&n);
    a=(char**)malloc(sizeof(char*)*n);
    for(i=0;i<n;i++)
    {
        char *s=(char*)malloc(1000001*sizeof(char));
        scanf("%s",s);
        a[i]=(char*)malloc(sizeof(char)*(strlen(s)+1));
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
