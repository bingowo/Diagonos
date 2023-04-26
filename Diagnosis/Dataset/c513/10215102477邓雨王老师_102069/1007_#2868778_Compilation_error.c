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
        while(m>=1){
            if(m%2==0){
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
        for(j=0;j<strlen(s);j++){
            if(s[j]!=s[j+1]) sum=sum+1;
            else {
                max=sum;
                sum=1;
            };
        }
    }
    printf("%d\n",sum);
}