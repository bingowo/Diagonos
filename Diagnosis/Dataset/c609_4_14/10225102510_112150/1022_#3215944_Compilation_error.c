#include<stdio.h>
#include<stdlib.h>
char* domain(char *addr)
{
    int i;for(i=0;addr[i]!='@';i++)
    return addr+i+1;
}
int cmp(const void* e1,const void* e2)
{
    char *addr1=*(char**)e1,*addr2=*(char**)e2;
    int delta=strcmp(domain(addr1),domain(addr2));
    if(delta)return adlta;
    return -1*strcmp(addr1,addr2);
}
int main()
{
    int i,n;char**a;
    scanf("%d",&n);
    a=(char**)malloc(sizeof(char*)*n);
    for(i=0;i<n;i++)
    {
        char *s=(char*),malloc(1000001*sizeof(char));
        scanf("%s",s);
        a[i]=(char*)malloc((strlen(s)+1)*sizeof(char));
        strcpy(a[i],s);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(i=0;i<n;i++) printf("%s\n",a[i]);
    return 0;
}