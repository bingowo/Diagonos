#include<stdio.h>
#include<string.h>

int main(){
    char digit[100] = {'\0'};
    long long int a = 0, b = 0, sum = 0;
    scanf("%s",digit);
    int i = 0, flag = 1, flag2 = 0;
    if(digit[0] == '-'){flag = -1;i++;}
    
        while(i < strlen(digit)){
            if(digit[i] <= '9' && digit[i] >= '0'){
                sum = sum*10 + digit[i] - '0';
                if(flag2 != 1)a = sum*flag;
            }
            else if(digit[i] == 'i'){
                b = sum*flag? sum*flag:flag;
                flag = 1;
                if(flag2 != 1)a = 0;
            }
            else{
                sum  = 0;
                flag2 = 1;
                if(digit[i] == '+')
                    flag = 1;
                else flag = -1;
            }
        i++;
        }//获取a,b
    
    int ans[100],j = 0;
    if(a == 0 && b == 0)ans[j++] = 0;
       else{ while(b != 0 || a != 0){
            long long int temp = a;
            ans[j++] = ((a%2)&1)^((b%2)&1);
            a = -a + b;
            b = -temp - b;
            if(a%2 == 1 || a%2 == -1){
                a++;
                b++;
            }
            a = a/2;
            b = b/2;
        }
       }
    j--;
    for(j;j >= 0;j--){
        printf("%d",ans[j]);
    }
}