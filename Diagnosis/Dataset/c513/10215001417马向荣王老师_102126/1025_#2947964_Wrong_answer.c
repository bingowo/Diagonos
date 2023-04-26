#include<stdio.h>
#include<string.h>
int differ(char *a,int lena)
{
    int p[21]={0};
    int num=0;
    for(int i=0;i<lena;i++)
    {
        int flag=0;
        for(int j=0;j<lena;j++)
        {
            if(a[i]==p[j]) flag=1;
        }
        if(flag==0) num++;
        p[i]=a[i];
        return num;
    }
    return num;
}
int compare(char *a,int lena,char *b,int lenb)
{
    int max=0;
    if(lena<lenb) max=lenb;
    for(int i=0;i<max;i++)
    {
        if(a[i]>b[i]) return 1;
        else if(a[i]<b[i]) return -1;
        else return 0;
    }
    return 0;
}
int main(void)
{
    int t=0;
    scanf("%d\n",&t);
    for(int m=0;m<t;m++)
    {
        int n=0;
        scanf("%d\n",&n);//句子数
        char a[n][21];
        int s[n];
        for(int i=0;i<n;i++)
        {
            scanf("%s",&a[i]);
            getchar();
            s[i]=differ(a[i],strlen(a[i]));//计算不同字符的数目
        }
        for(int i=0;i<n-1;i++)//排序数量
        {
            for(int j=0;j<n-1-i;j++)
            {
                if(s[j]<s[j+1])
                {
                    char b[21];
                    strcpy(b,a[j]);
                    strcpy(a[j],a[j+1]);
                    strcpy(a[j+1],b);
                    int t=s[j];
                    s[j]=s[j+1];
                    s[j+1]=t;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            s[i]=differ(a[i],strlen(a[i]));
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(s[j]==s[j+1])
                {
                    if(compare(a[j],strlen(a[j]),a[j+1],strlen(a[j+1]))> 0)
                    {
                        char b[21];
                        strcpy(b,a[j]);
                        strcpy(a[j],a[j+1]);
                        strcpy(a[j+1],b);
                    }
                }
            }
        }
        printf("case #%d:\n",m);
        for(int i=0;i<n;i++)
        {
            printf("%s\n",a[i]);
        }
    }
    return 0;
}