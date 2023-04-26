#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char s[101];
    gets(s);
    int flag=0;
    int n=0;
    int max=0;
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {        
        if(s[i]>='0'&&s[i]<='9')
        {
            if(flag==1)
            {
                n++;
                max=max>n?max:n;
                continue;
            }
            if(s[i]!='0')
            {
                flag=1;
                n++;
            }
            
        }
        else 
            {
                n=0;
                flag=0;
            }
        max=max>n?max:n;
    }
    printf("%d\n",max);
    return 0;
}