#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void delrep(char *a);
int isrep(char *a);
void func(char *s)
{
    while(isrep(s))
    {
        delrep(s);
    }
}
int main()
{
    int T,i,j,k,x,len1,len2,temp,res;
    char s[102],c[102];
    scanf("%d", &T);
    for(x=0;x<T;x++)
    {
        res=0;
        scanf("%s",s);
        len1=strlen(s);
        len2=0;
        memset(c,0,sizeof(c));
        for(i=0;i<strlen(s);i++)
        {
            k=0;
            for(j=0;j<strlen(s);j++)
            {
                //转换的思想，不一定要往里面加，而是转化成删掉某一个元素，这样就容易多了
                if(j!=i)        //不要s里的第i个元素
                {
                    c[k++]=s[j];
                }
            }
            c[k]=0;
            func(c);
            len2=strlen(c);
            temp=len1+1-len2;
            res=temp>res? temp:res;
        }
        printf("case #%d:\n",x);
        printf("%d\n",res);
    }
    return 0;
}
void delrep(char *a)
{
    int i,j;
    char temp[102]={0};
    j=0;
    for(i=0;i<strlen(a);i++)
    {
        if(i==0&&a[i]!=a[i+1])
            temp[j++]=a[i];
        else if(i==strlen(a)-1&&a[i]!=a[i-1])
            temp[j++]=a[i];
        else if(a[i]!=a[i+1]&&a[i]!=a[i-1])
            temp[j++]=a[i];
    }
    strcpy(a,temp);
}
int isrep(char *a)
{
    int flag=0;
    if(strstr(a,"AA")!=NULL)
        flag=1;
    else if(strstr(a,"BB")!=NULL)
        flag=1;
    else if(strstr(a,"CC")!=NULL)
        flag=1;
    return flag;
}
