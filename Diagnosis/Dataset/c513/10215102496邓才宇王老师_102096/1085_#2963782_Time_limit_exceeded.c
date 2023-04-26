#include<stdio.h>
#include<string.h>
int x[100]={0},y[100]={0},z[105]={0};
void sub(int x[],int y[],int len)
{
    int i,j;
    for(i=0;i<len;i++)
    {
        if(x[i]>=y[i])
            z[i]=x[i]-y[i];
        else
        {
            z[i]=x[i]+10-y[i];
            x[i+1]=x[i+1]-1;
        }
    }
    for(i=len-1;i>0;i--)
    {
        if(z[i]==0)
            len--;
        else
            break;
    }
    for(i=len-1;i>=0;i--)
        printf("%d",z[i]);
    printf("\n");
}
int main()
{
    char a[100],b[100];
    while(scanf("%s %s",a,b))
    {
        int i,j=0,k=0;
        int len1=strlen(a);
        int len2=strlen(b);
        for(i=len1-1,j=0;i>=0;i--)
            x[j++]=a[i]-'0';
        for(i=len2-1,k=0;i>=0;i--)
            y[k++]=b[i]-'0';
        if(len1>len2)
            sub(x,y,len1);
        else if(len1<len2)
        {
            printf("-");
            sub(y,x,len2);
        }
        else
        {
            for(i=len1-1;i>=0;i--)
            {
                if(x[i]==y[i])
                    continue;
                if(x[i]>y[i])
                {
                    sub(x,y,len1);
                    break;
                }
                if(x[i]<y[i])
                {
                    printf("-");
                    sub(y,x,len1);
                    break;
                }
            }
        }
    }
    return 0;
}
