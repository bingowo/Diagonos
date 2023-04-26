#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
int max(int a,int b)
{
    return a>b?a:b;
}
int isPresent(char* s1,char* s2,char* s)
{
    int i,j,len1,len2,len;
    int m1=-1,n1=-1,m2=-1,n2=-1;//m是最开始出现的，n是最后出现的位置，不出现就是-1
    len1= strlen(s1);
    len2= strlen(s2);
    len=strlen(s);
    for (i=0;i<=len-len1;i++)
    {
        if(strncmp(s+i,s1,len1)==0)
        {
//            printf("%s",s2);
            m1=(m1==-1)?i:m1;
            n1=(n1<i)?i:n1;
        }
    }
    for (j=0;j<=len-len2;j++)
    {
        if(strncmp(s+j,s2,len2)==0)
        {
            m2=(m2==-1)?j:m2;
            n2=(n2<j)?j:n2;
        }
    }
//    printf("!!!m1=%d m2=%d n1=%d n2=%d!!!\n",m1,m2,n1,n2);
    int ans1=-1,ans2=-1;
    if(m1!=-1&&n2!=-1)
    {
        if(m1==n2)
        {
            if(len1==len2)
                ans1=(len1-2>0?len1-2:0);
            else
                ans1=max(len1,len2)-2;
        }
        else
            ans1=(m1>n2)?abs(m1-n2-len2):abs(n2-m1-len1);
    }
    if(m2!=-1&&n1!=-1)
    {
        if(m2==n1)
        {
            if(len1==len2)
                ans1=(len1-2>0?len1-2:0);
            else
                ans1=max(len1,len2)-2;
        }
        else
            ans2=(m2>n1)?abs(m2-n1-len1):abs(n1-m2-len2);
    }
    if(ans1!=-1&&ans2!=-1)
        return max(ans1,ans2);
    else{
        if(ans1!=-1)
            return ans1;
        else if(ans2!=-1)
            return ans2;
        else
            return 0;
    }
}




int main(void)
{
    int t;char s[81];
    char s1[81],s2[81];
    scanf("%d",&t);
    getchar();
    for(int i=0;i<t;i++)
    {
        gets(s1);
        gets(s2);
        gets(s);

        printf("case #%d:\n",i);
        printf("%d",isPresent(s1,s2,s));
        printf("\n");
    }
    return 0;

}
