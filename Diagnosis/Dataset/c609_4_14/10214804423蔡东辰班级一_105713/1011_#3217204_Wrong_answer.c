#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int find(char* s);
int cal(int len);//计算分母，len是小数点之后的长度
long long GCD(long long m, long long n);
int main()
{
    long long result = 0;
    long long weight = 1;
    long long B, C = 0;//B分母,C分子
    int table[3] = {0, 1, -1};//数码0、1、2分别对应的权重值。
    char s[31];
    scanf("%s", s);
    if(find(s)<0){
        for(int i=strlen(s)-1; i>=0; i--){
            result += table[s[i]-'0'] * weight;
            weight *= 3;
        }
        printf("%d", result);
    }
    else{
        int len = strlen(s);
        for(int i=find(s)-1; i >= 0; i--){
            result += table[s[i]-'0'] * weight;
            weight *= 3;
        }
        B = cal(len-find(s)-1);//B分母
        weight = B/3;
        for(int i = find(s) + 1; i<len; i++){//算分子
            C += table[s[i]-'0'] * weight;
            weight /= 3;
        }
		int gcd = GCD((C>0)?C:-C, (B>0)?B:-B);
		C = C/gcd;
		B = B/gcd;
        if(result < 0){
            if(C<0){
                printf("%d %d %d", result, C, B);
            }
            else{
                printf("%d %d %d", result+1, B-C, B);
            }
        }
        else if(result > 0){
            if(C>0){
                printf("%d %d %d", result, C, B);
            }
            else{
                printf("%d %d %d", result-1, B+C, B);
            }
        }
        else{
        	printf("%d %d", C, B);
		}
    }
     return 0;

}
int find(char* s){
    int result = -1;
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == '.'){
            result = i;
            break;
        }
    }
    return result;
}
int cal(int len){
    int result = 1;
    for(int i=len; i>0; i--){
        result *= 3;
    }
    return result;
}
long long GCD(long long m, long long n){
    long long bigger = (m>=n)? m : n;
    long long smaller = (m>=n)? n : m;
    long long mod = bigger % smaller;
    if(mod == 0){
        return smaller;
    }
    return GCD(smaller, mod);
}
