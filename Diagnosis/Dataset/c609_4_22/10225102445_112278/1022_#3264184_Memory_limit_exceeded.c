#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
struct F
{char *a;
 char  *b;
 char *c;
};
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
{struct F stu[A];
for(i=0;i<A;i++)
{ stu[i].a=(char*)malloc(sizeof(char)*1000000);
    scanf("%s",stu[i].a);
    stu[i].b=(char*)malloc(sizeof(char)*100000);
stu[i].c=(char*)malloc(sizeof(char)*1000000);
}
for(i=0;i<A;i++)
{for(j=0;j<strlen(stu[i].a);j++)
  {if(stu[i].a[j]!='@'){stu[i].b[j]=stu[i].a[j];}
  else if(stu[i].a[j]=='@') {p[i]=j+1;break;}

  }

}
for(i=0;i<A;i++)
{for(j=p[i],m=0;j<strlen(stu[i].a);j++)
  {if(stu[i].a[j]!='\0'){stu[i].c[m]=stu[i].a[j];m++;}
else break;

  }
}

qsort(stu,A,sizeof(stu[0]),cmp1);
for(i=0;i<A;i++)
{printf("%s\n",stu[i].a);
free(stu[i].a);
free(stu[i].b);
free(stu[i].c);
}


}


else {char s[1000000] ;scanf("%s",s);printf("%s",s);}

return 0;
}

