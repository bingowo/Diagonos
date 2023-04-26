#include<stdio.h>
#include<stdlib.h>
struct count
{ long long int number;
  int code;
  int  cou;
};
int cmp(const void*a,const void *b){
   struct count d1,d2;
   d1=*((struct count*)a);
   d2=*((struct count*)b);
   if (d1.code!=d2.code) return d1.code-d2.code;
   else {if (d1.count>d2.count) return -1;
         else return 1;}
}
int main()
{int T,N,M,G,i,j,S,k,l,f; int a[20]; struct count student[500];
for(i=0;i<500;i++)
student[i].code=0;
scanf("%d",&T);
for(i=0;i<T;i++)
{ scanf("%d %d %d",&N,&M,&G);
  for(j=0;j<M;j++)
  {scanf("%d ",&a[j]);}
  for(j=0;j<G;j++)
   {scanf("%d %d ",&student[j].number,&student[j].cou); 
      for(k=0;k<student[j].cou;k++)
      { scanf("%d ",&l); student[j].code+=a[k];
          }
     }
     qsort(student,G,sizeof(student[0]),cmp);
     printf("case #%d:\n",T)
     for(f=0;f<G;f++)
     {printf("%lld %d\n",student[f].number,student[f].code);
         
     }
}