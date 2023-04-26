#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int month2idx(char* m)
{ int i;
  static char* month[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
  for(i=0;;i++) if(!strcmp(m,month[i])) return i;
}
int cmp(const void*a,const void*b)
{struct maya *x,*y;
x=(struct maya*)a;
y=(struct maya*)b;
    return x->val-y->val;
}
struct maya
{ int day,year,val;
  char date[10];
    
}
int main()
{ int T,i,j,N; struct maya s[10001];
scanf("%d",&T);
for(i=0;i<T;i++)
{ scanf("%d",&N);
  for(j=0;j<N;j++)
  { scanf("%d.",&s[j].day);
    scanf("%s",s[j].date);
    scanf("%d",&s[j].year);  
    s[j].val=s[j].year*1000+month2idx(s[j].date)*20+s[j].day;
  }
  qsort(s,N,sizeof(s[0]),cmp);
  printf("case #%d:\n",i);
  for(j=0;j<N;j++)
  printf("%d. %s %d\n",s[j].day,s[j].date,s[j].year);
}
    
}