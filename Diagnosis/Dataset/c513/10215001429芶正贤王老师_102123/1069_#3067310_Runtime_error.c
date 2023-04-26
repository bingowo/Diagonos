#include<stdio.h>
#include<string.h>

int main()
{
    char origin[5];
    int n=0,len;
    scanf("%s",origin);
    len = strlen(origin);
    for(int i=0;i<len;i++)
    {
        n += (origin[i]-'0');
        n = 10*n;
    }
    n=n/10;
    
    int time=0,mark=0;
    int m=0,new;
    char M[len];
    int LEN;
    do
    {
        
    	
    	for(int i=0;i<len;i++)//对M赋值
    		{
        		M[i]=origin[len-1-i];
        		m += (M[i]-'0');
        		m = m*10;
    		}
    	m = m/10;
    	new = n+m;
    
    	
    	LEN = new/10;
    	char s[LEN];
    	for(int i=0,temp=new;i<LEN;i++)
    	{
        	s[LEN-1-i] = '0' + temp%10;
        	temp = temp/10;
    	}
    	
    	if(LEN%2 == 0)//偶数位
    	{
        	for(int i=0;i<LEN/2;i++)
        	{
            	if(s[i] == s[LEN-1-i]);
            	else
            	{
                	mark=1;
                	break;
            	}
        	}
    	}
    	else//奇数位
    	{
        	for(int i=0;i<LEN/2;i++)
        	{
            	if(s[i] == s[LEN-1-i]);
            	else
            	{
                	mark=1;
                	break;
            	}
        	}
    	}
        
    	if(mark == 1)
        {
            time++;
            
            n = new;
            len = LEN;
            strcpy(origin,s);
        }
            
        
    }while(mark == 1);
    
    printf("%d %d",time,n);
    
    return 0;
}

