#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char s[10001];
    int ret=0, r, bin[65], count=0;
    scanf("%s", s);
    long long a=0, b=0, temp=0, x1, x2;
    if(s[0]=='-') ret = 1;//表示当前的数为负数
    for(long long i=ret; i<strlen(s); i++){
        if(s[i]>='0'&&s[i]<='9'){
            temp = temp*10+(int)s[i]-48;
            continue;
        }else if(s[i]=='+'||s[i]=='-'){
            if(ret==0)  a = temp;
            else  a = temp*-1;
            ret = 0;
            temp = 0;
            if(s[i]=='-') ret = 1;
            continue;
        }else{
            if(ret==0){
                if(temp==0) b = 1;
                else b = temp;
            }else{
                if(temp==0) b = -1;
                else b = temp*-1;
            }
            temp = 0;
        }
    }
    if(temp!=0){
        if(ret==0) a = temp;
        else a = temp*-1;
    }
    while(a!=0||b!=0){
        r = 1;
        if(a%2==b%2||a%2==-1*(b%2)) r = 0;
        bin[count++] = r;
        x1 = (b-a+r)/2;
        x2 = (r-a-b)/2;
        a = x1; 
        b = x2;
    }
    for(int i=0; i<count; i++)
        printf("%d", bin[count-i-1]);
    
}