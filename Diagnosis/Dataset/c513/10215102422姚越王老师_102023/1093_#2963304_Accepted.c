#include<string.h>
#include<stdio.h>
#define C 1000
int total(const char* s)
{
    int n=0;
    for(int i=0;s[i];++i)n+=s[i]-48;
    return n;
}
void get_ans(char* s);
int main()
{
    char s[C],tmp[C];scanf("%s",s);
    strcpy(tmp,s);
    get_ans(s);
    while(!(strcmp(tmp,s)))
    {
    	s[strlen(s)-1]++;
    	get_ans(s);
	}
    printf("%s",s);
    return 0;
}
void get_ans(char* s)
{
    int i,j,len=strlen(s);
    for(i=0;s[i];++i)
    {
        if(s[i]=='9')
        {
            if(!i)
            {
                for(j=len;j>0;--j)s[j]=s[j-1];
                s[0]='1';s[1]='0';
                for(j=2;j<=len;j++)s[j]='0';
                s[len+1]='\0';
                get_ans(s);
                return;
            }
            else
            {
                s[i-1]++;s[i]='0';
                for(j=i+1;j<len;j++)s[j]='0';
                get_ans(s);
                return;
            }
        }
    }
    if(!(total(s)%9))
    {
        s[len-1]++;
        if(s[len-1]=='9')get_ans(s);
        return;
    }
    return;
}