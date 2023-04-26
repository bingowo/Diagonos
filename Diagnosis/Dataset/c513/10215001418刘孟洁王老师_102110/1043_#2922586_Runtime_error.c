#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cnt(char s[])
{
    int i = 0,num = 0;
    for( i = 0; i < strlen(s)-1; i++)
    {
        if(s[i] == s[i+1])num++;
    }
    return num;
}

int main()
{
    char s1[103],t[101][103];
    int n,i,j,k,ans,num = 0;
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%s",s1);
        for(j = 2; j < strlen(s1); j++)
        {
            if(s1[j] != s1[j-1]&&s1[j] != s1[j+1]&&s1[j-1] == s1[j+1]&&s1[j-2] != s1[j-1]&&s1[j+2] != s1[j+1])
             {
                 for(k = 0; k <= j; k++)t[num][k] = s1[k];
                 t[num][j+1] = s1[j];
                 for(k = j+2; k <= strlen(s1); k++)t[num][k] = s1[k-1];
                 t[num][k] = '\0';
                 break;
             }
        }
        if(j == strlen(s1))
            {
                for(k = 0; k < strlen(s1); k++)t[num][k] = s1[k];
                t[num][k] = s1[k-1];
                t[num][k+1]= '\0';
            }
        k = 0;
        ans = 1;
        printf("%d\n",cnt(t[num]));
        printf("%s\n",t[num]);
        while(cnt(t[num]))
        {
            for( j = 0; j <= strlen(t[num]); j++)
            {
                if(t[num][j] == t[num][j+1]||t[num][j] == t[num][j-1])ans++;
                else if(t[num][j] != t[num][j+1])
                {t[num+1][k] = t[num][j] == t[num][j-1]?t[num][j+1]:t[num][j];k++;}
            }
            num++;
       }
        printf("case #%d:\n",i);
         //printf("%d\n",ans);
        for(j = 0; j < num+1; j++)
            for(k = 0; k < 103; k++)t[j][k] = '\0';
    }
   return 0;
}
