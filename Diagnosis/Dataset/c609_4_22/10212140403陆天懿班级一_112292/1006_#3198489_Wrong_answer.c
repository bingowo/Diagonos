#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>
typedef long long ll;

int pros;
int len,n;
ll r;
ll num[63];
char s[63];

void Init(){
    memset(num,-1,sizeof(num));
    n=0;
}

ll Bi(int i){
    if(i==0) return 1;
    if(i==1) return 0;
    return i;
}

ll C2I(char c){
    if(c>='0'&&c<='9')
        return c-'0';
    else if(c>='A'&&c<='Z')
        return 10+c-'A';
    else
        return 36+c-'a';
}

void GetBase(){
    for(int i=0;i<len;i++){
        if(num[C2I(s[i])]<0){
            num[C2I(s[i])]=Bi(n);
            n++;
        }
    }
}

void GetR(){
    ll b=n<2?2:n;
    r=0;
    for(int i=0;i<len;i++){
        r=r*b+num[C2I(s[i])];
    }
}

int main(){
    scanf("%d",&pros);
    for(int cnt=0;cnt<pros;cnt++){
        Init();
        scanf("%s",s);
        len=strlen(s);
        GetBase();
        GetR();

        printf("case #%d:\n",cnt);
        printf("%d\n",r);
    }
    return 0;
}
