#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int email_address_cmp(const void *a,const void *b)
{
    int atposa=0,i=0,j=0,atposb=0,lenahost=0,lenbhost=0;
    for(i=0;*(*(char**)a+i)!='@';i++);
    atposa=i;
    for(i=0;*(*(char**)b+i)!='@';i++);
    atposb=i;
    for(i=atposa,j=atposb;*(*(char**)b+j)!='\0'&&*(*(char**)a+i)!='\0';i++,j++)
        if(*(*(char**)a+i)!=*(*(char**)b+j)) return *(*(char**)a+i)-*(*(char**)b+j);
    if ((lenahost=strlen(*(char**)a+atposa))!=(lenbhost=strlen(*(char**)b+atposb))) return lenahost-lenbhost;
    for(i=0;*(*(char**)b+i)!='@'&&*(*(char**)a+i)!='@';i++)
        if(*(*(char**)a+i)!=*(*(char**)b+i)) return *(*(char**)b+i)-*(*(char**)a+i);
    if(strlen(*(char**)a)-lenahost!=strlen(*(char**)b)-lenbhost) return strlen(*(char**)b)-lenbhost-strlen(*(char**)a)+lenahost;
    return 0;
}

int main()
{
    int n=0;
    scanf("%d",&n);
    int j=0;
    char **email_address;
    email_address=(char**)malloc(n*sizeof(char*));
    for(j=0;j<n;j++)
    {
        char temp[1000001];
        scanf("%s",temp);
        *(email_address+j)=(char*)malloc((strlen(temp)+1)*sizeof(char));
        for(int i=0;i<strlen(temp)+1;i++)
        *(*(email_address+j)+i)=temp[i];
    }
    qsort(email_address,n,sizeof(char*),email_address_cmp);
    for(j=0;j<n;j++)
        printf("%s\n",*(email_address+j));
    return 0;
}
