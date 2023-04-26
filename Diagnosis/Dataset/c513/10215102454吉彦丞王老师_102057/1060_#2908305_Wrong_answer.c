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
        if(s[i]-'0'<10)
        {
            if(s[i]=='0')
            {
            	if(i==0)
            	{
            		continue;
				}
				else if(s[i-1]-'0'>10)
				{
					continue;
				}
				else if(s[i-1]=='0')
				{
					for(int j=i-1;j>=0;j--)
					{
						if(s[j]=='0')
						{
							continue;
						}
						else
						{
							if(s[j]-'0'<10)
							{
								t++;
							}
							else
							{
								break;
							}
						}	
					}
				}
				else
				{
					t++;
				}
			}
			else
			{
				t++;
			}
        }
        else
        {
            if(max<t)
            {
                max=t;
            }
            t=0;
            continue;
        }
    }
    printf("%d",max);
    return 0;
}