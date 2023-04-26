#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int gcd(int x, int y)
{
    while(y^=x^=y^=x%=y);
    return x;
}
int cal(unsigned int a){
    int temp = 0,t = a & (-a);
    do{
        if(a&1){
            temp++;
        }
        t = a & (-a);
    }while(a>>t);
    return temp;
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
        printf("%d/%d\n",sum/t,sizeof(a)*8/t);
        }

    return 0;
}
