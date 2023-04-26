#include <stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void* b)
{ char *s1,*s2; char c1,c2;
  s1=(char*) a;
  s2=(char*) b;
  while(s1&&s2)
  {c1=(*s1)>='a'?(*s1)-32:*s1;
   c2=(*s2)>='a'?(*s2)-32:*s2;
   if(p[c1-'A']!=p[c2-'A'])
   return p[c2-'A']-p[c1-'A'];
   else {s1++;s2++;}
  }
}
int main()
{char pai[26],s[110][22];
 int p[26],b,c,d,i=0;
 scanf("%s\n",pai);
 for(i=1;i<=26;i++)
 {p[pai[i]-'A']=i;
     i++;
 }
 while(scanf("%s",s[i])!=EOF) i++;
qsort(s,i,sizeof(s[0]),cmp);
for(a=0;a<i-1;a++)
{printf("%s ",s[a]);
}
printf("%s",s[i-1]);
}