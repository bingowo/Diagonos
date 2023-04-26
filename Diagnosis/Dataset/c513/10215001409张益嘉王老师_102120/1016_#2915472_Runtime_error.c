#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(int a[],int len)
{

    int i;
    char m;
    for(i=0;i<len/2;i++)
    {
        m=a[i];
        a[i]=a[len-i-1];
        a[len-i-1]=m;

    }

}

int chufyu(int n,int r)
{
    int shang,yu;
    if((n%r)==0) {shang=n/r;yu=0;}
    else shang=n/r+1;
    yu=shang*r-n;
    return yu;


}

int chufshang(int n,int r)
{
    int shang,yu;
    if((n%r)==0) {shang=n/r;yu=0;}
    else shang=n/r+1;

    return shang;


}

int main()
{
    int n,r,ans[300],i,j,co,n0;
    char re[300];
    memset(re,0,sizeof(char)*300);
    memset(ans,0,sizeof(int)*300);
    scanf("%d%d",&n,&r);
    r=-r;
    n0=n;
    if(n==0) printf("0");
    else if(n>0)
    {
        for(i=0;;i++)
        {
            if((i%2)==0)
            {
                ans[i]=n%r;
                n/=r;
            }
            else
            {
                ans[i]=chufyu(n,r);
                n=chufshang(n,r);
            }
            if(n==0) break;
        }
        co=i+1;
    }
    else
    {
        n=-n;
        for(i=0;;i++)
        {
            if((i%2)!=0)
            {
                ans[i]=n%r;
                n/=r;
            }
            else
            {
                ans[i]=chufyu(n,r);
                n=chufshang(n,r);
            }
            if(n==0) break;
        }
        co=i+1;
    }
    reverse(ans,co);
    for(i=0;i<co;i++)
    {
        if((ans[i]>=0)&&(ans[i]<=9)) re[i]=ans[i]+'0';
        else
        {
            re[i]=ans[i]+'A'-10;
        }
        //printf("test: ans[%d]=%d re[%d]=%c\n",i,ans[i],i,re[i]);
    }
   if(n0!=0) printf("%s",re);
}
