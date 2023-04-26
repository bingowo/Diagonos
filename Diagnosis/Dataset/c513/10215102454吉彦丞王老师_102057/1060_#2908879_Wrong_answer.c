#include<stdio.h>
#include<string.h>
int main()
{
    int max=0;
    char s[100];
    scanf("%s",&s);
    int l=strlen(s);
    int t=0;
    for(int i=0;i<l;i++)
    {
        if(s[i]-'0'<10&&s[i]-'0'>0)
        {
        	if(s[i+1]-'0'<10)
        	{
        		t++;
			}
			else
			{
				if(max<t)
            	{
                	max=t;
            	}
            	t=0;
            	i++;
            	continue;
			}
		}
    }
    if(max<t)
    {
    	max=t;
	}
    printf("%d",max+1);
    return 0;
}