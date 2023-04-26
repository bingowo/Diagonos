#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int number;
    int df;
    int sheng;
    int fu;
    int ping;

}qiudui;
int cmp(const void *a,const void*b)
{
    qiudui *s1,*s2;
    s1=(qiudui*)a;
    s2=(qiudui*)b;
    if(s1->df!=s2->df)return s2->df-s1->df;
    else
    {
        if(s1->sheng !=s2->sheng)return s2->sheng-s1->sheng;
        else
        {
            if(s1->fu!=s2->fu)return s1->fu-s2->fu;
            else return s1->number-s2->number;
        }
    }
}
int main()
{
    int m=0,n=0;
   while(scanf("%d %d",&n,&m))
   {
       if(n==0 && m==0)break;
       int i=0,l,k,c;
       qiudui p[12]={0};
       for(i=0;i<n;i++){p[i].number=i+1;}
       for(i=0;i<m;i++)
       {
            l=0;k=0;c=0;
           scanf("%d %d %d",&l,&k,&c);
           l=l-1;k=k-1;
           switch(c)
           {
               case 1: p[l].df=p[l].df+3 ;p[l].sheng++;p[k].df=p[k].df-1;p[k].fu++;break;
               case -1: p[l].df=p[l].df-1;p[l].fu++;p[k].df=p[k].df+3;p[k].sheng++;break;
               case 0: p[l].df=p[l].df+1;p[l].ping++;p[k].df=p[k].df+1;p[k].ping++;break;
           }
       }
       qsort(p,n,sizeof(p[0]),cmp);
       for(i=0;i<n;i++)printf("%d ",p[i].number);
       printf("\n");

   }

    return 0;
}
