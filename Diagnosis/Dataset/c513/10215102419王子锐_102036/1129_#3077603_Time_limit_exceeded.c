#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char s[10006],t[10006];
    int k=0,sum=0,j,i,len;
    scanf("%s",s);
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]>='a'&&s[i]<='z') 
        { 
            t[k++]=s[i];t[k]='\0'; 
        }
        else
        {
            sum=0;
            while(s[i]>="0"&&s[i]<='9')
                sum=sum*10+s[i++]-'0';
        }
    for(j=1;j<=sum;j++)
                printf("%s",t);
            k=0;i=i-1;
    }
    if(k!=0) printf("%s",t);
    printf("\n");
    return 0;
}
