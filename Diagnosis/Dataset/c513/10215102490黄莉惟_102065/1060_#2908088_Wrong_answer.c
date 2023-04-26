#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main(){
    char s[1000];
    char s1[1000];
    scanf("%s",s);
    int i,num,r;
    int j=0;
    int max=0;
    for(i=0;i<strlen(s);i++){
        if(s[i]>='0'&&s[i]<='9'){
            s1[j]=s[i];
            j++;
            num++;
        }else{
            for(r=0;r<num;r++){
                if(s1[r]=='0'){
                    num--;
                }else{
                    break;
                }
            }
            if(num>max){
                max=num;
            }
            j=0;
            num=0;
            memset(s1,0,sizeof(s1));
        }
    }
    printf("%d",max);
}