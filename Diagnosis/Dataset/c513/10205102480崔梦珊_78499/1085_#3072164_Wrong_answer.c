#include<stdio.h>
#include<string.h>
int main()
{
    char aa[501]={0};
    char bb[501]={0};
    while(scanf("%s %s",aa,bb)!=EOF)
    {
        int alen=strlen(aa);
        int blen=strlen(bb);
        int a[501]={0},b[501]={0};
        for(int i=0;i<alen;i++)
        {
            a[501-alen+i]=aa[i]-'0';
        }
        for(int i=0;i<blen;i++)
        {
            b[501-blen+i]=bb[i]-'0';
        }
        int flag=0;
        for(int i=0;i<=500;i++)
        {
            if(a[i]<b[i])
            {
                flag=-1;
                break;
            }
            if(a[i]>b[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("0");
        }
        if(flag==1)
        {
            for(int i=500;i>=1;i--)
            {
                int temp=a[i]-b[i];
                if(temp<0)
                {
                    a[i]=10+temp;
                    a[i-1]--;
                }
                else a[i]=temp;
            }
            /*for(int i=0;i<=500;i++)
            {
                printf("%d",a[i]);
            }*/
            int f=0;
            for(int i=0;i<=500;i++)
            {
                if(f==0&&a[i]==0)
                {
                    continue;
                }
                if(f==0&&a[i]!=0)
                {
                    f++;
                    printf("%d",a[i]);
                    continue;
                }
                if(f!=0)
                {
                    printf("%d",a[i]);
                }
            }
            printf("\n");
        }
        if(flag==-1)
        {
            for(int i=500;i>=1;i--)
            {
                int temp=b[i]-a[i];
                if(temp<0)
                {
                    b[i]=10+temp;
                    b[i-1]--;
                }
                else b[i]=temp;
            }
            int f=0;
            printf("-");
            for(int i=0;i<=500;i++)
            {
                if(f==0&&b[i]==0)
                {
                    continue;
                }
                if(f==0&&b[i]!=0)
                {
                    printf("%d",b[i]);
                    f++;
                    continue;
                }
                if(f!=0)
                {
                    printf("%d",b[i]);
                }
            }
            printf("\n");
        }
    }

}
