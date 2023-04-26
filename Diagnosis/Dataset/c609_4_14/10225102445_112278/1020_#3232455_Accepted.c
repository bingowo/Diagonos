#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct F
{char c[30];
   int a;
}stu[100];
int cmp(const void*b,const void*p)
{   struct F *aa=(struct F*)b;
   struct F *bb=(struct F*)p;
    if(aa->a!=bb->a)
    {return aa->a-bb->a;}
    else
    {return strcmp(aa->c,bb->c);}

}
int main()
{int i=0,m,k,g,l;

    while(scanf("%s",stu[i].c)!=-1){i++;}
    l=i;
    for(m=0;m<=i-1;m++)
    {for(k=0;k<=29;k++)
     {if(stu[m].c[k]>='0'&&stu[m].c[k]<='9')
      {for(g=k;g<=29;g++){if(stu[m].c[g]<'0'||stu[m].c[g]>'9')break;}
  int s=1;int u=0;for(int v=g-1;v>=k;v--){u+=s*(stu[m].c[v]-48);s*=10;}
    stu[m].a=u;break;}
    else stu[m].a=-1;}}
qsort(stu,l,sizeof(stu[0]),cmp);
for(i=0;i<=l-1;i++){printf("%s ",stu[i].c);}
return 0;

}
