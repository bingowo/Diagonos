#include <stdio.h>

int MAX(int x){
    int s[31],i;
    for(i=0;x>0;i++){
        s[i]=x%2;
        x/=2;
    }
    i--;
    int L,R=0,length=1;
    for(L=0;L<i;L++){
        if(s[L]==s[L+1]){
            if(length<(L-R+1))
                length=L-R+1;
            R=L+1;
            continue;
        }
    }
    return length;
}

int main(){
    int n,T;
    int i=0;
    scanf("%d\n",&n);
    while(scanf("%d\n",&T)!=EOF){
        printf("case #%d:\n%d\n",i++,MAX(T));
    }
    return 0;
}