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

int pipei(char*s)
{
    int len=strlen(s),i,j;
    if(len<=0) return 1;
    if((len%2)!=0) return -1;
    char x[120];
    memset(x,0,sizeof(char)*120);
    strcpy(x,s);
    for(i=0;i<len;i++)
    {
        if(x[i]==')')
        {
            if(x[i-1]=='(')
            {
                for(j=i-1;j<len-2;j++)
                {
                    x[j]=x[j+2];
                }
                x[j]=0;
                //printf("test:x=%s\n",x);
                return pipei(x);
            }
            else return -1;
        }
        else if(x[i]==']')
        {
            if(x[i-1]=='[')
            {
                for(j=i-1;j<len-2;j++)
                {
                    x[j]=x[j+2];
                }
                x[j]=0;
                //printf("test:x=%s\n",x);
                return pipei(x);
            }
            else return -1;
        }
        else if(x[i]=='}')
        {
            if(x[i-1]=='{')
            {
                for(j=i-1;j<len-2;j++)
                {
                    x[j]=x[j+2];
                }
                x[j]=0;
                //printf("test:x=%s\n",x);
                return pipei(x);
            }
            else return -1;
        }


    }


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
       //if(i==13) printf("s=%s",s);
       int len=strlen(s);
       re=pipei(s);
       if(re==1) re=jud(s);
       if(re==-1) printf("No\n");
       else if(re==1) printf("Yes\n");

   }
   return 0;
}
