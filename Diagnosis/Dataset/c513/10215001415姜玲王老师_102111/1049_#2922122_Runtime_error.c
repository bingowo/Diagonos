#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b)
{char*p1=(char*)a;
char*p2=(char*)b;
return strcmp(p1,p2);
}
int main()
{int n,m,j;
scanf("%d",&n);
getchar();
char t[501];
for(int i=0;i<n;i++)
{char*a[501];
printf("case #%d:\n",i);
gets(t);
m=0;
for(int k=0;k<strlen(t);k++)
{for(;t[k]!=' '&&t[k]!=','&&t[k]!='.'&&t[k]!='!'&&t[k]!='?'&&k<strlen(t);k++)
{*(a[m])=t[k];a[m]++;}
*(a[m])=0;
m++;
}
qsort(a,m,sizeof(a[0]),cmp);
for(int q=0;q<m-1;q++)
{if(strcmp(a[q],a[q+1])) printf("%s ",a[q]);}
printf("%s\n",a[m-1]);
}

}
