#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct F
{char a[200];
 char  b[200];
 char c[200] ;
};
struct f
{char a[100000];
 char  b[100000];
 char c[100000] ;

};
int cmp1(const void *a,const void *b)
{struct F*aa=(struct F*)a;
struct F*bb=(struct F*)b;
if(strcmp(aa->c,bb->c)!=0){return strcmp(aa->c,bb->c);}
else {return -strcmp(aa->b,bb->b);}
}

int cmp2(const void *a,const void *b)
{struct f*aa=(struct f*)a;
struct f*bb=(struct f*)b;
if(strcmp(aa->c,bb->c)!=0){return strcmp(aa->c,bb->c);}

else {return -strcmp(aa->b,bb->b);}
}

int main()
{int A,i,j,m;
scanf("%d",&A);
int p[A];
if(A<1000)
{struct F stu[A];

for(i=0;i<A;i++)
{
    scanf("%s",stu[i].a);
}
for(i=0;i<A;i++)
{for(j=0;j<100000;j++)
  {if(stu[i].a[j]!='@'){stu[i].b[j]=stu[i].a[j];}
  else if(stu[i].a[j]=='@') {p[i]=j+1;break;}

  }
}
for(i=0;i<A;i++)
{for(j=p[i],m=0;j<100000;j++)
  {if(stu[i].a[j]!='\0'){stu[i].c[m]=stu[i].a[j];m++;}
else break;

  }
}

qsort(stu,A,sizeof(stu[0]),cmp1);
for(i=0;i<A;i++)
{printf("%s\n",stu[i].a);

}

}

else
{struct f st[A];
for(i=0;i<A;i++)
{
    scanf("%s",st[i].a);
}
for(i=0;i<A;i++)
{for(j=0;j<200;j++)
  {if(st[i].a[j]!='@'){st[i].b[j]=st[i].a[j];}
  else if(st[i].a[j]=='@') {p[i]=j+1;break;}

  }
}
for(i=0;i<A;i++)
{for(j=p[i],m=0;j<200;j++)
  {if(st[i].a[j]!='\0'){st[i].c[m]=st[i].a[j];m++;}
else break;

  }
}
qsort(st,A,sizeof(st[0]),cmp2);
for(i=0;i<A;i++)
{printf("%s\n",st[i].a);}

}



return 0;
}
