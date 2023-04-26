#include<stdio.h>

int main()
{
    while(1 == 1)
    {
        char s[9];
        unsigned long long int n=0,len,ans;
        scanf("%s",s);
        if(n==0)
            break;
        len=str(s);
        if(len<3)//可计算n
        {
            for(int i=0;i<len;i++)
        	{
            	n+=s[i];
                n = n*10;
        	}
            unsigned long long int temp;
            temp=(int)pow(10,len);
            ans=n/temp;
        }
        else
        {
            unsigned long long int temp;
            temp=(s[0]-'0')*(s[0]-'0')+((s[1]-'0')*(s[1]-'0')+(s[2]-'0')*(s[2]-'0')/10+5)/10;
            if(temp/10 > 0)
                ans=temp/10;
            else
                ans=temp;
        }
        printf("%llu\n",ans);
        
    }
    return 0;
    
}
