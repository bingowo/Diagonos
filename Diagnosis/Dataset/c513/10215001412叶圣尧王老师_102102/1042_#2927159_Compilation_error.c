#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sp(char*a,int n)
{char s1[n+1];
    for(int i=0;i<n;i++)
    {
        for(int e=0;e<n-2;e++)
        {
            for(int k=1;k<=n;k++)
            {strncpy(s1,a,k);s1[k]='\0';
            printf("%s",s1);}
        }
    }
}

int main()
{
    int T,i,j;scanf("%d",&T);char s[17],c;
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        scanf("%s",s);int a[52]={0};
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]>='A'&&s[i]<='Z')a[s[i]-65]++;
            else a[s[i]-71]++;
        }
        int k=0;
        for(i=0;i<26;i++)if(a[i]>0)s[k++]='A'+i;
        for(i=26;i<52;i++)if(a[i]>0)s[k++]='a'+i-26;
        s[k]='\0';
        for(i=0;i<k;i++)
        {
            char s1[k+1];
            for(int l=1;l<=k-i;l++)
            {strncpy(s1,s+i,l);s1[l]='\0';
            printf("%s\n",s1);}
            for(j=k-2;j>0;j--)
            {
                strncpy(s1,s,j-1);s1[j-1]='\0';
                void sp(s+j+1,k-j-1);
            }
            
        }
    }
}