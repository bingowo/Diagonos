#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a,const void *b)
{
    int x=*(int*)a;
    int y=*(int*)b;
    return y-x;
}
void read(char s[])
{
    int head=0,tail=50,a[30]={0};
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        a[len-1-i]=s[i]-'0';
    }
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(a[i]>a[j])
            {
                if(j<tail)
                {
                    head=i;
                    tail=j;
                    break;
                }
            }
        }
    }
    if(head==0&&tail==50)
    {
         printf("%d0",a[len-1]);
         for(int i=len-2;i>=0;i--)
             printf("%d",a[i]);
    }
    else
    {
        int t=a[head];
        a[head]=a[tail];
        a[tail]=t;
        qsort(a,tail,sizeof(int),cmp);
        for(int i=len-1;i>=0;i--)
            printf("%d",a[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    scanf("%d",&n);char s[30];
    for(int i;i<n;i++)
    {
        printf("case #%d:\n",i);
        scanf("%s",s);
        read(s);
    }
    return 0;
}
