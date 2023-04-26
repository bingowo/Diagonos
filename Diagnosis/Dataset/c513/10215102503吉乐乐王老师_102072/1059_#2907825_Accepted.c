#include <stdio.h>
#include <stdlib.h>
int getlow(int a[],int n){
    int low=1;
        for(int i=1;i<=n;i++){
        if(a[i]<a[low])low=i;
    }
    return low;
}
int getheight(int a[],int n,int low,int left ,int right){
    int height;
    if(a[left]<a[right]){
        if(a[left]==a[low]){
            height=a[right];
            if(a[right]==a[low])height=1;
            if(a[right]>a[low])height-=a[low];
        }
        else {
            height=a[left];
            if(height>a[low])height-=a[low];}
    }
    if(a[right]<a[left]){
        if(a[right]==a[low]){
            height=a[left];
            if(a[left]==a[low])height=1;
            if(a[left]>a[low])height-=a[low];
        }
        else {
            height=a[right];
            if(height>a[low])height-=a[low];
        }
    }
    if(a[left]==a[right])height=1;
    return height;
}
int g(int a,int b){
    return a%b==0?b:g(b,a%b);
}
int main()
{
    int n,s;
    scanf("%d %d",&n,&s);getchar();
    int *a=(int *)malloc(sizeof(int)*(n+2));
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    a[0]=a[1];a[n+1]=a[n];
    int ret=a[1];int fenzi=0;int fenmu=0;
    int gcd;
    for(int i=1;i<=n;i++){
        if(a[i]<ret)ret=a[i];
    }
    while(s){
        int low=getlow(a,n);
        int width,height;
        int left,right;left=right=low;
        while(left>0&&a[left]<=a[low])left--;
        while(right<(n+1)&&a[right]<=a[low])right++;
        width=right-left-1;
        height=getheight(a,n,low,left,right);
        int v=width*height;
        if(v<=s){
            ret+=height;
            s-=v;
            for(int i=left+1;i<right;i++){
                a[i]+=height;
            }
            a[0]=a[1];a[n+1]=a[n];
            continue;
        }
        if(v>s){
            fenzi=s,fenmu=width;
            if(fenzi>=fenmu){
            ret+=fenzi/fenmu;
            fenzi%=fenmu;}
            gcd=g(fenzi,fenmu);
            s=0;
        }
    }
    if(fenzi){
        if(ret) printf("%d+%d/%d",ret,fenzi/gcd,fenmu/gcd);
        else printf("%d/%d",fenzi/gcd,fenmu/gcd);}
    else printf("%d",ret);
}
