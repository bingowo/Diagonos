#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct{char s[16];long long int shu;}chuan;

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
}
int main()
{
    int n;
    scanf("%d\n",n);
    chuan*a=NULL;
    a=(chuan*)malloc(n*sizeof(chuan));
    for(int i=0;i<n;i++)
    {
        
        scanf("%s\n",a[i],s);
        int len=strlen(a[i].s);
        int p[128],count=0;
        for(int k=0;k<128;k++)
        p[k]=-1;
        p[a[i].s[0]]=1;
        count++;
        for(int k=1;k<len;k++)
        {
            if(p[a[i].s[k]]==-1)
            {
                p[a[i].s[k]]=(count==1)?0:count;
                count++;
            }
        }//一共有count个不同的数，进制为count
        a[i].shu=0;
        for(int k=0;k<n;k++)
        {
            a[i].shu+=a[i].shu*count+p[a[i].s[k]];
        }
    }
    sort(a,n);
    for(int t=0;t<n;t++)
    printf("%s\n",a[t].s);
    return 0;
}