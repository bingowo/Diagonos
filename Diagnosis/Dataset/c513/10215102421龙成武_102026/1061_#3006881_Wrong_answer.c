#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
long long int strval(char *a)
{
    char norep[16]={0};
    long long int len,i,j,ans,base,val;
    len=strlen(a);
    for(i=0,j=0;i<len;i++)
    {
        if(strchr(norep,a[i])==NULL)
            norep[j++]=a[i];
    }
    base=j>2? j:2;
    ans=0;
    for(i=0;i<len;i++)
    {
        val=strchr(norep,a[i])-norep;
        if(val==0)
            val=1;
        else if(val==1) val=0;
        ans=ans*base+val;
    }
    return ans;
}
int compar(const void *p1,const void *p2)
{
    char **a=(char**)p1,**b=(char**)p2;
    int val;
    val=strval(*a)-strval(*b);
    if(val<0)
        return -1;
    else if(val>0)
        return 1;
    else
    {
        return strcmp(*a,*b);
    }
}
int main()
{
    int N,i;
    char **s;
    scanf("%d",&N);
    s=(char**)malloc(N*sizeof(char*));
    for(i=0;i<N;i++)
    {
        s[i]=(char*)malloc(16*sizeof(char));
        scanf("%s",s[i]);
    }
    qsort(s,N,sizeof(char*),compar);
    for(i=0;i<N;i++)
    {
        printf("%s\n",s[i]);
        free(s[i]);
    }
    free(s);
    return 0;
}
