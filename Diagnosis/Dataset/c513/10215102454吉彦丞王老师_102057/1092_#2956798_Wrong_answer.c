#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000];
    scanf("%s",&s);
    int l=strlen(s);
    int a[l];
    int result=1;
    if(l==1)
    {
    	printf("1");
	}
	else
    {
		if(s[0]==s[1])
    	{
        	a[0]=1;
        	for(int i=1;i<l-1;i++)
        	{
            	if(s[i]==s[i-1]&&s[i]==s[i+1])
            	{
                	a[i]=1;
            	}
            	else if(s[i]!=s[i-1]&&s[i]!=s[i+1])
            	{
                	a[i]=3;
            	}
            	else
            	{
                	a[i]=2;
            	}
        	}
        	if(s[l-2]==s[l-1])
        	{
            	a[l-1]=1;
        	}
        	else
        	{
            	a[l-1]=2;
        	}
        	for(int i=0;i<l;i++)
    		{
        		result=result*a[i];
    		}
    		printf("%d\n",result);
    	}
    	else
    	{
        	a[0]=2;
        	for(int i=1;i<l-1;i++)
        	{
            	if(s[i]==s[i-1]&&s[i]==s[i+1])
            	{
                	a[i]=1;
            	}
            	else if(s[i]!=s[i-1]&&s[i]!=s[i+1])
            	{
                	a[i]=3;
            	}
            	else
            	{
                	a[i]=2;
            	}
        	}
        	if(s[l-2]==s[l-1])
        	{
            	a[l-1]=1;
        	}
        	else
        	{
            	a[l-1]=2;
        	}
        	for(int i=0;i<l;i++)
    		{
        		result=result*a[i];
    		}
    		printf("%d\n",result);
    	} 
	}
    return 0;
}