#include <stdio.h>
#include <stdlib.h>
int p[27];
int cmp(const void*a,const void* b)
{ char *s1,*s2; char c1,c2;
  s1=(char*) a;
  s2=(char*) b;
  while(*s1&&*s2)
  {c1=(*s1)>='a'?(*s1)-32:*s1;
   c2=(*s2)>='a'?(*s2)-32:*s2;
   if(p[c1-'A']!=p[c2-'A'])
   return p[c2-'A']-p[c1-'A'];
   else {s1++;s2++;}
  }
  if(*s1==0) return -1;
  else return 1;
}
int main()
{char pai[26],s[110][22],str[2200];
 int b,c,d,i=0,a,count,k,j;
 while(scanf("%s",pai)!=EOF)
 {
 for(i=1;i<=26;i++)
 {p[pai[i]-'A']=i;
     i++;
 }
 gets(str);
 count=0;k=0;
 while(1)
 { j=0;
  while(str[k]!=' '&&str[k]) s[count][j++]=str[k++];
  s[count][j]='\0';
  count++;
    if(str[k]=='\n') break; 
 }
qsort(s,count,sizeof(s[0]),cmp);
for(a=0;a<count-1;a++)
{printf("%s ",s[a]);
}
printf("%s\n",s[count-1]);
}
}