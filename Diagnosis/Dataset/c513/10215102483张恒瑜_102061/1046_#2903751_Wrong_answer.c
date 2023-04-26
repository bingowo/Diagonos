#include<stdio.h>
#include<string.h>

int findnext(char A[],int j,int x)
{
    int i;
    for(i=j;i<strlen(A);i++)
    {
        if(A[i]==x) return i;
    }
    return -1;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        getchar();
        char s[200]={'\0'};
        int cnt=0;
        while (scanf("%s",s)!=EOF)
        {
            for(int i=0;i<strlen(s);i++)
            {
                if(s[i]>='A' && s[i]<='Z') s[i]+=32;
            }
            if(strcmp(s,"the")==0);
            else if(strcmp(s,"a")==0);
            else if(strcmp(s,"an")==0);
            else if(strcmp(s,"of")==0);
            else if(strcmp(s,"for")==0);
            else if(strcmp(s,"and")==0);
            else if(strcmp(s,"the")==0);
            else cnt++;
            char c=getchar();
            if(c=='\n') break;
        }
        
        printf("case #%d:\n%d\n",t,cnt);
    }
    return 0;
}