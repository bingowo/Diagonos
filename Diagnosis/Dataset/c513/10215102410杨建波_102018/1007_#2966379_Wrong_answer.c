#include<stdio.h>

int main(){
    int T,n;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        scanf("%d",&n);
        int rem, a[100],j = 0,count = 1,flag = 0,form = 0;
        while(n != 0){
            rem = n %2;
            n = n / 2;
            a[j++] = rem;
        }
        for(int c = 0;c < j-1;c++){
            if(a[c] != a[c+1]) {
                count++;
                flag = 1;
            }
            else if(flag == 1){
                form = form > count? form:count;
                count = 1;
                flag = 0;
            }
        }
        printf("case #%d:\n%d\n",i,form);
    }
}