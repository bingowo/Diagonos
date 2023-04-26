#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char s[501],s1[501];
        int num[501],num1=0,num2=0;
        scanf("%s",s);
        int k=0;
        while(s[k]){
            int time=1;
            char c=s[k];
            while(s[k+1]&&s[k]==s[k+1]&&time<255){
                time++;
                k++;
            }
            num[num1++]=time;
            s1[num2++]=c;
            k++;
        }
        printf("case #%d:\n",i);
        for(int k=0;k<num1;k++){
            printf("%d%c",num[k],s1[k]);
        }
        printf("\n");
    }
    return 0;
}