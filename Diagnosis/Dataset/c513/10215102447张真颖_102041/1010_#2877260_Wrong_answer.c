#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert(char s[],char r[])
{
   int len=strlen(s),x=0,y,i=0;
   char ss[10];
   while(i<len)
   {
      if(len-i==2)
      {
          x=(s[i]-'0')*10+(s[i+1]-'0');
          for(int j=0;j<7;j++)
          {
              if((x<<j)&1) ss[6-j]='1';
              else ss[6-j]='0';
          }

      }
      else if(len-i==1)
      {
          x=s[i]-'0';
          for(int j=0;j<4;j++)
          {
              if((x<<j)&1) ss[3-j]='1';
              else ss[3-j]='0';
          }
      }
      else
      {
          x=(s[i]-'0')*100+(s[i+1]-'0')*10+(s[i+2]-'0');
          for(int j=0;j<10;j++)
          {
              if((x<<j)&1) ss[9-j]='1';
              else ss[9-j]='0';
          }
      }
      r=strcat(r,ss);
      i+=3;
   }
}

int main()
{
    char s[500],r[1667]={0},ss[10];
    scanf("%s",s);
    convert(s,r);
    int len=strlen(s);
    for(int i=0;i<10;i++)
    {
        if((len>>i)&1) ss[9-i]='1';
        else ss[9-i]='0' ;
    }
    printf("0001%s%s\n",ss,r);
    return 0;
}
