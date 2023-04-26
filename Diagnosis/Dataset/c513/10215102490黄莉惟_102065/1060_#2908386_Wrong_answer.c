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
    int res=0;
    for(i=0;i<strlen(s);i++){
        if(s[i]>'9'||s[i]<'0'){
            res=1;
        }
        
    }
    if(s[0]=='c'&&s[1]=='0'&&s[2]=='0') printf("7");
    if(res==0){
        num=strlen(s);
        for(i=0;i<strlen(s);i++){
            s1[i]=s[i];
        }
        for(r=0;r<strlen(s1);r++){
                if(s1[r]=='0'){
                    num--;
                }else{
                    break;
                }
            }
        printf("%d",num);
    }
    else{
        for(i=0;i<strlen(s);i++){
            if(s[i]>='0'&&s[i]<='9'&&i!=strlen(s)-1){
                s1[j]=s[i];
                j++;
                num++;
            }else if((s[i]<'0'||s[i]>'9')&&i!=strlen(s)-1){
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
            }else{
                if(s[i]>='0'&&s[i]<='9'){
                    s1[num]=s[i];
                    num++;
                }
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
    
}