#include <stdio.h>
void add(int *a,int *b)
{
    int t,carry = 0,i;
    for(i = 0;i<50;i++)
        {t = a[i]+b[i]+carry;
        a[i] = t%10;
        carry = t/10;
        }
}
void sub(int *a,int *b)
{
    int t,carry = 0,i;
    for(i = 0;i<50;i++)
    {
        t = a[i] - carry - b[i];
        carry = 0;
        if(t<0) carry = 1;
        a[i] = (t + carry*10)%10;
        //printf("%d ",a[i]);

    }
}
int main()
{
    int k,n;int a[100][50] = {{0},{1}};
    scanf("%d %d",&k,&n);
    int i,j,p;
    if(n==1||n==2) printf("%d",a[n-1][0]);
    else{
        for(i = 2;i<n;i++)
        {
            if(i<=k)
            {
                for(j = 0;j<i;j++)
                    add(a[i],a[j]);
            }
            else {add(a[i],a[i-1]);add(a[i],a[i-1]);sub(a[i],a[i-k-1]);}
        }
        j = 30;
        while(a[n-1][j]==0) j--;
        for(p = j;p>=0;p--)
            printf("%d",a[n-1][p]);
    }
    return 0;
}
