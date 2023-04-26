#include <stdio.h>
#include <stdlib.h>
char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main() {
 int n,r,temp,i = 0;
 int a[100000];
 scanf("%d%d",&n,&r);
 if(n == 0)
    printf("0");
while(n!=0){
    temp = n%r;
    n /= r;
    if(temp < 0){
        n++;
        temp = temp - r;
    }
    a[i] = temp;
    i++;
}
i--;
for(;i>=0;i--){
    printf("%c",table[a[i]]);
}

 return 0;
}
