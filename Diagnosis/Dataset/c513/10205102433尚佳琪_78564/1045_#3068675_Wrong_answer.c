#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
typedef struct
{
    int cnt;
    int cnt2;
    char s[105];
    char s2[105];
    int subi;
}node;
int cmp(const void *a,const void *b)
{
    node s1=*(node*)a;
    node s2=*(node*)b;
    return s1.cnt-s2.cnt;
}
int main()
{
    int n;
    scanf("%d",&n);
    node a[n];
    //int ans=1000;
    for(int i=0;i<n;i++)
    {
        scanf("%s",a[i].s);
        a[i].cnt=strlen(a[i].s);
        int t=0;

        a[i].s2[t++]=a[i].s[0];

        for(int j=1;j<a[i].cnt;j++)
        {
            if(a[i].s[j]!=a[i].s[j-1])
                a[i].s2[t++]=a[i].s[j];
        }
         a[i].s2[t]='\0';
         a[i].cnt2=t;
         a[i].subi=a[i].cnt-a[i].cnt2;
         //printf("%s\n",a[i].s2);
         if(i>0)
         {
             if(strcmp(a[i].s2,a[i-1].s2)!=0)
             {
                 printf("-1");
                 return 0;
             }
         }
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int temp=a[n/2].cnt;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=ans+abs(a[i].cnt-temp);
    }
    printf("%d",ans);
}
