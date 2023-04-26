#include <stdio.h>
#include <string.h>
#define N 501

void output(int a[],int len){
    int i;
    for(i=len-1;i>=0;i--){
        if(a[i]!=0) break;
    }
    for(;i>=0;i--){
        printf("%c",a[i]);
    }
}

int main() {
    char a[N];
    char b[N];
    scanf("%s",a);
    scanf("%s",b);
    int alen,blen,max_len,min_len;
    alen = strlen(a);blen= strlen(b);
    char A[N],B[N];
    for(int i=1;i<alen;i++){
        a[alen-i]=A[i-1];
    }
    for(int i=1;i<blen;i++){
        b[blen-i]=B[i-1];
    }
    if(alen > blen) max_len=alen,min_len=blen;
    else if(alen<blen) max_len=blen,min_len=alen;
    else if(alen=blen){
        for(int i=0;i<alen;i++){
            if(a[i]>b[i]) {max_len = alen;min_len=blen;break;}
            else if(a[i]<b[i]) {max_len = blen,min_len=alen;break;}
            else continue;
        }
    }
    if(max_len==alen){
        for(int i=max_len-1;i>=min_len;i--){
            B[i]='0';
        }
        for(int m=min_len-1;m>=0;m--){
            if(A[m]>=B[m]) A[m]=B[m]-B[m]+'0';
            else{
                A[m]=A[m]+10-B[m]+'0';
                A[m+1]--;
            }
        }
        output(A,alen);
    } else {
        for(int i=max_len-1;i>=min_len;i--){
            A[i]='0';
        }
        for (int m = min_len - 1; m >= 0; m--) {
            if (B[m] >= A[m]) B[m] = B[m] - A[m] + '0';
            else {
                B[m] = B[m] + 10 - A[m] + '0';
                B[m+1]--;
            }
        }
        printf("-");
        output(B,blen);
    }
    return 0;
}
