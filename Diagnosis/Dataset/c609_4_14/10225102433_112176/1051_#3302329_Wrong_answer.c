#include <stdio.h>
#include <string.h>

int A[1001];
int B[1001];
int C[1001];
int N;

void Bigsub(const int *a,const int *b)
{
    for(int i = 1000,t = 0;i >= 0;i--){
        t = a[i]-t;
        t -= b[i];
        C[i] = (t+10)%10;
        if(t < 0) t = 1;
        else t = 0;
    }
}

int cmp(char *a,char *b)
{
    int lena = strlen(a);
    int lenb = strlen(b);
    int sig1 = 0,sig2 = 0;
    for(int i = 0;i < lena;i++){
        if(a[i] == '.') {
            sig1 = i;
            break;
        }
    }
    for(int i = 0;i < lenb;i++){
        if(b[i] == '.') {
            sig2 = i;
            break;
        }
    }
    if(sig1 != sig2){
        if(sig1 > sig2){
            if(sig1 == 1 && a[0] == '0') return 0;
            else return 1;
        }
        else{
            if(sig2 == 1 && b[0] == '0') return 1;
            else return 0;
        }
    }
    else{
        if(strcmp(a,b) > 0) return 1;
        else return 0;
    }
}

void init_set(char *s,int *arr)
{
    int cnt = 0;
    int len = strlen(s);
    int flag = 0,idx = 0;
    for(int i = 0;i < len;i++){
        if(s[i] == '.'){
            flag = 1;
            idx = i;
            break;
        }
    }
    if(flag){
        for(int i = idx+1;i < len;i++){
            arr[501+cnt] = s[i]-'0';
            cnt++;
        }
        cnt = 0;
        for(int i = idx-1;i >= 0;i--){
            arr[500-cnt] = s[i]-'0';
            cnt++;
        }
    }
    else{
        for(int i = len-1;i >= 0;i--){
            arr[500-cnt] = s[i] - '0';
            cnt++;
        }
    }
}

int main()
{
    char a[501] = {0},b[501] = {0};
    scanf("%s %s %d",a,b,&N);
    init_set(a,A);
    init_set(b,B);
    if(cmp(a,b)) Bigsub(A,B);
    else{
        printf("-");
        Bigsub(B,A);
    }
    int ans = 500+N;
    if(C[ans] >= 5){
        int t = 1;
        for(int i = ans-1;i >= 0;i--){
            t += C[i];
            C[i] = t%10;
            t /= 10;
        }
    }
    int begin = 0;
    for(int i = 0;i < 1001;i++){
        if(C[i] != 0){
            begin = i;
            break;
        }
    }
    if(begin > ans){
        printf("0.");
        while(N--) printf("0");
    }
    else{
        if(begin <= 500){
            for(int i = begin;i < 501;i++){
                printf("%d",C[i]);
                if(i == 500) printf(".");
            }
        }
        else{
            printf("0.");
        }
        for(int i = 501,j = 0;j < N;i++,j++) printf("%d",C[i]);
    }
    return 0;
}