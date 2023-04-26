#include <stdio.h>
#include <math.h>
int main() {
    int t ;
    scanf("%d",&t);
    int i =0 ;
    for(;i<t;i++){
        unsigned int n;
        unsigned int cnt=  1;
        int len = 0;
        int len1 = 0;
        scanf("%ud",&n);
        for(int j = 0;j<31;j++){
            if((cnt&(n>>j))!=((cnt &(n>>(j+1))))){
                len++;
            }else{
                if(pow(2,j)>n){
                    len = len-1;
                }
                len1 = len1>len?len1:len;
                len = 0;
            }
        }
        len1 = len >len1?len-1:len1;
        len1 = len1 +1;
        
        if(n == pow(2,31)-1 || n==0){
            len1 = 0;
        }

        printf("case #%d:\n%d\n",i,len1);
    }

    return 0;
}
