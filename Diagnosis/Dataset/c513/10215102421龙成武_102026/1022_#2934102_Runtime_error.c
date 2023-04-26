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
        scanf("%s",address[i]);
    }
    qsort(address,n,sizeof(char*),compar);

    for(i=0;i<n;i++)
    {
        puts(address[i]);
    }

    for(i=0;i<n;i++)
    {
        free(address[i]);
    }
    free(address);
    return 0;
}

int compar(const void *p1,const void *p2)
{
    int flag=0,ia,ib;
    char *a,*b,**A,**B;
    A=(char**)p1;B=(char**)p2;
    a=*A;b=*B;
    for(ia=0;ia<strlen(a);ia++)
        if(a[ia]=='@')
            break;
    for(ib=0;ib<strlen(b);ib++)
        if(b[ib]=='@')
            break;
    flag=strcmp(a+ia,b+ib);     //返回值不是+1或-1，只是在我的电脑上这样而已
    if(flag>0)
        flag=1;
    else if(flag<0)
        flag=-1;
    else
    {
        flag=-strcmp(a,b);
        if(flag>0)
            flag=1;
        else
            flag=-1;
    }
    return flag;
}
