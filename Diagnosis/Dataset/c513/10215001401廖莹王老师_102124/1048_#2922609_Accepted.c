#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int zs;
    int xs;
}duoxiangshi;

int read(char s[1000],duoxiangshi p[60])
{

    int sign=1,c=0,d=0,i,j=0;
    for(i=0;s[i];i++)
    {
        sign=1;c=0;d=0;p[i].zs=0;p[i].xs=0;
        if(s[i]=='+')i++;
        else if(s[i]=='-'){sign=-1;i++;}
        while(isdigit(s[i])){c=c*10+s[i]-'0';i++;}
        if(s[i]!='x'){p[j].xs=c*sign;p[j].zs=0;j++;continue;}
        else
        {
            if(c==0){p[j].xs=1*sign;}else p[j].xs=c*sign;i++;
        }
        if(s[i]=='^'){i++; while(isdigit(s[i])){d=d*10+s[i]-'0';i++;}p[j].zs=d;j++;}
        else{p[j].zs=1;j++;}
        i--;
    }
  return j;
}
int jisuan(duoxiangshi p[60],duoxiangshi t[60],duoxiangshi r[60],int j,int h)
{
    int m,n,i=0;
    for(m=0;m<j;m++)
    {
        r[i].zs=0;r[i].xs=0;
        for(n=0;n<h;n++)
        {
            r[i].zs=p[m].zs+t[n].zs;
            r[i].xs=p[m].xs*t[n].xs;
            i++;
        }
    }
    return i;
}
int cmp(const void*a,const void*b)
{
    duoxiangshi *p1,*p2;
    p1=(duoxiangshi*)a;
    p2=(duoxiangshi*)b;
    if(p1->zs>p2->zs)return -1;
    else return 1;
}
int jingjian(duoxiangshi r[60],duoxiangshi k[60],int l)
{
    qsort(r,l,sizeof(r[0]),cmp);
    int i=0,m=0,h=0;
    for(i=0;i<l;i++)
    {
        k[m].xs=r[i].xs;k[m].zs=r[i].zs;
        for(h=i+1;h<l;h++)
        {
            if(r[h].zs==r[h-1].zs)k[m].xs=k[m].xs+r[h].xs;
            else break;
        }
        m++;
        i=h-1;
    }
    return m;

}
int main()
{
    char s1[1000]={0},s2[1000]={0};
    while(scanf("%s %s",s1,s2)==2)
    {
    duoxiangshi p[60],t[60],r[60],k[60];
    int i=0,j=0,h=0,l=0,n=0;
   j=read(s1,p);
   h=read(s2,t);
   l=jisuan(p,t,r,j,h);n=jingjian(r,k,l);
    for(i=0;i<n;i++)
  {
      if(k[i].xs!=0)printf("%d ",k[i].xs);
  }
  printf("\n");
       for(i=0;s1[i];i++)s1[i]=0;
       for(i=0;s2[i];i++)s2[i]=0;

    }

    return 0;
}
