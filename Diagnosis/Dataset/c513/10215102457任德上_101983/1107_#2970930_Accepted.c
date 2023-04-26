#include<stdio.h>
void trans(int flag,int *n,int k,int p){
    if(k<0||k>2||p<0||p>2);
    else{
        *(n+k*3+p)=*(n+k*3+p)==1?0:1;
    }

}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int a[3][3];
        for(int k=0;k<3;k++){
            for(int p=0;p<3;p++)a[k][p]=1;
        }
        for(int k=0;k<3;k++){
            for(int p=0;p<3;p++){
                int flag;
                scanf("%d",&flag);
                if(flag%2==1){
                    trans(flag,a[0],k,p);
                    trans(flag,a[0],k,p-1);
                    trans(flag,a[0],k+1,p);
                    trans(flag,a[0],k,p+1);
                    trans(flag,a[0],k-1,p);
                }
            }
        }
        printf("case #%d:\n",i);
        for(int k=0;k<3;k++){
            for(int p=0;p<3;p++)printf("%d ",a[k][p]);
            printf("\n");
        }
    }
    return 0;
}