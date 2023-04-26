#include<stdio.h>
int main(){
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++){
        int n,r;
        scanf("%d",&n);
        scanf("%d",&r);
        if(r<=10){
            int t=0;
            while(n>0){
                t=t+n%r;
                n=n/r;
            }
            int num=0;
            int m=t;
            while(t>0){
                t=t/r;
                num++;
            }
            int nu=num;
            int a[num];
            while(m>0){
                a[num-1]=m%r;
                m=m/r;
                num--;
            }
            printf("case #%d:\n",i);
            for(int j=0;j<nu;j++){
                printf("%d",a[j]);
            }
            printf("\n");
        }
        else{
            int t=0;
            while(n>0){
                t=t+n%r;
                n=n/r;
            }
            int num=0;
            int m=t;
            while(t>0){
                t=t/r;
                num++;
            }
            int nu=num;
            int a[num];
            while(m>0){
                a[num-1]=m%r;
                m=m/r;
                num--;
            }
            char s[nu];
            for(int j=0;j<nu;j++){
                if(a[j]<10){
                    s[j]=a[j]+'0';
                }
                else{
                    s[j]=a[j]+7+'0';
                }
            }
            printf("case #%d:\n",i);
            for(int j=0;j<nu;j++){
                printf("%c",s[j]);
            }
            printf("\n");
        }
    }
    return 0;
    
}