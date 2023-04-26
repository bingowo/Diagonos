#include<stdio.h>
#include<string.h>
struct date{
 int val;
 int y;
 int d;
 char m[7];
} a[100];

int month(char*m)
{int i;
 static char*month[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
 for(i=0;;i++)
 if(strcmp(m,month[i])==0) return i;
}

int compare(const void*a1,const void*a2)
{ int n1=*(int *)a1;
  int n2=*(int *)a2;
  return n1-n2;
}

int main()
{int i,T,N,j;
 scanf("%d\n",&T);
 for(j=0;j<T;j++)
{printf("case #%d\n:",j);
 scanf("%d\n",&N);
 for(i=0;i<N;i++)
 {scanf("%d.%s%d",&a[i].d,&a[i].m,&a[i].y);
  int month(char*m);
  a[i].val=a[i].y*500+month(a[i].m)*20+a[i].d;
  qsort(a[i].val,N,sizeof(a[0].val),compare);
  printf("%d. %s%d\n",a[i].d,a[i].m,a[i].y);
 }

}
return 0;
}
