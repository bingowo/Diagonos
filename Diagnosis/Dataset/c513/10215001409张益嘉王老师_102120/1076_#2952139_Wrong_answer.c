#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int judxiao(char *s);
int judzhong(char*s);
int judda(char*s);
int jud(char*s);
int judsmall(char*s);
int judmid(char*s);
int judbig(char*s);

int judxiao(char *s)
{
   if(s[0]==')') return judsmall(s+1);
   else if(s[0]=='{') return judda(s+1);
   else return -1;
}

int judsmall(char*s)
{
    if(strlen(s)<=0) return 1;
    else if(s[0]==']') return judmid(s+1);
    else if(s[0]=='(') return judxiao(s+1);
    else if((s[0]=='[')||(s[0]=='{')) return jud(s);
    else return -1;
}

int judzhong(char*s)
{
    if(s[0]==']') return judmid(s+1);
    else if(s[0]=='(') return judxiao(s+1);
    else return -1;
}

int judmid(char*s)
{
    if(strlen(s)<=0) return 1;
    else if(s[0]=='[') return judzhong(s+1);
    else if(s[0]=='}') return judbig(s+1);
    else if((s[0]=='(')||(s[0]=='{')) return jud(s);
    else return -1;
}

int judda(char*s)
{
    if(s[0]=='}') return jud(s+1);
    else if(s[0]=='[') return judzhong(s+1);
    else return -1;
}

int judbig(char*s)
{
    if(strlen(s)<=0) return 1;
    else if(s[0]=='{') return judda(s+1);
    else if(s[0]==')') return judsmall(s+1);
    else if((s[0]=='(')||(s[0]=='[')) return jud(s);
    else return -1;
}

int jud(char*s)
{
    int re,len=strlen(s),i;

    if(strlen(s)<=0) return 1;
    else if(s[0]=='(') return judxiao(s+1);
    else if(s[0]=='[') return judzhong(s+1);
    else if(s[0]=='{') return judda(s+1);
    else return -1;


}

int main()
{
   int i,t;
   scanf("%d",&t);
   for(i=0;i<t;i++)
   {
       char s[120];
       int re=0;
       memset(s,0,sizeof(char)*120);
       scanf("%s",s);
       re=jud(s);
       if(re==-1) printf("No\n");
       else if(re==1) printf("Yes\n");

   }
}
