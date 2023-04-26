#include <cstdio>
#include <cstring>
const int N = 10010;
using namespace std;
int tmp[N];
int tmp2[N];
int ans[N];
int cnt = 0;
int sig = 0;
char s[N];
int count = 0;
int len;
int r;
void BigD(int b){
    for(int i = 0; i<len; i++){
        r = r*10+tmp[i];
        tmp2[i] = r/b;
        r%=b;
    }
    memset(tmp,0,sizeof(tmp));
    int res = len-1;
    for(int i =0; i<len; i++){
        if(tmp2[i]){
            res = i;
            break;
        }
    }
    int begin = 0;
    for(int i = res; i<len; i++){
        tmp[begin++] = tmp2[i];
    }
    len = len-res;
    memset(tmp2,0,sizeof tmp2);
}
void Bigp(){
    int t = 1;
    for(int i = len-1; i>=0; i--){
        t+=tmp[i];
        tmp[i] = t%10;
        t/=10;
    }
    if(t){
        int k[N];
        k[0] = 1;
        for(int i = 0; i<len; i++) k[i+1] = tmp[i];
        for(int i = 0; i<len+1; i++) tmp[i] = k[i];
        len++;
    }
}
int main(){
    scanf("%s",s);
    len = strlen(s);
    if(s[0]=='-'){
        sig = 1;
        for(int i = 1; i<len; i++) tmp[i-1] = s[i]-'0';
        len--;
    }
    else{
        for(int i = 0; i<len; i++) tmp[i] = s[i]-'0';
    }
    while(1){
        if(sig){
            for(int i = 0; i<len; i++) tmp[i] = -tmp[i];
            BigD(-2);
            if(r<0){
                r+=2;
                Bigp();
            }
            ans[cnt++] = r;
            r = 0;
            sig = 0;
        }
        else{
            BigD(2);
            sig = 1;
            ans[cnt++] = r;
            r = 0;
        }
        if(!tmp[0]) break;
    }
    for(int i = cnt-1; i>=0; i--) printf("%d",ans[i]);
    return 0;
}