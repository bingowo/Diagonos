#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 3
#define M 2
#define S 1

int main()
{
   int T,i;
   scanf("%d",&T);
   char a[101];
   for(i=0;i<T;i++)
   {
       scanf("%s",a);
       int sign=0,j,cnt=1,out=1;//判断括号是否成对
       int res[101];//判断括号是否优雅
       for(j=0;j<strlen(a);j++)
       {
           if(a[j]=='{')sign+=L;res[cnt++]=L;
           if(a[j]=='}')sign-=L;res[cnt++]=-1*L;
           if(a[j]=='[')sign+=M;res[cnt++]=M;
           if(a[j]==']')sign-=M;res[cnt++]=-1*M;
           if(a[j]=='(')sign+=S;res[cnt++]=S;
           if(a[j]==')')sign-=S;res[cnt++]=-1*S;
       }
       if(sign!=0){printf("No");continue;}
       else
       {
           for(j=0;j<cnt-1;j++)
           {
               if(res[j]==L){if(res[j+1]!=M){out=0;break;}}
               if(res[j]==M){if(res[j+1]!=S){out=0;break;}}
               if(res[j]==S){if(res[j+1]!=-S){out=0;break;}}
               if(res[j]==-1*M){if(res[j+1]!=M&&res[j+1]!=-1*L){out=0;break;}}
           }
       }
       if(out==0){printf("No\n");}
       else{printf("Yes\n");}
   }
    return 0;
}
