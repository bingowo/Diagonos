#include<stdio.h>
#include<stdlib.h>
struct count
{ char number[12];
  int code;
  int  cou;
};
int cmp(const void*a,const void *b){
   struct count d1,d2;
   d1=*((struct count*)a);
   d2=*((struct count*)b);
   if (d1.code!=d2.code) return d1.code-d2.code;
   else {if (d1.number>d2.number) return -1;
         else return 1;}
}
int main()
{int T,N,M,G,i,j,S,k,l,f,p,q; int a[20],m[500]; struct count student[500];
for(i=0;i<500;i++)
student[i].code=0;
scanf("%d\n",&T);
for(i=0;i<T;i++)
{ scanf("%d %d %d\n",&N,&M,&G);
  for(p=0;p<M-1;p++)
  {scanf("%d ",&a[p]);}
  scanf("%d\n",&a[M-1]);
  for(j=0;j<N;j++)
   {scanf("%s ",student[j].number); 
   scanf("%d ",&student[j].cou);
   int k=0;
      while(scanf("%d ",&m[k]))
      {student[j].code+=a[m[k]];
          k++;
      }
     }
     qsort(student,N,sizeof(student[0]),cmp);
     printf("case #%d:\n",i);
     for(f=0;f<G;f++)
     {for(q=0;q<11;q++)
      printf("%c",student[f].number[q]);
      printf(" ");
         printf("%d\n",student[f].code);
         
     }
}
}