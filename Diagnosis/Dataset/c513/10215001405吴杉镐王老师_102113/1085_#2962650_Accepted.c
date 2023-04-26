#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int T,n;
char s1[600],s2[600];
int a[600],b[600],cnt1,cnt2,l1,l2;
int main(){
    while(~scanf("%s%s",s1,s2))
    {
        cnt1=cnt2=0;
        l1=strlen(s1);
        l2=strlen(s2);
        for(int i=l1-1;i>=0;i--)
            a[++cnt1]=s1[i]-'0';
        for(int i=l2-1;i>=0;i--)
            b[++cnt2]=s2[i]-'0';
        //位数对齐
        while(cnt1<cnt2)
            a[++cnt1]=0;
        while(cnt2<cnt1)
            b[++cnt2]=0;
        
        int flg=0;
        for(int i=cnt1;i;i--)
        {
            a[i]-=b[i];
            if(a[i]!=0 && flg==0) //通过首位确定符号
            {
                if(a[i]>0)
                    flg=1;
                else
                    flg=-1;
            }
            a[i]*=flg;
        }

        for(int i=1;i<=cnt1;i++)
            if(a[i]<0)
            {
                a[i]+=10;
                a[i+1]--;
            }
        while(a[cnt1]==0&&cnt1>1)
            cnt1--;
        if(flg==-1)
            printf("-");
        for(int i=cnt1;i;i--)
            printf("%d",a[i]);
        puts("");
    }
    return 0;
}
