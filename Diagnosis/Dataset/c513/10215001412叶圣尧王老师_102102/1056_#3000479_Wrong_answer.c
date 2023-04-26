#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

int cmp(const void*a,const void*b)
{
    if(strlen((char*)b)!=strlen((char*)a))
    return strlen((char*)b)>strlen((char*)a);
    else return strcmp((char*)a,(char*)b);
}

int main()
{
    int n;scanf("%d",&n);
    int i,j;char s[n][20],L[10000],c[10000];
    for(i=0;i<n;i++)
        scanf("%s",s[i]);
    scanf("%s",L);
    qsort(s,n,sizeof(char)*20,cmp);
    strcpy(c,L);int a[10000]={0};
    int k=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<strlen(L)-strlen(s[i])+1;j++)
        {
            int flag=0;
            if(L[j]=='0'||L[j]!=s[i][0])continue;
            char t=L[j+strlen(s[i])];
            L[j+strlen(s[i])]='\0';
            if(strcmp(L+j,s[i])==0)
            {
               a[j]=strlen(s[i]);
                memset(L+j,'0',strlen(s[i]));
                flag=1;
            }
            L[j+strlen(s[i])]=t;
            if(flag==1)j+=strlen(s[i])-1;
        }
    }
    for(i=0;i<strlen(c);i++)
    {
        if(a[i]!=0)
        {
            char t=c[i+a[i]];c[i+a[i]]='\0';
            printf("%s",c+i);c[i+a[i]]=t;
            i=i+a[i]-1;
        }
        else printf("%c",c[i]);
        if(i<strlen(c)-1)putchar(' ');
    }
}
