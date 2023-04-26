#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cnt(char s[])//计算字符串是否还有重复字母
{
    int i=0,num=0;
    for(i=0;i<strlen(s)-1;i++)
    {
        if(s[i]==s[i+1]) num++;
    }
    return num;
}


int max(int a,int b)
{
    if(a>=b) return a;
    else return b;
}

int main()
{
    char s1[107]={0},s[107],s2[107]={0};
    int T,i=0,j=0,n=0,k=0,m=0,l=0,ans=0,len=0,num=0;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        ans=0;
        scanf("%s",s);
        for(j=0;j<strlen(s);j++)//枚举每一个字母后面插入和他相同的字母
        {
            if(s[j]==s[j-1]&&j!=0)  continue;
            m=j;
            for(k=0;k<=m;k++) s1[k]=s[k];
            s1[k++]=s[m];
            for(;k<=strlen(s);k++) s1[k]=s[k-1];
            s1[k]='\0';//最后一定要有结束符！
            len=strlen(s1);
            while(cnt(s1))
            {
                strcpy(s2,s1);
                for(l=0;l<k;l++) s1[l]='\0';
                for(m=0,l=0;l<strlen(s2)-1;l++)
                {
                    if(l==0){if(s2[0]!=s2[1]) {s1[m]=s2[l];m++;}}//首字母单独讨论
                    else if((s2[l]!=s2[l-1])&&(s2[l]!=s2[l+1])) {s1[m]=s2[l];m++;}//当这个字母和前后都不同时，才记录

                }
                if(s2[l]!=s2[l-1]) {s1[m]=s2[l];m++;}
                s1[m]='\0';//结束符结束符！1
                if(strlen(s1)==0) break;
            }
            num=len-strlen(s1);
            ans=max(ans,num);
            for(l=0;l<k;l++)
            {
                s1[l]='\0';
                s2[l]='\0';
            }
        }
        printf("case #%d:\n",i);
        printf("%d",ans);
    }
    return 0;
}
