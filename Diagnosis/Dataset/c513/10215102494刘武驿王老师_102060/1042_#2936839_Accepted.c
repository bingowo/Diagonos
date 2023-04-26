#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(void* a,void *b)
{
    return (strcmp((char *)a,(char *)b));
}
int cmp1(void* a,void *b)
{
    return *(char *)a-*(char *)b;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char s[1000];
        scanf("%s",s);
        int len=strlen(s),count=1;
        qsort(s,len,sizeof(s[0]),cmp1);
        char uni[20];
        uni[0]=s[0];
        for(int j=1;j<len;j++) if(s[j]!=s[j-1]) uni[count++]=s[j];
        uni[count]='\0';
        char ans[300000][17];
        ans[0][0]='\0';
        int count1=1,tmp=1;
        for(int j=0;j<count;j++)
        {
            for(int x=0;x<tmp;x++)
            {
                strcpy(ans[count1],ans[x]);
                len=strlen(ans[count1]);
                ans[count1][len]=uni[j];
                ans[count1][len+1]='\0';
                count1++;
            }
            tmp=count1;
        }
        qsort(ans,count1,sizeof(ans[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=1;j<count1;j++) printf("%s\n",ans[j]);
    }
}