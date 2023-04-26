#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000000
int main()
{
    int T;
    scanf("%d",&T);
    int cnt=0;
    while(T)
    {
        
		char str[MAX];
        scanf("%s",str);
        int c=strlen(str);
        int i;
        int res=0;
        for(i=0; i<c; i++)
        {
            res*=3;
            if(str[i]=='1')
            {
                res+=1;
            }
            else if (str[i]=='0')
            {
                res+=0;
            }
            else if(str[i]=='-')
            {
                res+=-1;
            }

        }
        printf("case #%d:\n%d",cnt,res);
        T-=1;
        cnt+=1;

    }
    return 0;
}