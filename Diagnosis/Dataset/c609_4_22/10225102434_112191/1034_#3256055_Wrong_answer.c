#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char* Turn(char *p)
{
    int num = 0,sum = 0;
    while((*p!='0'||*(p+1)!='x')&&*p!='\0')
    {
        if(*p>='0'&&*p<='9')num = *p-'0';
        else if(*p>='a'&&*p<='f')num = *p-'a'+10;
        else if (*p>='A'&&*p<='F') num = *p-'A'+10;
        else
        {
            p++;
            break;
        }
        sum = sum*16+num;
        p++;
    }
    char*p2 = p;
    if(sum==0)return p2;
    printf("%d ",sum);
    return p2;
}
int main()
{
  char s[1000001] ;
  scanf("%s",s);
  char a[] = "0x";
  char*p1 = strstr(s,a);
        if(p1 == NULL)
      {
          printf("%d",-1);
          return 0;
      }
  while(*p1!='\0')
  {
      p1 = p1+2;
      p1 = Turn(p1);
  }
  return 0;
}
