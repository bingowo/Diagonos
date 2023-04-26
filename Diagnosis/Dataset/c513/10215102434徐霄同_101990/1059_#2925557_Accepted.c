#include <stdio.h>
int gcd(int m,int n)
{
    if(n==0)
        return m;
    return gcd(n,m%n);
}
int main()
{
    int a[1000],h[1000];
    int n,s,i,j,m,g;
    scanf("%d%d",&n,&s);
    m=0;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]>m)
            m=a[i];
    }
    for(i=0;i<m;i++){
        h[i]=0;
        for(j=0;j<n;j++)
            if(a[j]<=i)
                h[i]++;
    }
    i=0;
    while(i<m&&s>=h[i]){
        s=s-h[i];
        i++;
    }
    if(s==0)
        printf("%d\n",i);
    else{
        if(i<m){
            g=gcd(h[i],s);
            if(i!=0)
                printf("%d+%d/%d\n",i,s/g,h[i]/g);
            else
                printf("%d/%d\n",s/g,h[i]/g);
        }
        else{
            i=i+s/n;
            s=s%n;
            if(s==0)
                printf("%d\n",i);
            else{
                g=gcd(n,s);
                printf("%d+%d/%d\n",i,s/g,n/g);
            }
        }
    }
    return 0;
}
