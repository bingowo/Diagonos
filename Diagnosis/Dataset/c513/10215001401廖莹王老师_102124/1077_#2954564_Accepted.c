#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int s;
    int ct;
}tong;
tong p[500];
int m,n;
int bitong(char a[1000][5],char b[1000][5])
{
    int i=0,j=0,k=0;
    for(i=0;i<m;i++)
    {
        p[k].ct=0;
        for(j=0;j<n;j++)
        {
         if(strcmp(a[i],b[j])==0){p[k].ct++;b[j][0]='\0';}
        }
        if(p[k].ct!=0){p[k].s=atoi(a[i]);k++;}
    }
    return k;
}
int cmp(const void *a,const void*b)
{
    char*s1,*s2;int k1=0,k2=0;
    s1=(char *)a;s2=(char*)b;
    k1=atoi(s1);k2=atoi(s2);
    if(k1>=k2)return 1;
    else return -1;
}
int main()
{

    int i=0,k=0,q=0;
    char a[1000][5];
    char b[1000][5];
    scanf("%d",&m);
    for(i=0;i<m;i++)scanf("%s",a[i]);
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%s",b[i]);
    qsort(b,n,sizeof(b[0]),cmp);
    k=bitong(a,b);
    for(i=0;i<k;i++){for(q=0;q<p[i].ct;q++)printf("%d ",p[i].s);}
    for(i=0;i<n;i++)if(b[i][0])printf("%s ",b[i]);
    return 0;
}
