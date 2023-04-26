#include <stdio.h>
#include <ctype.h>

int main()
{
    int t;
    scanf("%d",&t);
    char c=getchar();
    for(int j=0; j<t; j++)
    {
       int index=0;
       char alphamap[100]={0};
       char s[210];
       gets(s);
       for(int i=0; s[i]; i++)
       {
           if(isalpha(s[i]))
            alphamap[s[i]]+=1;
       }
       for( index=64;alphamap[index]==0;index++);
       for(int i=0; s[i]; i++)
       {
           if(isalpha(s[i]))
           {
           s[i]=index;
           alphamap[index]--;
           if(alphamap[index]==0) 
           for(;alphamap[index]==0;index++);
           }
       }
       printf("case #%d:\n",j);
       printf("%s\n",s);
    }
return 0;
}