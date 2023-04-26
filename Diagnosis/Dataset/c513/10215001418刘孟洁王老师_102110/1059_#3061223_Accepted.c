#include<stdio.h>
#include<string.h>

int GCD(int x,int y)
{
    if(x%y==0) return y;
    else if (y%x==0) return x;
    else if(x>y) x=x%y;
    else if(y>x) y=y%x;
    return GCD(x,y);
}

int cmp(const void*a,const void*b)
{
    int c=*(int*)a;
    int d=*(int*)b;
    if(c>d) return -1;
    else return 1;
}

int main()
{
    int i,j,k,t,n,s,a[1007],sum,num;
    scanf("%d%d",&n,&s);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmp);
    for(i=0;i<n;i++)
    {
       sum=0;
       for(j=i+1;j<n;j++)
           sum+=a[i]-a[j];
       if(sum<=s)
       {
          num=n-i;
          break;
       }
    }
    s-=sum;
    t=GCD(s,num);
    s/=t;
    num/=t;
    if(s>=num)
    {
        a[i]+=s/num;
        s-=s/num*num;
    }
    if(a[i]==0)
    {
        if(s==0) printf("0");
        else printf("%d/%d",s,num);
    }
    else
    {
        if(s==0) printf("%d",a[i]);
        else printf("%d+%d/%d",a[i],s,num);
    }
    return 0;
}
