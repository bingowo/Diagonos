#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int bigger(char a[],char b[])
{
    if(strlen(a)>strlen (b)) return 1;
    else if(strlen(a)<strlen(b)) return -1;
    else
    {
        for(int i=0;i<strlen(a);i++)
        {
            if(a[i]>b[i]) return 1;
            else if(a[i]<b[i]) return -1;
        }
        return 0;
    }
}
int sub(int a[],int lena,int b[],int lenb)
{
    int subb,i=0,k;
    while(i<lenb)
    {
        k=1;
        subb=a[i]-b[i];
        if(subb<0)
        {
            a[i]=subb+10;
            a[i+k]--;
            while(a[i+k]==-1)
            {
                a[i+k]+=10;
                k++;
                a[i+k]--;
            }
        }
        else
        {
            a[i]=subb;
        }
        for(int i=lena-1;i>=0;i--)
        {
            printf("%d",a[i]);
        }
        printf("\n");
        i++;
    }
    for(i=lena-1;i>=0;i--)
    {
        if(a[i]!=0)
            return i+1;
    }
}
int num(char a[],int a2[])
{
    for(int i=0;i<strlen(a);i++)
    {
        a2[strlen(a)-i-1]=a[i]-'0';
    }
    return strlen(a);
}
int main()
{
    int lena,lenb,big,a1[600],b1[600];
    char a[600]={0},b[600]={0};
    while(scanf("%s %s",a,b)!=EOF)
    {
        memset(a1,0,sizeof(a));
        memset(b1,0,sizeof(b));
        lena=num(a,a1);
        lenb=num(b,b1);
        for(int i=lena-1;i>=0;i--)

        big=bigger(a,b);
        if(big==0)
        {
            printf("0\n");
            continue;
        }
        else if(big==1)
        {
            lena=sub(a1,lena,b1,lenb);
            for(int i=lena-1;i>=0;i--)
            {
                printf("%d",a1[i]);
            }
        }
        else
        {
            printf("-");
            lenb=sub(b1,lenb,a1,lena);
            for(int i=lenb-1;i>=0;i--)
            {
                printf("%d",b1[i]);
            }
        }
        printf("\n");

    }
    return 0;
}
