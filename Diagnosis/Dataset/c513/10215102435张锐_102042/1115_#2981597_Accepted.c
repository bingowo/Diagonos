#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        char s[100];
        scanf("%s",s);
        int len=strlen(s);
        int *p1=(int *)malloc((len+1)*sizeof(int));
        p1[0]=0;
        for(int i=0;i<len;i++) p1[i+1]=(s[i]-'0');
        int p;
        for(p=len-1;p>=0;p--)
        {
            if(p1[p]<p1[p+1]) break;
        }
        qsort(p1+p+1,len-p,sizeof(int),cmp);
        for(int i=p+1;i<len+1;i++)
        {
            int temp=p1[p];
            if(temp<p1[i])
            {
                p1[p]=p1[i];p1[i]=temp;
                break;
            }
        }
        printf("case #%d:\n",f);
        for(int i=0;i<len+1;i++)
        {
            if(i==0&&p1[i]==0) continue;
            else printf("%d",p1[i]);
        }
        printf("\n");
    }
    return 0;
}
