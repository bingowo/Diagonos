#include<stdio.h>
#include<string.h>

int main()
{
    
    char origin[10];
    scanf("%s",origin);
    
    int time,mark=1;
    
    for(time=1;mark==1;time++)
    {//每遍循环得到新的origin
        int n=0,len;
        len = strlen(origin);
    	for(int i=0;i<len;i++)
    	{
        	n += (origin[i]-'0');
        	n = n*10;
    	}
    	n = n/10;//给n赋值
    	int m=0;
    	for(int i=len-1;i>-1;i--)
    	{
        	m += (origin[i]-'0');
        	m = m*10;
    	}
    	m = m/10;//给m赋值
        int new;
        new = n+m;
        int length;
        int temp=new;
        for(length=0;temp != 0;length++)
        {
            temp = temp/10;
        }//得到new值的长度length
        char s[length];
        int tmpt=new;
        for(int i=0;i<length;i++)
        {
            s[length-i-1]= '0' + (tmpt%10);
            tmpt = tmpt/10;
        }//给s赋值
        
        if(length%2 == 0)//length为偶数
        {
            for(int i=0;i<(length/2);i++)
        	{
            	if(s[i] == s[length-1-i])
                    mark=0;//是回文数，mark为0
            	else
                {
                    mark = 1;
                    break;
                }
        	}
        }
        else//length为奇数
        {
            for(int i=0;i<(length/2);i++)
            {
                if(s[i] == s[length-1-i])
                    mark=0;//是回文数，mark为0
                else
                {
                    mark = 1;
                    break;
                }
            }
        }
        
        if(mark == 1)
            strcpy(origin,s);
        else
        {
            printf("%d ",time);
    		printf("%s",s);
        }
    }
    return 0;
}

