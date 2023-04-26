#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    int t;
    scanf("%d",&t);
    double b[26];
    int a[26];
    char s[101];
    for (int i=0; i<t; i++)
    {
        for (int j=0; j<26; j++)
        {
            scanf("%lf",&b[j]);
            a[j]=j;
        }
        for (int j=0; j<25; j++)
        {
            int v=j;
            for (int k=j+1; k<26; k++)
                if (b[a[v]]<b[a[k]]||(b[a[v]]==b[a[k]]&&a[k]<a[v])) v=k;
            int m=a[v];
            a[v]=a[j];
            a[j]=m;
        }
        scanf("%s",s);
        int count[27];
        memset(count,0,sizeof(count));
        for (int j=0;j<strlen(s);j++)
            if (s[j]<='Z') count[s[j]-'A']++;
            else count[s[j]-'a']+=100;
        printf("case #%d:\n",i);
        for (int j=0;j<26;j++)
        {
            int x=a[j];
            while (count[x]>=100)
            {printf("%c",'a'+x);count[x]-=100;}
            while (count[x]>0)
            {
                printf("%c",'A'+x);count[x]--;
            }

        }
        printf("\n");
    }


    return 0;
}
