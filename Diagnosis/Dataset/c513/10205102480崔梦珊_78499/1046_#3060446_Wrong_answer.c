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
            if(strlen(s[p])==1&&s[p][0]=='a') ans--;
            if(strlen(s[p])==2&&s[p][0]=='a'&&s[p][1]=='n') ans--;
            if(strlen(s[p])==2&&s[p][0]=='o'&&s[p][1]=='f') ans--;
            if(strlen(s[p])==3&&s[p][0]=='t'&&s[p][1]=='h'&&s[p][2]=='e') ans--;
            if(strlen(s[p])==3&&s[p][0]=='f'&&s[p][1]=='o'&&s[p][2]=='r') ans--;
            if(strlen(s[p])==3&&s[p][0]=='a'&&s[p][1]=='n'&&s[p][2]=='d') ans--;
        }

        printf("case #%d:\n",i);
        printf("%d\n",ans);
    }
}
