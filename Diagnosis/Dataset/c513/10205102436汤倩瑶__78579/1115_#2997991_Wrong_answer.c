#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; i++)
    {
        int a[65]= {0};
        long long int x;

        scanf("%lld",&x);
        long long int xx=x;
        int cnt=0;
        while(xx!=0)
        {
            a[cnt++]=xx%10;
            xx/=10;
        }
        //115
        //5 1 1
        int j=1;
        long long int min=10e20;
        while(1){
            for(int k=0;k<j;k++)
            {long long int tmp=0;
                int t=a[j];
                a[j]=a[k];
                a[k]=t;
                for(int p=0;p<=cnt;p++)
                tmp=tmp*10+a[cnt-p];

                if((tmp>x)&&(tmp<min)){min=tmp;}
                //t=a[j];
                //a[j]=a[k];
                //a[k]=t;
            }
            if(min!=10e20&&min>x)break;
            j++;
        }
        printf("case #%d:\n",i);
        printf("%lld\n",min);
    }

    return 0;
}
