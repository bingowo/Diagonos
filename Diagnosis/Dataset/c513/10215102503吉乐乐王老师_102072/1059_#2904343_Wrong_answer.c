#include <stdio.h>
#include <stdlib.h>
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
        int low=1;int width,height;
        for(int i=1;i<=n;i++){
            if(a[i]<a[low])low=i;
        }
        int left,right;left=right=low;
        while(left>0&&a[left]<=a[low])left--;
        while(right<(n+1)&&a[right]<=a[low])right++;
        width=right-left-1;
        height=a[left]<=a[right]?a[left]:a[right];
        double v=width*height;
        if(v<=s){
            ret+=height;
            s-=v;
            for(int i=left+1;i<right;i++){
                a[i]+=height;
            }
        }
        if(v>s){
            fenzi=v-s,fenmu=v;
            gcd=(fenzi,fenmu);
            s=0;
        }
    }
    if(fenzi)printf("%d+%d/%d",ret,fenzi/gcd,fenmu/gcd);
    else printf("%d",ret);
}
