#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{char s[15];int num;}node;
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
        int n,m,g,s;
        node p[505]={0};
    int a[11]={0};
        scanf("%d%d%d",&n,&m,&g);
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[j]);
        }

        for(int j=0;j<n;j++)
        {
            scanf("%s",p[j].s);
           scanf("%d",&s);
            for(int k=0;k<s;k++)
            {
                int x;
                scanf("%d",&x);
                p[j].num+=a[x-1];

            }


        }
        printf("case #%d:\n",i);
        qsort(p,n,sizeof(p[0]),cmp);
int cnt=0;
for(int i=0;i<n;i++) if(p[i].num>=g)cnt++;
printf("%d\n",cnt);
  for(int i=0;i<n;i++) if(p[i].num>=g) printf("%s %d\n",p[i].s,p[i].num);
    }



return 0;

}
