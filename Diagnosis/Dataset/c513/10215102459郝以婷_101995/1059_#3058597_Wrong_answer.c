#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;//注意是*(int*)a，不是(int*)a
}

int main()
{
    int n,s,a[1001],i,cnt,j,cnt1=0,h,r=0,r1;
    scanf("%d %d",&n,&s);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),cmp);
    h=a[0];
    for(i=0;i<n;i++)
    {
        cnt=0;
        for(j=i;j<n;j++)
        {
            if(a[j]==a[i])
                cnt++;
            else
                break;
        }
        if((cnt1+cnt+i)<s)
        {
            cnt1=cnt1+cnt+i;
            h++;
        }
        else if(cnt1+cnt+i==s)
        {
            h++;
            break;
        }
        else
        {
            r=s-cnt1;
            r1=cnt+i;
            for(j=2;j<=r;j++)
            {
                if((r%j==0)&&((cnt+i)%j==0))
                {
                    r=r/j;
                    r1=r1/j;
                }
            }
            printf("%d+%d/%d",h,r,r1);
            break;
        }
        i=i+cnt-1;
    }
    if(r==0)
        printf("%d",h);
    return 0;
}
