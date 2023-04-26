#include <stdio.h>
#include <string.h>
void bi3(char*p,int n,int m){
    for(int j = 0;j<n;j++){
        int ret = 0;
        for(int i = 0;i<m;i++){
            ret = ret*10+(p[j*3+i]-'0');
        }
        for(int q = 3*m;q>=0;q--){
            int b = (ret>>q)&1;
            printf("%d",b);
        }
    }

}
int main() {
    char s[500];
    scanf("%s",s);
    printf("0001");
    int len = strlen(s);
    for(int i = 9;i>=0;i--){
        int a = (len>>i)&1;
        printf("%d",a);
    }
    int n = len/3;
    bi3(s,n,3);
    if(len%3==1){
        bi3(&(s[3*n]),1,1);
    } else if(len%3==2){
        bi3(&(s[3*n]),1,2);
    }
    return 0;
}
