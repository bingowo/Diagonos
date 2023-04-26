#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int gcd(int x, int y)
{
    while(y^=x^=y^=x%=y);
    return x;
}
int cal(char a){
    int tem = a,ans = 0;
    unsigned int temp = tem;
    if(tem<0){
        temp = temp & (~(~0<<8));
    }
    do{
        int t = temp&1;
        if(t == 1)
            ans++;
    }while(temp = temp>>1);
    return ans;

}

int main(){
    int n;
    scanf("%d",&n);
    char c;
    c = getchar();
    while(n--){
        char a[121];
        gets(a);
        int sum = 0;
        for(int i = 0;i < strlen(a);i++){
             sum += cal(a[i]);
        }
        int t = gcd(sum,strlen(a)*8);
        printf("%d/%d\n",sum/t,strlen(a)*8/t);
        }

    return 0;
}
