#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char s[20],s1[20]={'0'},s2[20]={'0'};
    char t[20];
    scanf("%s",s);
    int r=0,len=0;
    int k=0,i=0,j=0;
    long long int qr=1,qi=1,a=0,b=0;
    if(strchr(s,'i')==0)
    {
        a=(long long int)atoi(s);
        b=0;
        k=-1;
        while(a || b)
        {
            if(a%2==0 && b%2==0)
			{
				t[++k]='0';
				r=0;
			}
			else if(a%2 !=0 && b%2!=0)
            {
                t[++k]='0';
				r=0;
            }
			else
			{
				t[++k]='1';
				r=1;
			}
            qi=(r-a-b)/2;
            qr=b+qi;
            a=qr;b=qi;
        }
    }
    else
    {
        while(s[i++]!='+');
        
        for(j=0;j<i-1;j++)
            s1[j] = s[j];
            
        if(s[i] == 'i') s2[0] = '1';
		else
		{
			k=0;
			for(j=i;j<strlen(s)-1;j++)
            	s2[k++] = s[j];
		} 
        
        a=(long long int)atoi(s1);
        b=(long long int)atoi(s2);
        k= -1;
        while(a || b)
        {
            if(a%2==0 && b%2==0)
			{
				t[++k]='0';
				r=0;
			}
			else if(a%2 !=0 && b%2!=0)
            {
                t[++k]='0';
				r=0;
            }
			else
			{
				t[++k]='1';
				r=1;
			}
            qi=(r-a-b)/2;
            qr=b+qi;
            a=qr;b=qi;
        }
    }
    len=strlen(t);
    for(i=len-1;i>=0;i--)
    {
        printf("%c",t[i]);
    }
    return 0;
}
