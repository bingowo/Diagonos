#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct stu
{ int C,M,E,A;
  char ID[100];     
};
int cmp1(const void*a,const void*b)
{ struct stu x,y;
   x=*((struct stu*) a);
   y=*((struct stu*) b);
   if(x.A!=y.A) return y.A-x.A;
   else return strcmp(x.ID,y.ID);
}
int cmp2(const void*a,const void*b)
{ struct stu x,y;
   x=*((struct stu*) a);
   y=*((struct stu*) b);
   if(x.C!=y.C) return y.C-x.C;
   else return strcmp(x.ID,y.ID);
}
int cmp3(const void*a,const void*b)
{ struct stu x,y;
    x=*((struct stu*) a);
   y=*((struct stu*) b);
   if(x.M!=y.M) return y.M-x.M;
   else return strcmp(x.ID,y.ID);
}
int cmp4(const void*a,const void*b)
{ struct stu x,y;
    x=*((struct stu*) a);
   y=*((struct stu*) b);
   if(x.E!=y.E) return y.E-x.E;
   else return strcmp(x.ID,y.ID);
}
int main()
{ int i,j,n,m,T; struct stu a[10000];
   double k,k1,k2,k3;
scanf("%d",&T);
for(i=0;i<T;i++)
{ scanf("%d",&n);
  for(j=0;j<n;j++)
  {scanf("%s %d %d %d\n",a[j].ID,&a[j].C,&a[j].M,&a[j].E);
   k1=a[j].C; k2=a[j].M; k3=a[j].E;
   k=(k1+k2+k3)/3.0; 
   a[j].A=k+0.5;
  }
  printf("case #%d:\n",i);
  printf("A:\n");
  qsort(a,n,sizeof(a[0]),cmp1);
  printf("%s\n",a[0].ID);
  for(j=1;j<n;j++)
  {if(a[j].A==a[j-1].A) printf("%s\n",a[j].ID);
      else break;
  }
  printf("C:\n");
  qsort(a,n,sizeof(a[0]),cmp2);
  printf("%s\n",a[0].ID);
  for(j=1;j<n;j++)
  {if(a[j].C==a[j-1].C) printf("%s\n",a[j].ID);
      else break;
  }
  printf("M:\n");
  qsort(a,n,sizeof(a[0]),cmp3);
  printf("%s\n",a[0].ID);
  for(j=1;j<n;j++)
  {if(a[j].M==a[j-1].M) printf("%s\n",a[j].ID);
      else break;
  }
  printf("E:\n");
  qsort(a,n,sizeof(a[0]),cmp4);
  printf("%s\n",a[0].ID);
  for(j=1;j<n;j++)
  {if(a[j].E==a[j-1].E) printf("%s\n",a[j].ID);
      else break;
  }
   memset(a,0,sizeof(a)); 
}
    
}