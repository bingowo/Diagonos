#include<stdio.h>
#include<limits.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; i++)
    {
        int a[65]= {0};
       unsigned long long int x;

        scanf("%llu",&x);
        unsigned long long int xx=x;
        int cnt=0;
        while(xx!=0)
        {
            a[cnt++]=xx%10;
            xx/=10;
        }
        //115
        //5 1 1
        //1051
//        1 5 0 1
        int j=1;
       unsigned long long int min=ULLONG_MAX;
      // printf("%llu",min);
        while(j<=cnt){
            for(int k1=1;k1<=j;k1++)
            {
                for(int k2=0;k2<k1;k2++)
            {unsigned long long int tmp=0;
                int t=a[k1];
                a[k1]=a[k2];
                a[k2]=t;
                for(int p=0;p<=cnt;p++)
                tmp=tmp*10+a[cnt-p];
               // printf("%lld\n",tmp);
                if((tmp>x)&&(tmp<min)){min=tmp;}
               /* t=a[k1];
                a[k1]=a[k2];
                a[k2]=t;*/
            }
            }
            //if(min!=1000000&&min>x)break;
            j++;
        }
        printf("case #%d:\n",i);
        printf("%llu\n",min);
    }

    return 0;
}
