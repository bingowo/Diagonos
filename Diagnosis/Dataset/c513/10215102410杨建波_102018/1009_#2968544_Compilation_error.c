#include<stdio.h>
#include<string.h>

int gcd(int a, int b){
    if (!(b % a)) return a;
    return gcd(b % a, a);
}

int main(){
    int T;
   
    scanf("%d",&T); getchar();
    for(T;T > 0;T--){
        int i = 0; 
        char a[1000];
        char c;

        while((c = getchar())!='\n'){
            a[i++] = c;
        }
        a[i] = '\0';
        int deno = 0;
        int count = 0;
        for(int i = 0;i < strlen(a);i++){
           char ch = a[i];
            for(int j = 0;j < 8;j++){
                if((ch>>j)&1)count++;
            }
            deno += 8;
        }
        
        int n = gcd(count, deno);
        if(rem == 1)printf("%d/%d\n",count,strlen(a)*8);
        else printf("%d/%d\n",count/n,strlen(a)*8/n);
    }
}