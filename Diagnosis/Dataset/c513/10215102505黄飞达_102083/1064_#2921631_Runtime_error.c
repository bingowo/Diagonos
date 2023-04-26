                         #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int mypow(int a, int b){
    int res = 1;
    for (int i = 1; i <= b; i++) res *= a;
    return res;
}

int main(){
    int T;
    scanf("%d ", &T);
    for (int t = 0; t < T; t++){

        char s[105] = {0};
        gets(s);
        int slen = strlen(s), index = 0;
        double arr[105] = {0};

        printf("case #%d:\n", t);
        for (int i = 0; i < slen; i++){
            if (isdigit(s[i])){
                for (int j = 0; j < 10; j++){
                    if (s[i+j]==' ' || i+j==slen){
                        char *stemp = (char*)malloc(16);
                        strcpy(stemp, s+i);
                        stemp[i+j] = '\0';
                        arr[index++] = atof(stemp);
                        i += j;
                        break;
                    }            
                }
            }
            else if (s[i] != ' '){
                switch(s[i]){
                    case '+':arr[index++]=-1;break;
                    case '-':arr[index++]=-2;break;
                    case '*':arr[index++]=-3;break;
                    case '/':arr[index++]=-4;break;
                }
            }
        }
        for (int i = index-1; i >= 0; i--){
            if (arr[i] < 0){
                switch((int)arr[i]){
                    case -1:arr[i] = arr[i+1]+arr[i+2];break;
                    case -2:arr[i] = arr[i+1]-arr[i+2];break;
                    case -3:arr[i] = arr[i+1]*arr[i+2];break;
                    case -4:arr[i] = arr[i+1]/arr[i+2];break;
                }
                for (int j = index-1; j > i+1; j--){
                    arr[j-1] = arr[j];
                }
            }
        }
        printf("%lf\n", arr[0]);
    }
    return 0;
}