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
{ char s[1200],c; int i,j,n,m,l;
i=0;
while(scanf("%c",&s[i])!=EOF)
{ if(s[i]>='a'&&s[i]<='z') s[i]-=32;
    if(i>0&&s[i]>=s[0])
{ c=s[i];l=strlen(s);
  for(j=l-1;j>=1;j--)
  { s[j]=s[j-1];
  }
  s[0]=c;
}
 i++;   
}
s[i]=0;
printf("%s",s);
}
