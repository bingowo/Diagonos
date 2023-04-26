#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char s[1000]={'0'},s1[1000]={'0'},s2[1000]={'0'};
    char t[1000]={'0'};
    scanf("%s",s);
    int r=0,len=0;
    int k=0,i=0,j=0;
    long long int qr=1,qi=1,a=0,b=0;
    i=1;
    while(s[i++] != '-' && i<=strlen(s));
    if(strchr(s,'+')==0 && i==strlen(s)+1)
    {
        if(strchr(s,'i')==0)
        {
            a=(long long int)atoll(s);
            b=0;
        }
        else
        {
            a=0;
            if(s[0] == 'i') b=1;
            else if (s[0]=='-' && s[1]=='i') b=-1;
            else
                b=(long long int)atoll(s);
        }
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
        i=0;
        while((s[++i]!='+') && (s[i]!='-'));

        for(j=0;j<i;j++)
            s1[j] = s[j];
        if(i==0) s1[0]='0';
        if(s[i] == 'i') s2[0] = '1';
		else
		{
			k=0;
			for(j=i;j<strlen(s);j++)
            	s2[k++] = s[j];
		}

        a=(long long int)atoll(s1);
        if(s2[0]=='+' && s2[1]=='i')b =1;
        else if(s2[0]=='-' && s2[1]=='i' ) b=-1;
        else b=(long long int)atoll(s2);
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
