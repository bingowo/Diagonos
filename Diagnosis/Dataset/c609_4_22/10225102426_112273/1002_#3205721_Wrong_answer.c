#include<stdio.h>
int main()
{
    int T=0,i=0,j=0,k=0;
    int n=0,count=0,r=0;
    int b[50]={0};
    scanf("%d",&T);
    //每行问题
    for(i=0;i<T;i++){
        //初始化
        for(j=0;j<50;j++){
            b[j]=0;
        }
        j=0;
        count=1;
        r=0;
        scanf("%d",&n);
        //转二进制
        for(n=n;n>0;){
            b[j]=n%2;
            n=n/2;
            j++;
        }
        //检验重复
        for(k=1;k<j;k++){
            if(b[k]==b[k-1]){
                if(count>r){
                    r=count;
                    count=1;
                }
            }
            else{
                count++;
                if((k+1)==j&&count>r){
                    r=count;
                }
            }
        }
        if(j==1){
            r=0;
        }
        printf("case #%d:\n",i);
        printf("%d\n",r);
    }
    return 0;
}
