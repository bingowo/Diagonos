#include<stdio.h>
#include<math.h>

int main()
{
    int T,i=0;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int x,y,a[1000]={0},b[1000]={0},j=0,k=0,n=0,m=0,l1=0,l2=0,sum=0,h=0,x1=0,y1=0;
        scanf("%d %d",&x,&y);
        x1=x;
        y1=y;
        while(x)
        {
            a[j]=x%2;
            x/=2;
            j++;
        }
        l1=j;
        for(j=0;j<l1/2;j++)
        {
            n=a[j];
            a[j]=a[l1-j-1];
            a[l1-j-1]=n;
        }
        j=0;
        while(y)
        {
            b[j]=y%2;
            y/=2;
            j++;
        }
        l2=j;
        for(j=0;j<l2/2;j++)
        {
            m=b[j];
            b[j]=b[l2-j-1];
            b[l2-j-1]=m;
        }
        if(x1==0) l1=1;
        else if(y1==0) l2=0;
        for(j=l1-1,k=l2-1;j>=0&&k>=0;j--,k--)
        {
            if(a[j]!=b[k]) sum++;
        }
        h=l1-l2;
        sum+=fabs(h);
        printf("%d\n",sum);
    }
    return 0;
}
