#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char s[55];
    int i=0,sum=0,count=1;
    scanf("%s",s);
    int l=strlen(s);
    if(l==1) printf("1");
    else
    {
        for(i=1;i<l;i++)
      {
        if(s[i]!=s[i-1])  count++;
        else  count=1;
        if(sum<count) sum=count;
      }
      if(sum<count) sum=count;
      printf("%d",sum);
    }
    return 0;
}
