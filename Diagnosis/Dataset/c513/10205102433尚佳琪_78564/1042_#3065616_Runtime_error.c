#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
    char m[20];
}node;
int cmp(const void *a,const void *b)
{
    char s1=*(char*)a;
    char s2=*(char*)b;
    return s1-s2;
}
int cmp2(const void *a,const void *b)
{
    node s1=*(node*)a;
    node s2=*(node*)b;
    return strcmp(s1.m,s2.m);
}
int _10toR(int a[],int n,int r)
{
    int temp,len=0;
    while(n>0)
    {
        temp=n%r;
        n=n/r;
        //if(temp<10)
        a[len++]=temp;
        //超过十进制 10用A表示,16用G
       // else a[len++]=temp-10+'A';
    }
    //0存放最低位，len-1是最高位
    return len;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[20];
        char s2[20];
        int k=0;
        scanf("%s",s);
        int len=strlen(s);
        qsort(s,len,sizeof(s[0]),cmp);
        s2[k++]=s[0];
        for(int i=1;i<len;i++)
        {
            if(s[i]!=s[i-1])
            {
                s2[k++]=s[i];
            }
        }
        s2[k]='\0';
        node ans[100];
        int t=0,q=0;
        for(int i=1;i<pow(2,k);i++)
        {
            int temp=i;
            for(int j=0;j<k;j++)
            {
                if(temp&1)
                {
                    ans[t].m[q++]=s2[j];
                }
                temp=temp>>1;
            }
            ans[t].m[q]='\0';
           // printf("%s\n",ans[t].m);
            t++;
            q=0;
        }
        //printf("%d\n",t);
        qsort(ans,t,sizeof(ans[0]),cmp2);
        printf("case #%d:\n",i);
        for(int i=0;i<t;i++)
            printf("%s\n",ans[i].m);
    }
}
