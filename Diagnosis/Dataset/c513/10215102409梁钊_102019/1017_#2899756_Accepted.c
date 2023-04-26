#include<stdio.h>
#include<string.h>
#include<math.h>
long long add_results(long long* results,int num)
{
    long long result = 0 ;
    for(int i=0;i!=num;i++){
        int j = i ; int flag = 1 ;
        while(++j < num){
            if(results[j] > results[i]) flag = 0 ;
        }
        if(flag) result += results[i] ;
        else result -= results[i] ;
    }
    return result ;
}

int main()
{
    char s[51] = {'0'} ;
    int table[150] ;
    table['I'] = 1 ;table['V'] = 5 ;table['X'] = 10 ;table['L'] = 50 ;
    table['C'] = 100 ;table['D'] = 500 ;table['M'] = 1000 ;
    scanf("%s",&s) ;
    long long results[51] ; long long* p = results ;
    for(int i=0;i!=strlen(s);i++){
        int j = i ;
        if(s[i] == '('){
            int a = 1 ; long long n[51] ; long long* q = n ; int num = 0 ;
            while(s[++i] == '(') a += 1 ;
            while(s[i] != ')') *(q++) = table[s[i++]] ;
            num = q - n ;
            *(p++) = add_results(n,num) * pow(1000,a) ;
        }
        else if(s[i]==')') ;
        else{
            *(p++) = table[s[i]] ;
        }
    }
    int num = p - results ; long long result = 0 ;
    result = add_results(results,num) ;
    printf("%lld",result) ;
}

