#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char s[20];
    char t[20];
    scanf("%s",s);
    int r=0;
    int k=-1;
    long long int qr=1,qi=1,a=0,b=0;
    if(strchr(s,'i')==0)
    {
        a=(long long int)atoi(s);
        b=0;
        while(a || b)
        {
            if(a%2==0 && b%2==0)
			{
				t[++k]=0;
				r=0;
			}
			else if(a%2 !=0 && b%2!=0)
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
        t[++k]= '\0';
        printf("%s\n",t);

    }
    return 0;
}
