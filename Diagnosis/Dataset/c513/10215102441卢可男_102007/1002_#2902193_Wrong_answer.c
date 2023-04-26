#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int a[128]={};
    for(int j=0;j<128;j++)
    {
        a[j]=-1;

    }
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        char s[61]="";
        scanf("%s",s);
        int n=strlen(s);
        a[s[0]]=1;
        int count=1;
        int tem=0;
        int jinzhi=0;
        for(int k=1;k<n;k++)
        {
            if(a[s[k]]==-1)
            {
                a[s[k]]=tem;
                count++;
                tem=count;

            }
        }

        jinzhi=count;
        int  ans=0;
        int  z=1;
        for(int m=n-1;m>=0;m-- )
        {
            ans=ans+a[s[m]]*z;
            z=z*jinzhi;

        }
          printf("case #%d:\n%d",i,ans);


    }



        return 0;
}
