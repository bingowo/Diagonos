#include<stdio.h>
#include<string.h>
int main()
{
    int max=0;
    char s[50];
    scanf("%s",&s);
    int l=strlen(s);
    if(l==1)
    {
        max=1;
    }
    int t=1;
    for(int i=0;i<l-1;i++)
    {
        if(s[i]!=s[i+1])
        {
            t++;
        }
        else
        {
            if(max<t)
            {
                max=t;
            }
            t=1;
            continue;
        }
    }
    if(max<t)
    {
    	max=t;
	}
    printf("%d",max);
    return 0;
}