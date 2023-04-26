#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct F
{char a[1000];
 char  b[1000] ;
 char c[1000] ;
}stu[30000];
int cmp(const void *a,const void *b)
{struct F*aa=(struct F*)a;
struct F*bb=(struct F*)b;
if(strcmp(aa->c,bb->c)!=0){return strcmp(aa->c,bb->c);}
else {return -strcmp(aa->b,bb->b);}
}
int main()
{int A,i,j;
scanf("%d",&A);
int p[A];
for(i=0;i<A;i++)
{
    scanf("%s",stu[i].a);
}
for(i=0;i<A;i++)
{for(j=0;j<10000;j++)
  {if(stu[i].a[j]!='@'&&stu[i].a[j]!='\0'){stu[i].b[j]=stu[i].a[j];}
  else {p[i]=j+1;break;}

  }
}
for(i=0;i<A;i++)
{for(j=p[i];j<10000;j++)
  {if(stu[i].a[j]!='\0'){stu[i].c[j]=stu[i].a[j];}
else break;

  }
}
qsort(stu,A,sizeof(stu[0]),cmp);

for(i=0;i<A;i++)
{printf("%s\n",stu[i].a);

}

return 0;
}
