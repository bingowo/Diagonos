#include<stdio.h>

int main(){
    int A, B;
    char ans[101] = {'\0'};
    scanf("%d %d", &A, &B);
    int p = 0;
    if(A < 0){
        A = -A;
        p = 1;
    }
    int inter = A / B;
    int a = A - inter * B; 
    int rem, i = 0;
    while(inter > 0){
        rem = inter % 3;
        inter /= 3;
        ans[i++] = rem + '0';
    }
    for(int j = 0;j < i/2;j++){
        int t = ans[i-1-j];
        ans[i-1-j] = ans[j];
        ans[j] = t;
    }
    int comma = 0;
    if(a != 0){
        comma = i;
        ans[i++] = '.';
    }
    while(a > 0){
        B = B / 3;
        rem = a / B;
        a = a - B * rem;
        ans[i++] = rem + '0';
    }
    int x = 0, n;
    char ans2[101] ;
    
    if( p == 1){
        for(int j = 0;j < i;j++){
                if(ans[i-1-j] == '.') ans2[j] = '.';
                else{
                    n = -ans[i-1-j] + 1 + x + '0';
                    if(n < 0){
                        x = -1;
                    }
                    else x = 0;
                    if(n + 3 - 1 == -1)ans2[j] = '2';
                    else ans2[j] = (n + 3 - 1) + '0';
                }
            }
            if(x == 1)ans2[i++] = '1';
    }


    else{
        for(int j = 0;j < i;j++){
                if(ans[i-1-j] == '.') ans2[j] = '.';
                else{
                    n = ans[i-1-j] + 1 + x - '0';
                    if(n >= 3)x = 1;
                    else x = 0;
                    if(n % 3 - 1 == -1)ans2[j] = '2';
                    else ans2[j] = (n%3-1) + '0';
                }
            }
            if(x == 1)ans2[i++] = '1';
    }

    while(ans2[i-1] == '0'){
            i--;
        }
    int m = 0;
    if(comma != 0){
        while(ans2[m] == '0')m++;
    }
    if(ans[i-1] == '.'){printf("0.");i--;}
    int flag = 0;
    for(int j = i - 1;j >= m;j--){
        printf("%c", ans2[j]);
    }

}