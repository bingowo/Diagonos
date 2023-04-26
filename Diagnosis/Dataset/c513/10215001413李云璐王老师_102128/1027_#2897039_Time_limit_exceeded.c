#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define pai 3.1415926

typedef struct{double heng;double zong;double jiao;double bian;}zb;

zb*INPUT(int m)
{
    zb*s;
    s=(zb*)malloc(m*sizeof(zb));
    for(int k=0;k<m;k++)
    {
        scanf("%lf %lf",&s[k].heng,&s[k].zong);
        int  shou=1,wei=pow(fabs(s[k].heng),2)+pow(fabs(s[k].zong),2),mid=(shou+wei)/2;
        while(fabs(mid*mid-wei)>1e-5)
        {
            if(mid*mid>wei) wei=mid;
            else shou=mid;
            mid=(shou+wei)/2;
        }
        s[k].bian=mid;
        
        
        s[k].jiao=atan2(s[k].zong,s[k].heng);
        if(s[k].jiao<0) s[k].jiao+=2*pai;
    }
    
    return s;
}
void sort(zb*s,int m)
{
    int compare(const void*a1,const void*a2)
    {
        zb a=*(zb*)a1;
        zb b=*(zb*)a2;
        if(a.jiao!=b.jiao) return a.jiao*1000000-b.jiao*1000000;
        else return b.bian*1000000-a.bian*1000000;
    }
    qsort(s,m,sizeof(zb),compare);
}

int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        int m;
        scanf("%d\n",&m);
        zb*s=NULL;
        s=INPUT(m);
        
        sort(s,m);
        printf("case #%d:\n",i);
        for(int k=0;k<m;k++)
        printf("(%.4f,%.4f)\n",s[k].bian,s[k].jiao);
    }
    return 0;
    
    
}
