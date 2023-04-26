#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[60];
    scanf("%s",s);
    int number=0,count=0,i,m;
    for(m=0;s[m];m=m)
    {
        count=0;
      for(i=m;s[i];i++)
    {
        if(s[i]=='|' && s[i+1] && s[i+1]=='|'){count++;break;}
        else if(s[i]=='-' && s[i+1] && s[i+1]=='-'){count++;break;}
        else count++;
    }
    if(count==0)m++;
    else m=m+count;
    if(number>count)number=number;
    else number=count;
    }
    printf("%d",number);

    return 0;
}
