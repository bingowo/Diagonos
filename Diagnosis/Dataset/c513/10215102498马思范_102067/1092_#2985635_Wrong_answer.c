#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10000
typedef struct { int cnt, v[N]; } BIGINT ;
BIGINT int2BIG(int x)
{
    BIGINT R= {0,{0}};
    do
    {
        R.v[R.cnt++]=x%10;
        x/=10;
    } while (x>0);
    return R;
}
BIGINT mul(BIGINT S, BIGINT T)
{
    BIGINT R= {S.cnt+T.cnt,{0}};
    for (int i=0; i<T.cnt; i++)
    {
        int t,k,j;
        int carry=0;
        for (j=0; j<S.cnt; j++)
        {
            t=S.v[j]*T.v[i]+carry+R.v[i+j];
            R.v[i+j]=t%10;
            carry=t/10;
        }
        k=i+j;
        while (carry>0)
        {
            t=carry+R.v[k];
            R.v[k]=t%10;
            carry=t/10;
            k++;
        }
    }
    if (R.v[S.cnt+T.cnt-1]==0) R.cnt--;
    return R;
}
BIGINT pow(BIGINT a, int n)
{
    BIGINT r;
    if (n==0) return int2BIG(1);
    if (n==1) return a;
    r=pow(a, n/2);
    r=mul(r,r);
    if (n%2) r=mul(r, a);
    return r;
}

int main()
{
    char w[1001];
    scanf("%s",w);
    int len= strlen(w);
    int x=0;//记录3
    int y=0;//记录2
    if(len==1)
        printf("%d",1);
    else if(len==2)
    {
        if(w[0]==w[1])
            printf("%d",1);
        else
            printf("%d",4);
    }
    else
    {
        if(w[0]!=w[1])
            y++;
        if(w[len-1]!=w[len-2])
            y++;
        for (int i=1;i<len-1;i++)
        {
            if (w[i]!=w[i+1]&&w[i]!=w[i-1]&&w[i-1]==w[i+1])
                y++;
            else if(w[i]!=w[i+1]&&w[i]!=w[i-1]&&w[i-1]!=w[i+1])
                x++;
            else if(w[i]==w[i-1]&&w[i]!=w[i+1])
                y++;
            else if(w[i]==w[i+1]&&w[i]!=w[i-1])
                y++;
        }
        if(x==0)
            printf("%d",1);
        else
        {
            BIGINT result1,result2;
            BIGINT result;
            result1= pow(int2BIG(3),x);
            result2= pow(int2BIG(2),y);
            result= mul(result1,result2);
            for(int m=result.cnt-1;m>=0;m--)
                printf("%d",result.v[m]);
        }
    }
    return 0;
}