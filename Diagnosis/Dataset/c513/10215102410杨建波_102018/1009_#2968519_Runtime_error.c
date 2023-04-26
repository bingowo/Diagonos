#include<stdio.h>
#include<string.h>

int main(){
    int T;
   
    scanf("%d",&T);
    for(T;T > 0;T--){
        int i = 0; 
        char a[100];
        char c;
        getchar();
        while((c = getchar())!='\n'){
            a[i++] = c;
        }
        ungetc(c,stdin);
        a[i] = '\0';

        int deno = 0;
        int count = 0;
        for(int i = 0;i < strlen(a);i++){
           unsigned char ch = a[i];
            while(ch){
                count += (ch & 1);
                ch >>= 1;
            }
            deno += 8;
        }
        
        int rem = count,n;
        while(rem > 1 ){
            n = rem;
            rem =  deno % rem;
            deno = count;
        }
        if(rem == 1)printf("%d/%d\n",count,strlen(a)*8);
        else printf("%d/%d\n",count/n,strlen(a)*8/n);
    }
}