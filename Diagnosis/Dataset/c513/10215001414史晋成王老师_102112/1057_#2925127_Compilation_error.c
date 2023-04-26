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
{ char s[1200],c; int i,j,n,m;
scanf("%c",&s[0]);
if (s[0]>='a'&&s[0]<='z') s[0]-=32;
c=getchar()
while(c!=EOF)
{ if (c>='a'&&c<='z') c=c-32;
 if (c>=s[0])
 { for(i=0;i<strlen(s);i++)
    s[i+1]=s[i];
     s[0]=c;}
     else if (c<s[0])
     s[strlen(s)]=c;
}
printf("%s",s);
}
