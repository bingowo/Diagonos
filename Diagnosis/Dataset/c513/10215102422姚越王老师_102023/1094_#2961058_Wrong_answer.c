#include<string.h>
#include<stdio.h>
#define C 130
#define R 60
int compare(const int* a,const int* b)
{
    int i=0;
    while(a[i]==b[i])i++;
    if(a[i]<b[i])return 1;
    else return -1;
}
void sub(int *a,const int* b)
{
    int i,j;
    for(i=C-1;i>-1;--i)
    {
        if(a[i]<b[i])
        {
            j=i;
            while(a[--i]);
            a[i]--;for(++i;i<j;++i)a[i]=9;
            a[i]=10+a[i]-b[i];
        }
        else a[i]-=b[i];
    }
}
int main()
{
    int n,i,j,k,len;scanf("%d",&n);
    char str[C];
    int a[R][C]={0};
    for(i=0;i<n;++i)
    {
        scanf("%s",str);
        len=strlen(str);
        for(j=C-len,k=0;j<C;++j,++k)a[i][j]=str[k]-48;
    }
    int s=0,b=0;
    for(i=1;i<n;++i)
    {
        if(compare(a[i],a[s])==1)s=i;
        if(compare(a[i],a[b])==-1)b=i;
    }
    sub(a[b],a[s]);
    for(i=0;i<C;++i)if(a[b][i])break;
    for(i;i<C;++i)printf("%d",a[b][i]);
    return 0;
}