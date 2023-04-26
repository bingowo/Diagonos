#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int base[1001]={0};
    char word[1001];
    scanf("%s",word);
    int l=strlen(word),i;
    if(l==1)
    {
        printf("1");
        return 0;
    }
    else if(l==2)
    {
        if(word[0]==word[1]) printf("1");
        else printf("2");
        return 0;
    }
    else
    {
        int j;
        for(j=0;j<l;j++)
        {
            if(j==0)
            {
                if(word[0]==word[1]) base[0]=1;
                else base[0]=2;
            }
            else if(j==l-1)
            {
                if(word[j-1]==word[j-2]) base[l-1]=1;
                else base[l-1]=2;
            }
            else
            {
                if(word[j]==word[j+1]&&word[j]==word[j-1]) base[j]=1;
                else if(word[j]!=word[j+1]&&word[j]!=word[j-1]&&word[j+1]!=word[j-1]) base[j]=3;
                else base[j]=2;
            }
        }
        int ret[l+1];
        ret[0]=base[0];
        for(i=1;i<l;i++)
        {
            if(base[i]==1) continue;
            else if(base[i]==0) break;
            else
            {
                int k,flag=0;
                for(k=0;k<=i+1;k++)
                {
                    ret[k]=ret[k]*base[i]+flag;
                    flag=ret[k]/10;
                    ret[k]=ret[k]%10;
                }
            }
        }
        int flag=0;
        for(i=l+1;i>=0;i--)
        {
            if(ret[i]==0&&flag==0) continue;
            else
            {
                printf("%d",ret[i]);
                flag=1;
            }
        }
    }
    return 0;
}
