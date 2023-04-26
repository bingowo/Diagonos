#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
void slo(int s1[],int s2[],int a[],int n1)
{
    int i=0;
    for(int j=0; j<n1; j++)
    {
        a[j]=a[j]+s1[j]-s2[j];
        if(j!=n1-1)
        {
            if(a[j]<0)
            {
                a[j]=10+a[j];
                a[j+1]--;
            }
        }

    }
}
int main()
{
    char s1[505],s2[505];
    int a[505],b1[505],b2[505];
    while((scanf("%s%s",s1,s2))!=EOF)
    {
        int id=0,i=0;;
        for(int j=0; j<505; j++)
            {a[j]=0;b1[j]=0;b2[j]=0;}
        int len1=strlen(s1),len2=strlen(s2);
        for(int i=len1-1; i>=0; i--)
            b1[id++]=s1[i]-'0';
        id=0;
        for(int i=len2-1; i>=0; i--)
            b2[id++]=s2[i]-'0';
        if(strcmp(s1,s2)==0)
        {
            printf("0\n");
        }
        else if(len1>=len2)
        {
            slo(b1,b2,a,len1);
            for(int j=len1-1; j>=0; j--)
            {

                if(a[j]==0&&i==0)
                    continue;
                else
                    i=1;
                printf("%d",a[j]);
            }
            printf("\n");
        }
        else
        {
            slo(b2,b1,a,len2);
            printf("-");
            for(int j=504; j>=0; j--)
            {
                if(a[j]==0&&i==0)
                    continue;
                else
                    i=1;
                printf("%d",a[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
