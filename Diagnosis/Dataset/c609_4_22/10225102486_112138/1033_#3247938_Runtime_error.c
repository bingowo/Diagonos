#include<stdio.h>
#include<string.h>
int main(){
    int A,B,i=0,number=0,temp;
    char num[100];
    scanf("%d %s %d",&A,num,&B);
    for(i=0;i<strlen(num);i++){
        if(num[i]>='0'&&num[i]<='9'){
            temp=num[i]-'0';
        }
        else if(num[i]>='a'&&num[i]<='f'){
            temp=num[i]-'a'+10;
        }
        else if(num[i]>='A'&&num[i]<='F'){
            temp=num[i]-'A'+10;
        }
        number=number*A+temp;
    }
    int ans[100],j=0;
    if(num==0)
        printf("%d",num);
    else{
        while(number){
            ans[j++]=number%B;
            number/=B;
        }
        for(int k=j-1;k>=0;k--){
            if(ans[k]>=10)
                printf("%c",ans[k]+'A'-10);
            else
                printf("%d",ans[k]);
        }
    }
    return 0;
}