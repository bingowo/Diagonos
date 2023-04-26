#include<stdio.h>
#include<string.h>
int main()
{
    int max,min;
    char s[1000];
    scanf("%s",s);
    while(s!=EOF)
    {
        char res[300][300];
        for(int i=0;i<300;i++) for(int j=0;j<300;j++) res[i][j]=' ';
        int flag=150;
        max=flag;
        min=flag;
        for(int i=0;i<strlen(s);i++)
        {
            if(i==0) res[150][0]=s[0];
            else
            {
                if(s[i]>s[i-1]) flag++;
                if(s[i]<s[i-1]) flag--;
                if(flag>max) max=flag;
                if(flag<min) min=flag;
                res[flag][i]=s[i];
            }
        }
        for(int i=min;i<=max;i++)
        {
            for(int j=299;j>=0;j--)
            {
                if(res[i][j]!=' ')
                {
                    res[i][j+1]='\0';
                    break;
                }
            }
        }
        for(int i=max;i>=min;i--) printf("%s\n",res[i]);
        scanf("%s",s);
    }
}