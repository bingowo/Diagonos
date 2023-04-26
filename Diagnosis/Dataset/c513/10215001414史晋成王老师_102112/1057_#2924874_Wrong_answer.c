#include<stdio.h>
#include<string.h>
#include<string.h>
int cmp (const void*a,const void *b)
{ char *x,*y;
x=(char *) a;
y=(char*) b;
return strcmp(y,x);
}
int main()
{ char s[1200],c[1200][2]; int i,j,n,m;
gets(s);
i=strlen(s);
for(j=0;j<i;j++)
{ c[j][0]=s[j];
  c[j][1]=0;
   if (c[j][0]>='a'&&c[j][0]<='z') c[j][0]-=32;
}
qsort(c,i,sizeof(c[0]),cmp);
for(j=0;j<i;j++)
{ printf("%c",c[j][0]);}
}
