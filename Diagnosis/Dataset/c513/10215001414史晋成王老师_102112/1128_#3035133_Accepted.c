#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct count
{ char s1[330];
  char c1[330]; 
  char num[330];   
};
int cmp(const void*a,const void*b)
{  struct count a1,a2;
  a1=*((struct count*) a);
  a2=*((struct count*) b);
    if(strcmp(a1.s1,a2.s1)!=0) return strcmp(a1.s1,a2.s1);
    else return strcmp(a1.c1,a2.c1);
    
}

int main()
{ int n,i,j,m,l,k,r2;
  char s[110][330]={0};
  struct count a[110];
  scanf("%d",&n);
  m=0;
  for(i=0;i<n;i++)
  { scanf("%s\n",s[i]);
     if(s[i][4]!='s')
     {strcpy(a[m].num,s[i]); 
    for(j=7;s[i][j]!='/';j++)
    a[m].s1[j-7]=s[i][j];
    a[m].s1[j-7]=0;
    r2=0;
    for(;s[i][j];j++)
    {a[m].c1[r2]=s[i][j];r2++;}
    a[m].c1[r2]=0;
    m++;
     }
  }
  qsort(a,m,sizeof(a[0]),cmp);
  for(i=0;i<m;i++)
  {
      printf("%s\n",a[i].num);
  }
  return 0;
}