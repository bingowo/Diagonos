#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int judge(char*s,int*sign)
{
    int i;

    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='!')
        {
            int c[100]={0};
            if(i+3<strlen(s)){c[s[i+1]]=1;c[s[i+2]]=1;c[s[i+3]]=1;}
            else if(i+1>strlen(s)-1){c[s[i-1]]=1;c[s[i-2]]=1;c[s[i-3]]=1;}
            else if(i+2>strlen(s)-1){c[s[i+1]]=1;c[s[i-2]]=1;c[s[i-1]]=1;}
            else if(i+3>strlen(s)-1){c[s[i+1]]=1;c[s[i+2]]=1;c[s[i-1]]=1;}
            if(c['!']==0)
            {
                if(c['R']==0){s[i]='R';sign['R']++;}
                else if(c['Y']==0){s[i]='Y';sign['Y']++;}
                else if(c['B']==0){s[i]='B';sign['B']++;}
                else {s[i]='G';sign['G']++;}
            }
        }
    }
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='!')
        {
            int c[100]={0};
            if(i>=3){c[s[i-1]]=1;c[s[i-2]]=1;c[s[i-3]]=1;}
            else if(i==0){c[s[2]]=1;c[s[3]]=1;c[s[1]]=1;}
            else if(i==1){c[s[0]]=1;c[s[2]]=1;c[s[3]]=1;}
            else if(i==2){c[s[0]]=1;c[s[1]]=1;c[s[3]]=1;}
            if(c['!']==0)
            {
                if(c['R']==0){s[i]='R';sign['R']++;}
                else if(c['Y']==0){s[i]='Y';sign['Y']++;}
                else if(c['B']==0){s[i]='B';sign['B']++;}
                else {s[i]='G';sign['G']++;}
            }
        }
    }
    for(i=0;i<strlen(s);i++)if(s[i]=='!')break;
    if(i==strlen(s))return 0;
    else return 1;
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
}
