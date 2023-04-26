#include<stdio.h>
int main(){
    int t,a[10][10];
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int r,c,n,k,x,y,end=0;
        scanf("%d%d%d%d",&r,&c,&n,&k);
        for(int m=0;m<r;m++){
            for(int n=0;n<c;n++)a[m][n]=0;
        }
        for(int k=0;k<n;k++){
            scanf("%d%d",&x,&y);
            a[x-1][y-1]=1;
        }
        int sum=0;
        for(int m=0;m<r;m++){
            for(int n=0;n<c;n++){
                for(int q=m;q<r;q++){
                    for(int p=n;p<c;p++){
                        for(int m1=m;m1<=q;m1++){
                            for(int n1=n;n1<=p;n1++)sum+=a[m1][n1];
                        }
                        if(sum>=k)end++;
                        sum=0;
                    }
                }


            }
        }
        printf("case #%d:\n%d\n",i,end);
    }
    return 0;
}