#include<stdio.h>

int main(){
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        int n,m;
        scanf("%d%d",&n,&m);
        printf("case #%d:\n",a);
        printf("0.");
        int s[100]={0},y[100]={0},flag=0;
        for(int i=1;flag==0;i++){
            if(n==0){
                flag=1;
                for(int j=1;j<i;j++)printf("%d",s[j]);
                printf("\n");
            }
            else{
                if(y[n]!=0){
                    flag=1;
                    for(int j=1;j<i;j++)printf("%d",s[j]);
                    printf("\n");
                    printf("%d-%d\n",y[n],i-1);
                }
                else{
                    y[n]=i;
                    s[i]=n*10/m;
                    n=n*10%m;
                }
            }
        }
        a++;
    }
}