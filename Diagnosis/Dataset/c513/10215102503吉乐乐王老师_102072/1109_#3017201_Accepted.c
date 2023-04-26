#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);getchar();
    int cas=0;
    int num[9];
    while(t--){
        for(int i=8;i>=0;i--){
            scanf("%d",&num[i]);
        }
        getchar();
        printf("case #%d:\n",cas++);
        int flag=0;
        int cnt=0;
        for(int i=8;i>=0;i--){
            if(num[i]!=0){
                flag=1;
                cnt++;
                if(cnt!=1&&num[i]>0)putchar('+');
                if(i==0){
                    printf("%d",num[i]);continue;}
                else if(num[i]==1){
                    printf("x");
                    if(i!=1)printf("^%d",i);
                }
                else if(num[i]==-1){
                    printf("-x");
                    if(i!=1)printf("^%d",i);
                }
                else{
                    printf("%dx",num[i]);
                    if(i!=1)printf("^%d",i);
                }
            }
        }
        if(flag==0)printf("0");
        putchar('\n');
    }
}