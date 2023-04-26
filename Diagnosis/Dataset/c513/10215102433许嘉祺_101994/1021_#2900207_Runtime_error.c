#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char c[27];
    char c1[200];
    char s[25];
    char s1[100][20];
    char s2[100][20];
    while ((scanf("%s",c))!=EOF)
    {
        for (int i=0; i<26; i++)
        {
            c1[c[i]-'A'+'a']='a'+i;
            c1[c[i]]='a'+i;
        }
        int n=0,len=0;
        char d;
        d=getchar();
        while ((d=getchar())!='\n')
        if (d==' ') {s1[n++][len]=0;len=0;}
            else s1[n][len++]=d;
        s1[n][len]=0;
        for (int i=0;i<=n;i++){
        for (int j=0;j<strlen(s1[i]);j++)
            s2[i][j]=c1[s1[i][j]];
        s2[i][strlen(s1[i])]=0;
        }

        for (int i=0;i<=n-1;i++){
            int t=i;
            for (int j=i+1;j<=n;j++)
                if (strcmp(s2[j],s2[t])<0) t=j;
            if (t!=i) {
                char m[21];
                strcpy(m,s2[t]);
                strcpy(s2[t],s2[i]);
                strcpy(s2[i],m);
                strcpy(m,s1[t]);
                strcpy(s1[t],s1[i]);
                strcpy(s1[i],m);
            }
        }
        for (int i=0;i<=n-1;i++)
            printf("%s ",s1[i]);
        printf("%s\n",s1[n]);
    }

    return 0;
}