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
        	for(int j=i;j<l;j++)
        	{
        		if(s[j]-'0'<10)
        		{
        			t++;
        			i++;
				}
				else
				{
					if(max<t)
					{
						max=t;
					}
					i=i+t;
					t=0;
					continue;
				}
			}

		}
    }
    if(max<t)
    {
    	max=t;
	}
    printf("%d",max);
    return 0;
}