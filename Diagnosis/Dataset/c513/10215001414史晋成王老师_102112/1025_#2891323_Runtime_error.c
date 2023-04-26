#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct pi {
    int count;
    char alpha[200];
};
int cmp(const void*a,const void*b)
{ struct pi d1,d2;
d1=*((struct pi*)a);
d2=*((struct pi*)b);
if (d1.count!=d2.count) return d2.count-d1.count;
else return 1;
}

int main()
{int T,n,i,j,t,o; struct pi s[21]; int a[200];
for(i=0;i<21;i++)
{s[i].count=0;}
 scanf("%d\n",&T);
 for(i=0;i<T;i++)
 {scanf("%d\n",&n);
 for(j=0;j<n;j++)
 {int h=0;
   while(scanf("%c",s[j].alpha[h]))
    h++;
  int k=0,d=0,count;
   while(s[j].alpha[k])
   {for (t=0;t<k;t++)
   {if (s[j].alpha[k]==s[j].alpha[t]) d=1;}
     if (d==0) s[j].count++;
     k++;
   }
  
   }
   printf("case #%d:\n",i);
   qsort(s,n,sizeof(s[0]),cmp);
   for(j=0;j<n;j++)
   { int o=0;
       while(s[j].alpha[o])
       {printf(s[j].alpha[o]);
        o++; 
       } printf("\n");
   }
 }
     
 }
    
