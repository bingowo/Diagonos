#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void reversestring(char * b,int count)
{
    char c=0;
    int i=0;
    int size;
    size=count-1;
    if (size==0 || size==1)
        b=b;
    for(;i<=size;i++)
    {
        c=b[i];
        b[i]=b[size];
        b[size]=c;
        size--;
    }
}

int main()
{
    char str1[501],str2[501],temp[501];
    int a[501],b[501],c[501];
    int len;
    while(scanf("%s",temp)!=EOF)
    {   
        int sign=1;
        strcpy(str1,temp);
        scanf("%s",temp);
        strcpy(str2,temp);
        reversestring(str1, strlen(str1));
        reversestring(str2, strlen(str2));
        int x=0;
        for(int z=0;z< strlen(str1);z++)
        {
            a[z]=str1[z]-'0';
        }
        for(int z=0;z< strlen(str2);z++)
        {
            b[z]=str2[z]-'0';
        }
        if(strlen(str1)< strlen(str2))
            len=strlen(str2);
        else
            len=strlen(str1);
        if(strlen(str1)< strlen(str2))
            sign=-1;
        else if(strlen(str1)>strlen(str2))
            sign=1;
        else
        {
            int i=strlen(str1)-1;
            for(i=strlen(str1)-1;i>=0;i--)
            {
                if(str1[i]<str2[i])
                {
                    sign=-1;
                    break;
                }
                else if(str1[i]>str2[i])
                {
                    sign=1;
                    break;
                }
            }
            if(i==-1)
                x=1;
        }
        int aint,bint;
        for(int k=0;k<len;k++)
        {
            aint=k<strlen(str1)?a[k]:0;
            bint=k<strlen(str2)?b[k]:0;
            if(sign==1)
                c[k]=aint-bint;
            else
                c[k]=bint-aint;
        }
        for(int k=0;k<len;k++)
        {
            if(c[k]<0)
            {
                c[k]=c[k]+10;
                c[k+1]=c[k+1]-1;
            }
        }
        int flag=1;
        char u;
        if(sign==-1)
            u='-';
        if(u=='-')
            printf("%c",u);
        if(x==0)
        {
            for(int e=len-1;e>=0;e--)
            {
                if(c[e]==0&&flag)
                    continue;
                flag=0;
                printf("%d",c[e]);
            }
        }
        else
            printf("%d",0);
        printf("\n");
    }
}