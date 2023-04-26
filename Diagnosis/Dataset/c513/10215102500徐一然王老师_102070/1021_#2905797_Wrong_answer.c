#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int p[26];

int cmp(const void*a,const void*b)
{
    char *p1=(char *)a;
    char *p2=(char *)b;
    while(*p1&&*p2)
    {

        char s1,s2;
        int x,y;
        s1=toupper(*p1);
        s2=toupper(*p2);
        x=p[s1-'A'];
        y=p[s2-'A'];
        if(x!=y)
        {
            return x-y;
        }
        else
        {
            p1++;
            p2++;
        }

    }
    if(*p1=='0')
        return 1;
    else return -1;

}

int main()
{

     char s[27];
     while(scanf("%s\n",s)!=EOF)
    {     for(int i=0; i<26; i++)
             p[s[i]-'A']=i;
          char str[2200];
          char a[100][21];
          int count=0;
          int i=0;
          gets(str);
          while(1)
          {
              int j=0;
              while(str[i]!=' '&&str[i])
              {
                  a[count][j++]=str[i++];
              }
              a[count][j]='\0';
              count++;
              if(!str[i]) break; else i++;
          }
          qsort(a,count,sizeof(a[0]),cmp);
          for(int i=0;i<count;i++)
          {
              if(i==count-1)
              {
                  printf("%s\n",a[i]);
              }
              else
              printf("%s ",a[i]);
          }


     }


}
