#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char s[1000];
        scanf("%s",s);
        int bro[4],count=1,color[4];
        for(int j=0;j<4;j++) bro[j]=0;
        for(int j=0;j<strlen(s);j++)
        {
            if(s[j]=='R') color[0]=j%4;
            if(s[j]=='B') color[1]=j%4;
            if(s[j]=='Y') color[2]=j%4;
            if(s[j]=='G') color[3]=j%4;
        }
        for(int j=0;j<strlen(s);j++)
        {
            if(s[j]=='!')
            {
                int tmp=j%4;
                for(int p=0;p<4;p++)
                {
                    if(tmp==color[p])
                    {
                        bro[p]++;
                        break;
                    }
                }
            }
        }
        printf("case #%d:\n",i);
        for(int j=0;j<4;j++) printf("%d ",bro[j]);
        printf("\n");
    }
}
