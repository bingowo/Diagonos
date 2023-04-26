#include <stdio.h>
typedef struct{
    int num[50];
    int len;
} dig;
int main() {
    dig a[100]={0};
    a[0].num[0]=0;
    a[0].len=1;
    a[1].num[0]=1;
    a[1].len=1;
    a[2].num[0]=1;
    a[2].len=1;
    int n,k;
    scanf("%d%d",&k,&n);
    for(int i=3;i<n;i++){
        int carry=0,q=0;
        for(;q<a[i-1].len;q++){
            a[i].num[q]=a[i-1].num[q]*2+carry;
            carry= a[i].num[q]/10;
            a[i].num[q]%=10;
        }
        a[i].len=a[i-1].len;
        if(carry){
            a[i].num[q]=carry;
            a[i].len++;
        }
        if(i>k+1){
            for(int p=0;p<a[i-k-1].len;p++){
                if(a[i].num[p]<a[i-k-1].num[p]){
                    a[i].num[p+1]--;
                    int p2=p+1;
                    while(a[i].num[p2]<0){
                        a[i].num[p2]+=10;
                        a[i].num[p2+1]--;
                        p2++;
                    }
                    a[i].num[p]+=10;
                }
                a[i].num[p]=a[i].num[p]-a[i-k-1].num[p];
            }
            int len=a[i].len;
            while(a[i].num[len-1]==0){
                len--;
            }
            a[i].len=len;
        }
    }
    for(int t=a[n-1].len-1;t>=0;t--){
        printf("%d",a[n-1].num[t]);

    }
    return 0;
}
