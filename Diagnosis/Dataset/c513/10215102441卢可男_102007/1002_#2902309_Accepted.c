#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{

    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int a[128]={};
        for(int j=0;j<128;j++)
        {
            a[j]=-1;

        }
        char s[100]="";
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
        if(count==1){count++;}
        jinzhi=count;
        long long ans=0;
        long long  z=1;
        for(int m=n-1;m>=0;m-- )
        {
            ans=ans+a[s[m]]*z;
            z=z*jinzhi;

        }
          printf("case #%d:\n%lld\n",i,ans);


    }



        return 0;
}
