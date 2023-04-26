#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char sid[12];
    int sum;
    int s[10];
    int sco;//总分数
}students;

int cmp(const void *a,const void *b)
{
    students c=*(students*)a;
    students d=*(students*)b;
    if(c.sco!=d.sco) return d.sco-c.sco;
    else strcmp(c.sid,d.sid);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int k=0;k<t;k++)
    {
        printf("case #%d:\n",k);
        int n,m,g;
        scanf("%d%d%d",&n,&m,&g);
        int a[10];
        for(int i=0;i<m;i++)
            scanf("%d",&a[i]);
        students stu[500];
        int npass=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",stu[i].sid);
            scanf("%d",&stu[i].sum);
            stu[i].sco=0;
            for(int j=0;j<stu[i].sum;j++)
            {
                 scanf("%d",&stu[i].s[j]);
                 int b=stu[i].s[j]-1;
                 stu[i].sco+=a[b];
            }
            if(stu[i].sco>=g) npass++;
        }
        qsort(stu,n,sizeof(stu[0]),cmp);
        printf("%d\n",npass);
        for(int i=0;i<npass;i++)
        {
            printf("%s %d\n",stu[i].sid,stu[i].sco);
        }
    }
    return 0;
}