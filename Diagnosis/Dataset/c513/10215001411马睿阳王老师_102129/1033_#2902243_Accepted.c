#include<stdio.h>
#include<string.h>
struct date{
 int val;
 int y;
 int d;
 char m[7];
} a[10007];

typedef struct date dates;

int month(char*m)
{int i;
 static char*month[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
 for(i=0;;i++)
 if(strcmp(m,month[i])==0) return i;
}

int compare(const void*a,const void*b)
{ dates n1=*(dates*)a;
  dates n2=*(dates*)b;
  return n1.val-n2.val;
}

int main()
{int i,T,N,j;
 scanf("%d\n",&T);
 for(j=0;j<T;j++)
{
 scanf("%d\n",&N);
 for(i=0;i<N;i++)
 {scanf("%d.%s %d",&a[i].d,&a[i].m,&a[i].y);
 
  a[i].val=a[i].y*500+month(a[i].m)*20+a[i].d;
}
  qsort(a,N,sizeof(a[0]),compare);
   printf("case #%d:\n",j);
   for(int i=0;i<N;i++)
  printf("%d. %s %d\n",a[i].d,a[i].m,a[i].y);
 


}
return 0;
}
