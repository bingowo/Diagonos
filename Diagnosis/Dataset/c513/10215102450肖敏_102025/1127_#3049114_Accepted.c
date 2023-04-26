#include <stdio.h>
int gcd(int a,int b)
{
    int r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main() {
    int n;
    scanf("%d",&n);
    int s[n][2];
    int a,b;
    for(int i=0;i<n;i++)
    {
        scanf("%d/%d",&a,&b);
        s[i][0]=a;
        s[i][1]=b;
    }
    if(n==1)
    {
        int y=gcd(a,b);
        printf("%d/%d\n",a/y,b/y);
    }
    else {
        int y = gcd(s[0][1], s[1][1]);
        int x=(s[1][1]*s[0][1])/y;
        int m=s[0][0]*s[1][1]/y+s[1][0]*s[0][1]/y;
        for (int i = 2; i < n; i++) {
            y = gcd(x,s[i][1]);
            m=m*s[i][1]/y+s[i][0]*x/y;
            x=(x*s[i][1])/y;
        }
        y=gcd(x,m);
        printf("%d/%d\n",m/y,x/y);
    }
    return 0;
}