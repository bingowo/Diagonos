#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int t;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++)
    {
        int ans;
        char s[80],s1[80],s2[80];
        scanf("%s %s %s",s1,s2,s);
        int len=strlen(s);
        int len1=strlen(s1);
        int len2=strlen(s2);
        char str1[80][200]={0};
        char str2[80][200]={0};
        int min1=len,max1=0;
        int min2=len,max2=0;
        int temp;
        for(int j=0;j<=len-len1;j++)
        {
            for(int k=0;k<len1;k++)
            {
                str1[j][k]=s[j+k];
            }
            if(strcmp(str1[j],s1)==0)
            {
                if(j>max1) max1=j;
                if(j<min1) min1=j;
            }
        }
        for(int j=0;j<=len-len2;j++)
        {
            for(int k=0;k<len2;k++)
            {
                str2[j][k]=s[j+k];
            }
            if(strcmp(str1[j],s2)==0)
            {
                if(j>max2) max2=j;
                if(j<min2) min2=j;
            }
        }
        if(max2-min1>max1-min2) ans=max2-min1-len1;
        if(max2-min1<=max1-min2) ans=max1-min2-len2;
        if(ans<0) ans=0;
        printf("case #%d:\n",i);
        printf("%d\n",ans);
    }

}
