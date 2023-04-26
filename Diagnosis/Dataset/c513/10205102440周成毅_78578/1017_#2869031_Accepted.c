#include <stdio.h>
#include <string.h>
#include <math.h>

int trans(char s) {
    int a;
    switch (s) {
        case 'I':
            a = 1;
            break;
        case 'V':
            a = 5;
            break;
        case 'X':
            a = 10;
            break;
        case 'L':
            a = 50;
            break;
        case 'C':
            a = 100;
            break;
        case 'D':
            a = 500;
            break;
        case 'M':
            a = 1000;
            break;
        default:
            a = -1;
    }
    return a;
}

int main() {
    char s[51];
    int tag = 0;
    long long sum = 0;
    for (int i = 0; i < 51; i++) {
        s[i] = '\0';
    }
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == ')') {
            tag = 1;
            break;
        }
    }
    if (!tag) {
        for (int i = 0; i < len; i++) {
            int res = trans(s[i]);
            if (i == len - 1 || res >= trans(s[i + 1]))
                sum += res;
            else
                sum -= res;
        }
    }
    if (tag) {
        long long bit[20];
        int num=0,count=0,temp=0,tag1=0;
        for(int i=0;i<20;i++)
            bit[i]=0;
        for(int i=0;i<len;i++){
            if(s[i]=='(')
                count++;
        }
        for(int i=0;i<len;){
            if(s[i]!='(' && s[i]!=')' && tag1==0){
                int res = trans(s[i]);
                bit[num++]=res;
            }
            else if(s[i]=='('){
                tag1=1;
            }
            else if(s[i]==')')
                tag1=0;
            else if(s[i]!='(' && s[i]!=')' && tag1==1){
                for(;s[i]!=')';i++){
                    int res = trans(s[i]);
                    if (s[i+1] == ')' || res >= trans(s[i + 1]))
                        temp += res;
                    else
                        temp -= res;
                }
                bit[num++]=temp*pow(1000,count);
                continue;
            }
            i++;
        }
        for(int i=0;i<num;i++){
            long long res = bit[i];
            if(i==num-1 || res>=bit[i+1])
                sum+=res;
            else
                sum-=res;
        }
    }
    printf("%lld\n", sum);
    return 0;
}
