#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{char s[25];int num;}node;
int cmp(const void*a,const void*b)
{
    node p1=*((node*)a);
    node p2=*((node*)b);
    if(p1.num!=p2.num)return p2.num-p1.num;
    else return strcmp(p1.s,p2.s);



}
int main()
{

    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        node p[101]={0};
        int a[26]={0};
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            scanf("%s",p[j].s);
            int l=strlen(p[i].s);
            for(int k=0;k<l;k++)
            {
                a[p[j].s[k]-'A']=1;
            }
            int sum=0;
            for(int k=0;k<l;k++)
            {
                if(a[p[j].s[k]-'A']==1)sum++;
            }
            p[j].num=sum;

        }
        printf("case #%d:\n",i);
        qsort(p,n,sizeof(p[0]),cmp);
for(int i=0;i<n;i++) printf("%s\n",p[i].s);
    }



return 0;

}
