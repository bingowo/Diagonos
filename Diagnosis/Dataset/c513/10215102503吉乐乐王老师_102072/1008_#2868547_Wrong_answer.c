#include<stdio.h>
typedef unsigned long long ull;
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        ull x,y;
        scanf("%d %d",&x,&y);
        int cnt=0;
        for(int i=0;i<sizeof(ull)*8;i++){
            if(((x>>i)&1)!=((y>>i)&1))cnt++;
        }
        printf("%d\n",cnt);
    }
}