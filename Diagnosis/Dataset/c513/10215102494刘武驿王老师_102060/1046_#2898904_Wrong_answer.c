#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    char ban[12][5]={"the\0","a\0","an\0","of\0","for\0","and\0","THE\0","A\0","AN\0","OF\0","FOR\0","AND\0"};
    char ban1[11][5]={"The\0","A\0","An\0","Of\0","For\0","And\0","THE\0","AN\0","OF\0","FOR\0","AND\0"};
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
                p++;
                q=0;
                j++;
            }
            else
            {
                s[p][q++]=tmp[j++];
            }
        }
        int sum=p+1;
        for(int x=0;x<11;x++) if(strcmp(ban1[x],s[0])==0) sum--;
        for(int m=1;m<p+1;m++)
        {
            for(int x=0;x<12;x++) if(strcmp(ban[x],s[m])==0) sum--;
        }
        printf("case #%d:\n%d\n",i,sum);
    }
}