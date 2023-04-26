#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int to(char *t,int len)
{
    int temp=0;
    for(int i=0;i<len;i++) temp=temp*10+(t[i]-'0');
    return temp;
}
int cmp(const void *a,const void *b)
{
    int s1=*(int*)a,s2=*(int*)b;
    if(s1>s2) return 1;
    else return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int f=0;f<t;f++)
    {
        char s[100];int ans[100]={0};int p=0;
        scanf("%s",s);
        int len=strlen(s);
        int temp=0;
        for(int i=0;i<len;i++) temp=temp*10+(s[i]-'0');
        ans[p++]=temp;
        for(int i=1;i<len;i++)
        {
            char *t1=(char *)malloc(len*sizeof(char));
            for(int j=i,k=0;k<len;k++)
            {
                if(j+k<len) t1[k]=s[j+k];
                else t1[k]=s[j+k-len];
            }
            ans[p++]=to(t1,len);
            free(t1);
        }
        qsort(ans,p,sizeof(int),cmp);
        printf("case #%d:\n",f);
        for(int i=0;i<p;i++)
        {
            if(ans[i]==temp) printf("%d\n",ans[i+1]);
        }
    }
    return 0;
}
