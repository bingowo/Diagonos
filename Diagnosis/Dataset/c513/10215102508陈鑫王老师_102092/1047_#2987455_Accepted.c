#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int rle(char s[],int ans[],char ret[])
{
    int temp=1,index=0;
    char *q,*p=s;
    while(*p!='\0')
    {
        q=p+1;
        temp=1;
        while(*p==*q&&*q!='\0')
        {
            temp++;
            q++;
            if(temp==255)
                break;

        }
        ans[index]=temp;
        ret[index]=*p;
        index++;
        p=q;

    }
    ret[index]='\0';
    return index-1;
}
int main()
{
    int t;
    scanf("%d",&t);
    char c=getchar();
    for(int i=0;i<t;i++)
    {
        char s[501],ret[501];
        int ans[501];
        memset(ans,0,sizeof(int)*501);
        gets(s);
        int len=rle(s,ans,ret);
        printf("case #%d:\n",i);
        for(int j=0;j<=len;j++)
        {
            printf("%d%c",ans[j],ret[j]);
        }
        printf("\n");


    }
    return 0;
}
