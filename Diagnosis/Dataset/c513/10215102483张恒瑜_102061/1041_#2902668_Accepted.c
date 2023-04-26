#include<stdio.h>
#include<string.h>

int main()
{
    char in[100]={'\0'};
    scanf("%s",in);
    int i=0,max=1,cnt=1;
    for(i=0;i<strlen(in)-1;i++)
    {
        if(in[i]=='|')
        {
            if(in[i+1]=='-') cnt++;
            else cnt=1;
        }
        if(in[i]=='-')
        {
            if(in[i+1]=='|') cnt++;
            else cnt=1;
        }
        if(cnt>max) max=cnt;
    }
    printf("%d",max);
    return 0;
}