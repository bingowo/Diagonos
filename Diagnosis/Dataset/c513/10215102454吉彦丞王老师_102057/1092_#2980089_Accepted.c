#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000];
    scanf("%s",&s);
    int l=strlen(s);
    unsigned long long a[l];
    int b[l];
    for(int i=0;i<l;i++)
    {
        b[i]=0;
    }
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
            	else if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1])
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
            	else if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1])
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
    	} 		
		b[0]=1;
		for(int i=0;i<l;i++)
		{
	    	for(int j=0;j<l;j++)
	    	{
	        	b[j]=b[j]*a[i];
	    	}
	    	for(int k=1;k<l;k++)
	    	{
	        	while(b[k-1]>=10)
	        	{
	            	b[k]=b[k]+b[k-1]/10;
	            	b[k-1]=b[k-1]%10;
	        	}
	    	}
		}
		int t=0;
		for(int i=l-1;i>=0;i--)
		{
			//printf("%d",b[i]);
	    	if(b[i]==0)
	    	{
	        	t++;
	    	}
	    	else
	    	{
	    		break;
			}
		}
		for(int i=l-1-t;i>=0;i--)
		{
	    	printf("%d",b[i]);
		}
 	}
    return 0;
}