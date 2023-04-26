#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char table[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void getbyte(char ch,char s[])
{
    int r = strlen(s);
    for (int i=7;i>=0;i--) s[r++] = ((ch>>i)&1)+'0';
}

main()
{
    int n; scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        char ans[201] = {}; int index = 0;
        char s[101] = {}; scanf("%s",s);
        char store[5001] = {};
        for (int j=0;s[j];j+=3)
        {
            for (int k=0;k<3&&s[j+k];k++) getbyte(s[j+k],store);
            if (strlen(store)%6!=0)
            {
                int complete = 6-strlen(store)%6;
                int p = strlen(store);
                for (int q=0;q<complete;q++) store[p+q] = '0';
            }
            int help = strlen(store)/6;
            for (int k=0;store[k]&&help;k+=6,help--)
            {
                char t[7] = {};
                for (int p=0;p<6;p++) t[p] = store[k+p];
                ans[index++] = table[strtol(t,NULL,2)];
            }
            memset(store,0,sizeof(store));
            while (index%4!=0) ans[index++] = '=';
        }
        ans[index] = '\0';
        printf("case #%d:\n%s\n",i,ans);
    }
    return 0;
}