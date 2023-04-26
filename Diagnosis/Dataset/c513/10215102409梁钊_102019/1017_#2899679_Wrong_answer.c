#include<stdio.h>
#include<string.h>

int main()
{
    char s[51] = {'0'} ;
    int table[150] ;
    table['I'] = 1 ;table['V'] = 5 ;table['X'] = 10 ;table['L'] = 50 ;
    table['C'] = 100 ;table['D'] = 500 ;table['M'] = 1000 ;
    scanf("%s",&s) ;
    long results[51] ; long* p = results ;
    for(int i=0;i!=strlen(s);i++){
        int j = i ;
        if(s[i] == '('){
            int a = 1 ;
            while(s[++i] == '(') a += 1 ;
            *(p++) = table[s[i]] * a * 1000 ;
        }
        else if(s[i]==')') ;
        else{
            *(p++) = table[s[i]] ;
        }
    }
    int num = p - results ; long result = 0 ;
    for(int i=0;i!=num;i++){
        int j = i ; int flag = 1 ;
        while(++j < num){
            if(results[j] > results[i]) flag = 0 ;
        }
        if(flag) result += results[i] ;
        else result -= results[i] ;
    }
    printf("%ld",result) ;
}