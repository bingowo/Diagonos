#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    scanf("%s",s);
    int start=0,end=0,max=1;
    for(int i=0;i<strlen(s)-1;i++)
    {
        if(s[i]!=s[i+1])
        {
            end=i+1;
            if(end-start+1>max) max=end-start+1;
            continue;
        }
        if(s[i]==s[i+1])
        {
            if(end-start+1>max)
            {
                max=end-start+1;
            }
            start=i+1;
            end=i+1;
        }
    }
    printf("%d",max);
}
