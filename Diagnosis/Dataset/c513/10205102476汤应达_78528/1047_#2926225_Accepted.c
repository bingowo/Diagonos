#include<stdio.h>
#include<string.h>

int main()
{
    int t;scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[501];scanf("%s",s);
        int cnt=1;
        printf("case #%d:\n",i);
        for(int p=0;p<(int)strlen(s);p++)
        {
            if(s[p]==s[p+1] && cnt<255) cnt++;
            else if(s[p]==s[p+1]) {printf("%d%c",cnt,s[p]);cnt=1;}
            else {printf("%d%c",cnt,s[p]);cnt=1;}
        }        
        printf("\n");
    }

    return 0;
}