#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int T;
    scanf("%d",T);
    int a[128];
    for(int j=0;j<128;j++)
    {
        a[j]=-1;

    }
    for(int i=0;i<T;i++)
    {
        int count=1;//有几个首次出现的数
        char s1[61]={0};
        char s2[128]={0};
        scanf("%s",s1);
        int n=strlen(s1);
        a[s1[0]]=1;
        s2[s1[0]]='1';
        if(a[s1[1]]=-1){s2[1]='0';}
        for(int k=2;k<n;k++)
        {
            if(a[s1[k]]=-1)
            {
                count ++;
                s2[s1[k]]='count';

            }

        }
            int jinzhi=count+1;
            int ans=0;
            int quanwei=1;
            for(int m;m=n-1;m>=0)
            {
                int shuma=s2[s1[m]]-48;
                int ans=ans+shuma*quanwei;
                int quanwei=quanwei*jinzhi;

            }
            printf("case #%d %d",i,ans);
        }
        return 0;


}
