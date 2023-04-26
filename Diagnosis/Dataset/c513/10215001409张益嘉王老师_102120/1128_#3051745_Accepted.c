#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char zong[300];
    char nameyu[300];
    char xuadd[300];
}http;

http divide(http s)
{
    int len=strlen(s.zong),i,mid,j;
    for(i=0;i<len;i++)
    {
        if((s.zong[i]==':')&&(s.zong[i+1]=='/')&&(s.zong[i+2]=='/')) break;
    }
    mid=i+3;
    for(j=0,i=mid;i<len;i++,j++)
    {
        if(s.zong[i]=='/') break;
        s.nameyu[j]=s.zong[i];
    }
    s.nameyu[j]=0;
    mid=i+1;
    for(i=mid,j=0;i<len;i++,j++)
    {
        s.xuadd[j]=s.zong[i];
    }
    s.xuadd[j]=0;
    return s;
}

int cmp(const void*a,const void*b)
{
    http aa=*((http*)a);
    http bb=*((http*)b);
    if(strcmp(aa.nameyu,bb.nameyu)!=0)
    {
        return strcmp(aa.nameyu,bb.nameyu);
    }
    else return strcmp(aa.xuadd,bb.xuadd);


}

int ishttps(char* s)
{
    if(s[4]=='s') return 1;
    else return 0;
}

int main()
{
    int n,i,j=0;
    scanf("%d",&n);
    http web[101];
    http x;
    for(i=0;i<n;i++)
    {
        scanf("%s",x.zong);
        if(ishttps(x.zong)) continue;
        else web[j++]=divide(x);
        //printf("web[%d]:\n域名=%s\n虚拟地址=%s\n",i,web[i].nameyu,web[i].xuadd);
    }
    qsort(web,j,sizeof(http),cmp);
    for(i=0;i<j;i++)
    {
        printf("%s\n",web[i].zong);
    }

}
