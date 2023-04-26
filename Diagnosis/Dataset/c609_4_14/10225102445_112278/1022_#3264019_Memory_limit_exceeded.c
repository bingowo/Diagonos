#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
struct F
{char a[10000];
 char  b[10000];
 char c[10000] ;
}M;
int cmp1(const void *a,const void *b)
{struct F*aa=(struct F*)a;
struct F*bb=(struct F*)b;
if(strcmp(aa->c,bb->c)!=0){return strcmp(aa->c,bb->c);}
else {return -strcmp(aa->b,bb->b);}
}

int main()
{int A,i,j,m;
scanf("%d",&A);
int p[A];
if(A!=1)
{struct F*stu=(struct F*)malloc(A*sizeof(M));

for(i=0;i<A;i++)
{
    scanf("%s",stu[i].a);
}
for(i=0;i<A;i++)
{for(j=0;j<10000;j++)
  {if(stu[i].a[j]!='@'){stu[i].b[j]=stu[i].a[j];}
  else if(stu[i].a[j]=='@') {p[i]=j+1;break;}

  }
}
for(i=0;i<A;i++)
{for(j=p[i],m=0;j<10000;j++)
  {if(stu[i].a[j]!='\0'){stu[i].c[m]=stu[i].a[j];m++;}
else break;

  }
}

qsort(stu,A,sizeof(stu[0]),cmp1);
for(i=0;i<A;i++)
{printf("%s\n",stu[i].a);

}
free(stu);
}


else {char s[1000000] ;scanf("%s",s);printf("%s",s);}

return 0;
}
