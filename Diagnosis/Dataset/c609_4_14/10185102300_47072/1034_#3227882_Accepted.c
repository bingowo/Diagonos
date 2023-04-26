#include <stdio.h>

#define  N 100000

int isHexDigit(char c) { return c>='0'&&c<='9'||c>='a'&&c<='f'; }

 unsigned getHex(char *s)
{ unsigned r;
   for (r=0;isHexDigit(*s);s++)
      r=r*16+((*s>='0'&&*s<='9')?*s-'0':*s-'a'+10);
   return r;
}

char *find0x(char *s)
{ for (;*(s+1);s++)
      if (*s=='0' &&*(s+1)=='x'&&isHexDigit(*(s+2)))
         return s;
   return 0;
}

int main()
{  char s[N+1],*p=s; unsigned cnt=0,a[N/3],i;
    scanf("%s",s);
    while (p=find0x(p))  a[cnt++]=getHex(p+=2);
    if (cnt) for (i=0;i<cnt;i++) printf("%u%c",a[i],i<cnt-1?' ':'\n');
    else printf("-1\n");
   return 0;
}