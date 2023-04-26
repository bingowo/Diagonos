#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void divorce(char s[])
{
   char r[150]={0};
   int rest=s[0]-'0',j=3;
   r[0]='0',r[1]='.';
   if(strlen(s)>1) rest=rest*10+s[2]-'0';
   else
    rest*=10;
   r[2]=rest/8+'0';
   rest%=8;
   for(int i=3;!(rest==0&&i>=strlen(s));i++)
   {
       int tmp=0;
       if(i<strlen(s)) tmp=s[i]-'0';
       if((rest*10+tmp)>=8)
       {
           r[j]=(rest*10+tmp)/8+'0';
           rest=(rest*10+tmp)%8;
           j++;
       }
       else
       {
           rest=s[i]-'0';
           r[j]='0';
           j++;
       }
   }
   r[j]=0;
   strcpy(s,r);
}

void convert(char s[],char t[])
{
    int len=strlen(s);

    for(int i=len-1;i>1;i--)
    {
        t[0]=s[i];
        divorce(t);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[52]="",t[152]="";
        scanf("%s",s);
        convert(s,t);
        printf("case #%d:\n",i);
        printf("%s\n",t);

    }
    return 0;
}
