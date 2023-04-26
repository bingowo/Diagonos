#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char s[1000];
    char t[1000];
    scanf("%s",s);
    int r=0;
    int k=-1;
    long long int qr=1,qi=1,a=0,b=0;
    if(strchr(s,'i')==0)
    {
        a=(long long int)atoi(s);
        b=0;
        while(qi!=0 && qr!=0)
        {
            if(a%2==0)
			{
				t[++k]=0;
				r=0;
			}
			else 
			{
				t[++k]=1;
				r=1;
			}
            qi=(r-a-b)/2;
            qr=b+qi;
            a=qr;b=qi;
        }
        printf("%s",t);
        
    }
    return 0;
}