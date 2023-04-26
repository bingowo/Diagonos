#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int numof(char* x)
{
    int a[128],co=0;
    memset(a,0,128*sizeof(int));
    int len=strlen(x);
    int i,j;
    for(i=0;i<len;i++)
    {
        a[x[i]]++;
    }
    for(i=0;i<128;i++)
    {
        if(a[i]!=0) co++;
    }
    return co;
}

int cmp(const void* a,const void* b)
{
    char* aa=*((char**)a);
    char* bb=*((char**)b);
    int nofa=numof(aa);
    int nofb=numof(bb);
    if(nofa>nofb) return -1;
    else if(nofa<nofb) return 1;
    else return strcmp(aa,bb);

}

int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n,j;
        scanf("%d",&n);
        char* str[110];
        for(j=0;j<n;j++)
        {
            str[j]=(char*)malloc(25*sizeof(char));
        }

        for(j=0;j<n;j++)
        {
            scanf("%s",str[j]);
        }
        /*for(j=0;j<n;j++)
        {
            printf("test test str[%d]=%s\n",j,str[j]);
        }*/
        qsort(str,n,sizeof(char*),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<n;j++)
        {
            printf("%s\n",str[j]);
        }
    }
    return 0;
}
