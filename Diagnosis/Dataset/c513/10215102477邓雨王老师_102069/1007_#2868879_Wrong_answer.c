#include<stdio.h>
#include<string.h>
int main(){
    int chance;
    scanf("%d",&chance);
    int i;
    for(i=0;i<chance;i++){
        printf("case #%d:\n",i);
        char s[100];
        int m;
        int n=0;
        scanf("%d",&m);
        int p;
        if(m==1 | m==2) p=1;
        else if(m==3) p=2;
        else p=strlen(s);
        while(m>=1){
            if(m%2!=0){
                s[n]='1';
                n=n+1;
                m=m/2;
            }
            else {
                s[n]='0';
                n=n+1;
                m=m/2;
            }
        }
        int sum=1,max=1;
        int j;
        if(p>1){
        for(j=0;j<strlen(s)-1;j++){
            if(s[j]!=s[j+1]){
                sum=sum+1;
                if(sum>max) max=sum;
            }
            else {
                sum=1;
            };
        }}
        else max=1;
        printf("%d\n",max);
    }
}