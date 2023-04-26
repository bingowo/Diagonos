#include <stdio.h>
void quickSort(long long *a, int low, int high)
{
    if(low >= high)
        return;
    int i=low, j=high;
    long long key=a[low];
    while(i<j)
    {
        while(i<j && key<=a[j])
            j--;
        a[i]=a[j];
        while(i<j && key>=a[i])
            i++;
        a[j]=a[i];
    }
    a[i]=key;
    quickSort(a, low, i-1);
    quickSort(a, i+1, high);
}
int main(void)
{
    int m, n, I, i;
    while(scanf("%d%d",&n,&m))
    {
        if(n==0) break;
        long long s[n];
        for(i=0; i<n; i++){
            s[i]=i+1;
            s[i]+=30000000000LL;}
        //for(i=0; i<n; i++) printf("%lld\n",s[i]);
        for(I=0; I<m; I++)
        {
            int a, b, c;
            scanf("%d%d%d",&a,&b,&c);
            if(c==1){
                s[a-1]-=300000000;
                s[a-1]+=100000;
                s[b-1]+=100000000;
                s[b-1]+=100;
            }else if(c==-1){
                s[b-1]-=300000000;
                s[b-1]+=100000;
                s[a-1]+=100000000;
                s[a-1]+=100;
            }else{
                s[a-1]-=100000000;
                s[b-1]-=100000000;
            }
        }
        for(i=0; i<n; i++)
            s[i]=(s[i]-200000*((s[i]/100000)%1000)+99900000);
        quickSort(s, 0, n-1);
        for(i=0; i<n; i++){
            if(i==n-1) printf("%d\n",s[i]%100);
            else printf("%d ",s[i]%100);}
    }
    return 0;
}