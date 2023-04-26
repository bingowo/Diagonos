#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char s[50];
    int cnt;
}node;
int cmp(const void *a,const void *b)
{
    node s1=*(node*)a;
    node s2=*(node*)b;
    if(s1.cnt!=s2.cnt)
        return s2.cnt-s1.cnt;
    else
    {
        return strcmp(s1.s,s2.s);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n,m,g;
        scanf("%d %d %d",&n,&m,&g);
        int a[m+1];
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[j]);
        }
        node student[n];
        for(int k=0;k<n;k++)
        {
            student[k].cnt=0;
            scanf("%s",student[k].s);
            int num;
            scanf("%d",&num);
            for(int t=0;t<num;t++)
            {
                int temp;
                scanf("%d",&temp);
                student[k].cnt+=a[temp];
            }
        }
        qsort(student,n,sizeof(student[0]),cmp);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(student[i].cnt>=g)
                ans++;
                //printf("%s %d\n",student[i].s,student[i].cnt);
        }
        printf("case #%d:\n",i);
        printf("%d\n",ans);
        for(int i=0;i<ans;i++)
            printf("%s %d\n",student[i].s,student[i].cnt);
    }
}
