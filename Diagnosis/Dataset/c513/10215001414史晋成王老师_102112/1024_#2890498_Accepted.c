#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct count
{ char number[12];
  int code;
  int  cou;
};
int cmp(const void*a,const void *b){
   struct count d1,d2; int i; long long int a1=0,a2=0;

   d1=*((struct count*)a);
   d2=*((struct count*)b);
   for(i=0;i<11;i++)
   {a1+=(d1.number[i]-'0')*pow(10,10-i);
   a2+=(d2.number[i]-'0')*pow(10,10-i);}
   if (d1.code!=d2.code) return d2.code-d1.code;
   else {if (a1<a2) return -1;
         else return 1;}
}
int main()
{int T,N,M,G,i,j,S,k,l,f,p,q,g,e,o; int a[20]={0},m[500]; struct count student[500];
for(i=0;i<500;i++)
student[i].code=0;
scanf("%d\n",&T);
for(i=0;i<T;i++)
{ scanf("%d%d%d\n",&N,&M,&G);
  for(p=0;p<M-1;p++)
  {scanf("%d ",&a[p]);}
  scanf("%d\n",&a[M-1]);
  for(j=0;j<N;j++)
   {scanf("%s %d",student[j].number,&k); 
     int solve;
     for(g=0;g<k;g++)
     { scanf("%d ",&solve);
     student[j].code+=a[solve-1];
         }}
     qsort(student,N,sizeof(student[0]),cmp);
     for(o=0;o<N;o++)
     {if(student[o].code<G) break;}
     printf("case #%d:\n",i);
     printf("%d\n",o);
     if(o!=0){
     for(f=0;f<o;f++)
     {for(q=0;q<11;q++)
      printf("%c",student[f].number[q]);
      printf(" ");
         printf("%d\n",student[f].code);
         
     }}
     for(e=0;e<500;e++)
     {student[e].code=0;
         }
}
}