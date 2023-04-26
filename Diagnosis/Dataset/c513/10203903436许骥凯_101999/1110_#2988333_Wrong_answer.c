#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char s[81]; scanf("%s", s);
    int slen = strlen(s), coef = 0, nor = 0, temp = 0, flag = 0, left = 1;
    char c;
    for (int i = 0; i != slen; i++){
        if (isdigit(s[i])) temp = temp * 10 + s[i] - '0';
        else if (isalpha(s[i])){
            if (temp){
                if (left && flag || !left && !flag) coef -= temp;
                else coef += temp;
            } 
            else{
                if (left && flag || !left && !flag) coef--;
                else coef++;               
            }          
            temp = 0;
            c = s[i];
        }
        else if (s[i] == '='){
            if (temp) nor += flag? temp: -temp;
            temp = 0; left = 0; flag = 0;
        }
        else if (s[i] == '-'){
            if (temp){
                if (left && flag || !left && !flag) nor += temp;
                else nor -= temp;
            }
            temp = 0;
            flag = 1;
        }
        else if (s[i] == '+'){
            if (temp){
                if (left && flag || !left && !flag) nor += temp;
                else nor -= temp;                
            }
            temp = 0;
            flag = 0;
        }
    }    
    double res = nor * 1.0 / coef;
    printf("%c=%.3f", c, res);
    return 0;
}