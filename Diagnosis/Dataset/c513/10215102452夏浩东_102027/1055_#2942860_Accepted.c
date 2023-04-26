#include <stdio.h>
char s[1000001]={'\0'};
int main()
{
    int maxlen=0,temend=0,temlen=0,maxend=0;
    scanf("%s",s);
    int begin=0;
    for(int i=0;s[i]!='\0';i++)
    {
        int repeat=0;
        for(int j=begin;j<i;j++)
        {
            if(s[i]==s[j]) {repeat=1;begin=j+1;break;}
        }
        if(repeat==1)
		{
            if(maxlen<temlen) maxend=temend;
            maxlen=maxlen>temlen?maxlen:temlen;
            temlen=i-begin+1;
		}
        else {
        	temlen++;
			temend=i;
		}
    }
    if(maxlen<temlen) maxend=temend;
    maxlen=maxlen>temlen?maxlen:temlen;
    for(int i=maxend-maxlen+1;i<=maxend;i++)
    {
        printf("%c",s[i]);
    }
    return 0;
}