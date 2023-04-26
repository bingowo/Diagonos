#include<stdio.h>
#include<math.h>
#define N 100

typedef long long ll;
typedef struct a
{
    int bit[N];
    int len;
}bit_3;

int main()
{
    ll a,b;
    scanf("%lld %lld",&a,&b);

    ll in;
    ll r=a%b;
    if (!r)//a可被b整除
    {
        int i;
        in=a/b;
        bit_3 arr_i;arr_i.len=0;
        for (i=0;i<N;++i)
        {
            arr_i.bit[i]=0;
        }
        
        int num=0;
        while (in > 0)
        {
            arr_i.bit[num++]=in%3;
            in/=3;
        }

        arr_i.len=num;
        for(i=0;i<arr_i.len;++i)
        {
            if (arr_i.bit[i]==2)
            {
                arr_i.bit[i]=-1;
                arr_i.bit[i+1]++;
            }
            else if (arr_i.bit[i]==3)
            {
                arr_i.bit[i]=0;
                arr_i.bit[i+1]++;
            }
        }
        if (arr_i.bit[i]!=0)
        {
            arr_i.len++;
        }

        for (i=arr_i.len-1;i>=0;--i)
        {
            if (arr_i.bit[i]==-1)
            {
                putchar('2');
            }
            else
            {
                printf("%d",arr_i.bit[i]);
            }
        }
    }
    else//同时有整数部分和小数部分
    {
        int i;
        int bit_n;
        in = a/b;

        ll fl_up=r,fl_down=b;
        bit_3 arr;
        arr.len=0;
        for (i=0;i<N;++i) {arr.bit[i]=0;}
        
        for (i=1;i<N/2-1;++i)
        {
            if (pow(3,i)==fl_down)
            {
                bit_n=N/2+i;
            }
        }
        int pos1=bit_n;
        int pos2;
        //处理小数部分
        while (fl_up>0 || bit_n>N/2)
        {
            arr.bit[bit_n--]=fl_up%3;
            arr.len++;
            fl_up/=3;
        }

        while (in > 0)
        {
            arr.bit[bit_n--]=in%3;
            arr.len++;
            in/=3;
        }

        for (i=pos1;i>=pos1-(arr.len-1);--i)
        {
            if (arr.bit[i]==2)
            {
                arr.bit[i]=-1;
                arr.bit[i-1]++;
            }
            else if (arr.bit[i]==3)
            {
                arr.bit[i]=0;
                arr.bit[i-1]++;
            }
        }

        if (arr.bit[i]!=0)
        {
            arr.len++;
        }
        pos2=pos1-(arr.len-1);
        
        while (arr.bit[pos1]==0) pos1--;
        
        if (a<(b/2))
        {
            printf("0.");
        }
        for (i=pos2;i<=pos1;i++)
        {
            if (arr.bit[i]==-1)
            {
                putchar('2');
            }
            else
            {
                printf("%d",arr.bit[i]);
            }
            if (i==N/2)
            {
                putchar('.');
            }
        }
        
        //处理小数部分

    }

    return 0;
}