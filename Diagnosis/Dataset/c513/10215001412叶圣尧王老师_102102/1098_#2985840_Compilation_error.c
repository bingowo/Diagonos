#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void judge(char*s,int*d)
{
    int i;int c[100]={0};
    for(i=0;i<strlen(s)-3;i++)
    {
        if(s[i]=='!')
        {
            c[s[i+1]]=1;c[s[i+2]]=1;c[s[i+3]]=1;
            if(c['!']==0)
            {
                if(c['R']==0){s[i]='R';sign['R']++;}
                else if(c['Y']==0){s[i]='Y';sign['Y']++;}
                else if(c['B']==0){s[i]='B';sign['B']++;}
                else {s[i]='G';sign['G']++;}
            }
        }
    }
}

int main()
{
    int T;scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        char s[101];scanf("%s",s);
        int sign[100]={0};
        while(judge(s,sign));
        printf("%d %d %d %d\n",sign['R'],sign['B'],sign['Y'],sign['G']);
}