#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
void f(char* s,char* comb)
{
    if(*s)
    {char left[17]="";
    sprintf(left,"%s%c",comb,s[0]);
    printf("%s\n",left);
    f(s+1,left);
    f(s+1,comb);
    }
}
int main()
{
   int i,n,k,j;
   char s0[17],s[17]="",c;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       j=0;
       scanf("%s",s0);
       for(c='A';c<='Z';c++)if(strchr(s0,c)!=NULL)s[j++]=c;
       for(c='a';c<='z';c++)if(strchr(s0,c)!=NULL)s[j++]=c;
       printf("case #%d:\n",i);
       f(s,"");
   }

}
