#include <stdio.h>
int main() {
    int T;
    scanf("%d",&T);
    int a[25] = {2,3,5,7,11,13,17,19,23,29,31,37,42,43,47,
                 53,59,61,67,71,73,79,83,89,97};
    for(int i=0;i<T;i++){
        int num1[25];
        int num2[25];
        int ret[26];
        int j=0,p=0;
        do{
            scanf("%d",&num1[j++]);
        }while(getchar()!=' ');
        do{
            scanf("%d",&num2[p++]);
        } while (getchar()!='\n');
        int q= 0;
        int add = 0;
        for(;q<p&&q<j;q++){
            if(num1[j-q-1]+num2[p-q-1]+add>=a[q]){
                ret[q] = num1[j-q-1]+num2[p-q-1]+add-a[q];
                add =1;
            }else{
                ret[q] = num1[j-q-1]+num2[p-q-1]+add;
                add=0;
            }
        }if(j>p){
            while(j>q){
                if(num1[j-q-1]+add>=a[q]){
                    ret[q] =num1[j-q-1]+add-a[q];
                    add = 1;
                }else {
                    ret[q] =num1[j-q-1]+add;
                    add = 0;
                }
                q++;
            }
        }else if(j<p){
            while(p>q){
                if(num2[p-q-1]+add>=a[q]){
                    ret[q] =num2[p-q-1]+add-a[q];
                    add = 1;
                }else {
                    ret[q] =num2[p-q-1]+add;
                    add = 0;
                }
                q++;
            }
        }if(add){
            ret[q] = 1;
            q= q+1;
        }
        printf("case #%d:\n",i);
        for(int m =0;m<q;m++){
            printf("%d%c",ret[q-m-1],m==q-1?'\n':',');
        }
    }
    return 0;
}
