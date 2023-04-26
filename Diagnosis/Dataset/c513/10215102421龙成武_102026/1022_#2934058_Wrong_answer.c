#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int compar(const void *p1,const void *p2);
int main()
{
    int n,i;
    char **address;
    scanf("%d",&n);
    address=(char**)malloc(n*sizeof(char*));
    for(i=0;i<n;i++)
    {
        address[i]=(char*)malloc(100000*sizeof(char));
    }

    free(address);
    return 0;
}

int compar(const void *p1,const void *p2)
{
    int flag;
    return flag;
}
