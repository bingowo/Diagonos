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
        // char c ;
        // c = getchar();
        // gets(a);
        // ungetc(c,stdin);
        int count = 0;
        for(int i = 0;i < strlen(a);i++){
            unsigned char ch = a[i];
            for(int j = 0;j < 8;j++){
                if((ch>>j)&1)count++;
            }
        }
        int deno = strlen(a)*8;
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