#include<stdio.h>
#include<string.h>

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
        
        printf("%d\n", deno);
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