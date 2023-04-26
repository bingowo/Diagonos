#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char s[100]={0};
    void decto2(int a,char s[]) /*将十进制数转化为二进制*/
    {
        int t=0,j=0;
        char p;
        while(a)
        {
            t=a%2;
            s[j]=t+'0';
            a/=2;
            j++;
        }
        j--;
        for(int i=0;i<j;i++,j--)
        {
            p=s[i];
            s[i]=s[j];
            s[j]=p;
        }
    }
    int a,b,c,sum=1;
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        for(int x=0;x<100;x++)
        {
            s[x]=0;
        }
        scanf("%d",&b);
        decto2(b,s);
        c=strlen(s);
        for(int j=0;j<c-1;j++)
        {
            while(s[j]!=s[j+1]&&j<c-1)
            {
                sum++;
                j++;
            }
        }
        printf("case#%d:\n%d\n",i,sum);
    }
    return 0;
}
