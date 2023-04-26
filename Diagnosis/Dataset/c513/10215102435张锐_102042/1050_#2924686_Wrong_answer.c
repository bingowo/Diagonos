#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s1[200],s2[200],s[1000];
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%s",s);
        int len1=strlen(s1),len2=strlen(s2),len=strlen(s);
        int i1=0;
        for(;i1<len;i1++)
        {
            int temp=i1;int b=0;
            if(s1[0]==s[i1])
            {
                if(len1==1) break;
                for(int j=0;j<len1;j++,i1++)
                {
                    if(s1[j]!=s[i1]) {i1=temp;break;}
                    else if(s1[j]==s[i1]&&j==len1-1) {b=1;break;}
                }
            }
            if(b) break;
        }
        int i2=len-1;
        for(;i2>=0;i2--)
        {
            int temp=i2;int b=0;
            if(s2[len2-1]==s[i2])
            {
                if(len2==1) break;
                for(int j=len2-1;j>=0;j--,i2--)
                {
                    if(s2[j]!=s[i2]) {i2=temp;break;}
                    else if(s2[j]==s[i2]&&j==0) {i2=i2+len2-1;b=1;break;}
                }
            }
            if(b) break;
        }
        int left1=i1-len1+1,left2=i2-len2+1,right1=i1,right2=i2;
        int num1=0,num2=0;
        if(left2>right1) num1=left2-right1-1;//假设1在左边
        if(left1>right2) num2=left1-right2-1;//假设2在左边
        printf("case #%d:\n",i);
        int num=0;
        if(num1>0) num=num1;
        else num=num2;
        i1=0;
        for(;i1<len;i1++)
        {
            int temp=i1;int b=0;
            if(s2[0]==s[i1])
            {
                if(len2==1) break;
                for(int j=0;j<len2;j++,i1++)
                {
                    if(s2[j]!=s[i1]) {i1=temp;break;}
                    else if(s2[j]==s[i1]&&j==len2-1) {b=1;break;}
                }
            }
            if(b) break;
        }
        i2=len-1;
        for(;i2>=0;i2--)
        {
            int temp=i2;int b=0;
            if(s1[len1-1]==s[i2])
            {
                if(len1==1) break;
                for(int j=len1-1;j>=0;j--,i2--)
                {
                    if(s1[j]!=s[i2]) {i2=temp;break;}
                    else if(s1[j]==s[i2]&&j==0) {i2=i2+len1-1;b=1;break;}
                }
            }
            if(b) break;
        }
        left1=i1-len2+1,left2=i2-len1+1,right1=i1,right2=i2;
        num1=0,num2=0;
        if(left2>right1) num1=left2-right1-1;//假设1在左边
        if(left1>right2) num2=left1-right2-1;//假设2在左边
        if(num1>0&&num<num1) num=num1;
        if(num2>0&&num<num2) num=num2;
        printf("%d\n",num);
    }
    return 0;
}
