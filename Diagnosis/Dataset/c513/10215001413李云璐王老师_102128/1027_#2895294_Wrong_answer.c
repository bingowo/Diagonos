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
        s[k].bian=sqrt(pow(s[k].heng,2)+pow(s[k].zong,2));
        if(s[k].zong!=0&&s[k].heng!=0) 
        {
          if(s[k].zong>0&&s[k].heng>0) s[k].jiao=pai/4;
          if(s[k].zong>0&&s[k].heng<0) s[k].jiao=3*pai/4;
          if(s[k].zong<0&&s[k].heng>0) s[k].jiao=7*pai/4;
          if(s[k].zong<0&&s[k].heng<0) s[k].jiao=5*pai/4;
        }
        if(s[k].heng==0&&s[k].zong!=0) 
        {
            if(s[k].zong>0) s[k].jiao=pai/2;
            else s[k].jiao=3*pai/2;
        }
        else if(s[k].zong==0)
        {
            if(s[k].heng>=0) s[k].jiao=0;
            else s[k].jiao=pai;
        }
    }
    
    return s;
}
void sort(zb*s,int m)
{
    int compare(const void*a1,const void*a2)
    {
        zb a=*(zb*)a1;
        zb b=*(zb*)a2;
        if(a.jiao!=b.jiao) return a.jiao-b.jiao;
        else return b.bian-a.bian;
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
