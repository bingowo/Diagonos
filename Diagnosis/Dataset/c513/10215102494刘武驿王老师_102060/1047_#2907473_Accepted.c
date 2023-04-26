#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(void *a,void *b)
{
    return *((char *)a)-*((char *)b);
}
int main()
{
    int n;
    scanf("%d",&n);
    char tmp=getchar();
    for(int i=0;i<n;i++)
    {
        char s[1000];
        scanf("%s",s);
        int res[1000];
        for(int j=0;j<1000;j++) res[j]=1;
        int count=0;
        for(int j=0;j<strlen(s);j++)
        {
            if(s[j]==s[j+1]&&res[count]<255) res[count]++;
            else count++;
        }
        int j=0,p=0;
        printf("case #%d:\n",i);
        while(s[j])
        {
            printf("%d%c",res[p],s[j]);
            j+=res[p];
            p++;
        }
        printf("\n");
    }
}
