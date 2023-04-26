#include <stdio.h>
#include <string.h>

#define  N 100

char *encode(char *buf, char *s)
{ static const char *TransTable="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  static int j[][4]={{4,-1},{10,2,-1},{16,8,0,-1}},
                 k[][5]={{6,0,-1},{12,6,0,-1},{18,12,6,0,-1}};
  int i,b=0,*p=j[strlen(s)-1]; char *q=s; while (*p!=-1) b+=*q++<<*p++;
  for (i=0,p=k[strlen(s)-1]; *p!=-1; i++,p++) buf[i]=TransTable[(b>>*p)&0x3f];
  while (i%4) buf[i++]='='; buf[i]=0;
  return buf;
}

char* substr(char *t,char *s,int beg,int len)
{ int i;  for (i=0;i<len&&s[beg+i];i++) t[i]=s[beg+i]; t[i]=0;  return t; }

void solve()
{  char s[N+1],r[(N/3+1)*4+1]="",t[4],buf[5]; int i,slen;
   for (scanf("%s",s), slen=strlen(s), i=0; i<slen/3+(slen%3!=0); i++)
      strcat(r,encode(buf,substr(t,s,i*3,3)));
   printf("%s\n",r);
}

int main()
{  int i,t;  scanf("%d\n",&t);
   for (i=0;i<t;i++) printf("case #%d:\n",i),solve();
   return 0;
} 