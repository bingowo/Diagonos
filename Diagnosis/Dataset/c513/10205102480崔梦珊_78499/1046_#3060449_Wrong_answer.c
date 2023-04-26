#include<stdio.h>
#include<string.h>

int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        char c;
        char s[100][100];
        int j=0;
        int k=0;
        while((c=getchar())!='\n')
        {
            if(c==' ')
            {
                scanf("%s",s[k]);
                k++;
            }
            else
            {
                s[0][j]=c;
                j++;
                k=1;
            }
        }
        int ans=k;
        for(int p=0;p<k;p++)
        {
            if(strlen(s[p])==1&&(s[p][0]=='a'||s[p][0]=='A')) ans--;
            if(strlen(s[p])==2&&((s[p][0]=='a'||s[p][0]=='A')&&(s[p][1]=='n'||s[p][1]=='N'))) ans--;
            if(strlen(s[p])==2&&((s[p][0]=='o'||s[p][0]=='O')&&(s[p][1]=='f'||s[p][1]=='F'))) ans--;
            if(strlen(s[p])==3&&(s[p][0]=='t'||s[p][0]=='T')&&(s[p][1]=='h'||s[p][1]=='H')&&(s[p][2]=='e'||s[p][2]=='E')) ans--;
            if(strlen(s[p])==3&&(s[p][0]=='a'||s[p][0]=='A')&&(s[p][1]=='n'||s[p][1]=='N')&&(s[p][2]=='d'||s[p][2]=='D')) ans--;
            if(strlen(s[p])==3&&(s[p][0]=='f'||s[p][0]=='F')&&(s[p][1]=='o'||s[p][1]=='O')&&(s[p][2]=='r'||s[p][2]=='R')) ans--;
        }

        printf("case #%d:\n",i);
        printf("%d\n",ans);
    }
}
