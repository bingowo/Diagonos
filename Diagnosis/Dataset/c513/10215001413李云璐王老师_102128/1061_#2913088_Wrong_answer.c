#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct{char s[20];long long int count;long long int shu;}chuan;

void sort(chuan*s,int n)
{
    int cmp(const void*a1,const void*a2)
    {
        chuan a=*(chuan*)a1;
        chuan b=*(chuan*)a2;
        if(a.shu!=b.shu) return a.shu-b.shu;
        else return strcmp(a.s,b.s);
    }
    qsort(s,n,sizeof(chuan),cmp);
}//排序
int main()
{
    int n;
    scanf("%d",&n);
    chuan*a=NULL;
    a=(chuan*)malloc(n*sizeof(chuan));
    for(int i=0;i<n;i++)
    {
        
        scanf("%s",a[i].s);
        int len=strlen(a[i].s);
        int p[128];
        for(int k=0;k<128;k++)
        p[k]=-1;
        a[i].count=0;
        p[a[i].s[0]]=1;
        a[i].count++;
        for(int k=1;k<len;k++)
        {
            if(p[a[i].s[k]]==-1)
            {
                if(a[i].count==1) p[a[i].s[k]]=0;
                else p[a[i].s[k]]=a[i].count;
                a[i].count++;
            }
        }
        long long int jinzhi;
        if(a[i].count==1) jinzhi=2;
        else jinzhi=a[i].count;
        a[i].shu=0;
        for(int k=0;k<len;k++)
        {
            a[i].shu=a[i].shu*jinzhi+p[a[i].s[k]];
        }
    }//输入
    sort(a,n);
    for(int t=0;t<n;t++)
    printf("%s\n",a[t].s);
    return 0;
}