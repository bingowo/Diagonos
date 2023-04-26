#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int n;
    scanf("%d",&n);
    char ban[6][5]={"the\0","a\0","an\0","of\0","for\0","and\0"};
    char s[200][200];
    char tmp[200];
    char uu=getchar();
    for(int i=0;i<n;i++)
    {
        int j=0,p=0,q=0;
        gets(tmp);
        while(tmp[j])
        {
            if(tmp[j]==' ')
            {
                s[p][q]='\0';
                p++;
                q=0;
                j++;
            }
            else
            {
                s[p][q++]=tolower(tmp[j++]);
            }
        }
        int sum=p+1;
        for(int x=0;x<6;x++) if(strcmp(ban[x],s[0])==0) sum--;
        for(int m=1;m<p+1;m++)
        {
            for(int x=0;x<6;x++) if(strcmp(ban[x],s[m])==0) sum--;
        }
        printf("case #%d:\n%d\n",i,sum);
    }
}