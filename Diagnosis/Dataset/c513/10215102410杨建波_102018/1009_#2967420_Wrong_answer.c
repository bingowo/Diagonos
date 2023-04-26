#include<stdio.h>
#include<string.h>

int main(){
    int T;
    char a[100];
    scanf("%d",&T);
    for(T;T > 0;T--){
        scanf("%s",a);
        int count = 0;
        for(int i = 0;i < strlen(a);i++){
            int ch = (int)a[i];
            for(int j = 0;j < 8*sizeof(int);j++){
                if((ch>>j)&1 == 1)count++;
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