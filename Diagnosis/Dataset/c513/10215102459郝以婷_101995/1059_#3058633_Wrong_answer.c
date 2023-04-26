#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;//注意是*(int*)a，不是(int*)a
}

int main()
{
    int n,s,a[1001],i,cnt,j,cnt1=0,h,r=0,r1,if0=1;
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
        if(i==0)
        {
            if(cnt<s)
            {
                cnt1=cnt;
                h++;
            }
            else if(cnt==s)
            {
                h++;
                if0=0;
                break;
            }
            else if(cnt>s)
            {
                for(j=2;j<=s;j++)
                {
                    if((s%j==0)&&(cnt%j==0))
                    {
                        s=s/j;
                        cnt=cnt/j;
                    }
                }
                if(h>0)
                    printf("%d+%d/%d",h,s,cnt);
                else
                    printf("%d/%d",s,cnt);
                r=1;
                if0=0;
                break;
            }
        }
        else
        {
            if((cnt1+cnt+i+(a[i]-a[i-1]-1)*i)<s)
            {
                cnt1=cnt1+cnt+i+(a[i]-a[i-1]-1)*i;
                h=a[i]-a[i-1]+h;
            }
            else if((cnt1+cnt+i+(a[i]-a[i-1]-1)*i)==s)
            {
                h=a[i]-a[i-1]+h;
                if0=0;
                break;
            }
            else
            {
                r1=cnt+i;
                if(h!=a[i])
                {
                    r1=i;
                    if(((a[i]-h)*i+cnt1)<s)
                    {
                        cnt1=cnt1+(a[i]-h)*i;
                        h=a[i];
                        r1=cnt+i;
                    }
                    else if(((a[i]-h)*i+cnt1)==s)
                    {
                        h=a[i];
                        if0=0;
                        break;
                    }
                }
                r=s-cnt1;
                if(r1<r)
                {
                    h=h+r%r1;
                    r=r-r%r1*r1;
                }
                for(j=2;j<=r;j++)
                {
                    if((r%j==0)&&(r1%j==0))
                    {
                        r=r/j;
                        r1=r1/j;
                    }
                }
                if(h>0)
                    printf("%d+%d/%d",h,r,r1);
                else
                    printf("%d/%d",r,r1);
                if0=0;
                break;
            }
        }
        i=i+cnt-1;
        //printf("%d %d\n",h,cnt1);
    }
    if(if0)
    {
        r=s-cnt1;
        h=h+r/n;
        if(r%n==0)
            r=0;
        else
        {
            r=r-r/n*n;
            for(j=2;j<=r;j++)
            {
                if((r%j==0)&&(n%j==0))
                {
                    r=r/j;
                    n=n/j;
                }
            }
            //if(h>0)
                printf("%d+%d/%d",h,r,n);
            //else
                //printf("%d/%d",r,n);
        }
    }
    if(r==0)
        printf("%d",h);
    return 0;
}
