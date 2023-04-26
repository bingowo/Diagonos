#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef struct
{int s[100];
int count;}TEAM;

int cmp(const void*a1,const void*a2)
{
    TEAM a=*(TEAM*)a1;
    TEAM b=*(TEAM*)a2;
    
    if(a.s[0]!=b.s[0]) return b.s[0]-a.s[0];
    else if(a.s[1]!=b.s[1]) return b.s[1]-a.s[1];
    else if(a.s[2]!=b.s[2]) return b.s[2]-a.s[2];
}
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        int m;
        scanf("%d\n",&m);
        TEAM*u=NULL;
        u=(TEAM*)malloc(m*sizeof(TEAM));
        for(int k=0;k<m;k++)
        {
            u[k].count=0;
            while((scanf("%d",&u[k].s[u[k].count])!=EOF&&u[k].s[u[k].count]!=-1)) u[k].count++;
        }//输入
        qsort(u,m,sizeof(TEAM),cmp);//排序
        for(int k=0;k<m;k++)
    {
        for(int p=0;p<u[k].count;p++)
        printf("%d ",u[k].s[p]);
        printf("\n");//输出
    }
    }
    return 0;
}