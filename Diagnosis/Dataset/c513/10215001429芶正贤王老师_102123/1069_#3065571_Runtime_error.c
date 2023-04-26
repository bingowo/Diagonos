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
    
    int m,new;
    char M[len];
    int time=0,mark=0;
    
    do
    {
    	if(len%2 == 0)//偶数位
    	{
        	for(int i=0;i<len/2;i++)
        	{
            	if(origin[i] == origin[len-1-i]);
            	else
            	{
                	mark=1;
                	break;
            	}
        	}
    	}
    	else//奇数位
    	{
        	for(int i=0;i<len/2;i++)
        	{
            	if(origin[i] == origin[len-1-i]);
            	else
            	{
                	mark=1;
                	break;
            	}
        	}
    	}
    	m=0;
    	if(mark == 1)
        {
            time++;
            for(int i=0;i<len;i++)//对M赋值
    		{
        		M[i]=origin[len-1-i];
        		m += (M[i]-'0');
        		m = m*10;
    		}
    		new = n+m;
    		char s[5];
    		int LEN;
    		LEN = new/10;
    		for(int i=0;i<LEN;i++)
    		{
        		int temp=new;
        		s[LEN-1-i] = '0' + temp%10;
        		temp = temp/10;
    		}
            n = new;
            len = LEN;
            strcpy(origin,s);
        }
            
        
    }while(mark == 1);
    printf("%d",n);
    
    return 0;
}

