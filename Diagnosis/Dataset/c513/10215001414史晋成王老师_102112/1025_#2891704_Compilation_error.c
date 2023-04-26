#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct pi {
    int count;
    char id[200];
};
int cmp(const void*a,const void*b)
{ struct pi d1,d2;
d1=*((struct pi*)a);
d2=*((struct pi*)b);
if (d1.count!=d2.count) return d2.count-d1.count;
else return 1;
}

int main()
{int T,n,i,j,t,o,k; struct pi s[21]; char d[100]
for(i=0;i<21;i++)
s[i].count=0;
 scanf("%d",&T);
 for(i=0;i<T;i++)
 {scanf("%d",&n);
 for(j=0;j<n;j++)
 {scanf("%s",d);
   }
   printf("case #%d:\n",i);
    printf("\n");
   }
 
     return 0;
 }
    
