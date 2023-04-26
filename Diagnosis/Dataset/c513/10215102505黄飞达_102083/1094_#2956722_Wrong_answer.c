#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int res[1005]={0};

int cmp(const void*a, const void*b){
    return strcmp((char*)a, (char*)b);
}

void getDis(char *a, char *b){
    int f1=1, f2=1, alen=strlen(a), blen=strlen(b);
    if (a[0]=='-'){f1=-1; memmove(a, a+1, alen);alen--;}
    if (b[0]=='-'){f2=-1; memmove(b, b+1, blen); blen--;}
    int aarr[120]={0}, barr[120]={0};
    for (int i=0; i<blen; i++) barr[i]=b[blen-i-1]-'0';
    for (int i=0; i<alen; i++) aarr[i]=a[alen-i-1]-'0';
    if (f1==f2) {
        for (int i=0; i<blen; i++){
            res[i]+=barr[i]-aarr[i];
            if (res[i]<0) {res[i]+=10; res[i+1]--;}
        }
        int index=blen;
        while(index>=0 && res[index]==0)index--;
        if (index<0) printf("0");
        else if (f1==-1) printf("-");
        for (int i=index; i>=0; i--) printf("%d", res[i]);
        printf("\n");
    }
    else {
        int up=0;
        for (int i=0; i<blen; i++){
            res[i]+=barr[i]+aarr[i]+up;
            if (res[i]>=10) {up=res[i]/10; res[i]-=10;}
        }
        int index=blen+1;
        while(index>=0 && res[index]==0)index--;
        if (index<0) printf("0");
        for (int i=index; i>=0; i--) printf("%d", res[i]);
        printf("\n");
    }
    return;
}

int main(){
    int n;
    scanf("%d ", &n);
    char s[51][121]={0};
    int maxlen=0;
    for (int i=0; i<n; i++) {
        gets(s[i]);
        if (maxlen<strlen(s[i])) maxlen=strlen(s[i]);
    }
    for (int i=0; i<n; i++) {
        int len=strlen(s[i]);
        memmove(s[i]+maxlen-len, s[i], len);
        for (int j=0; j<maxlen-len; j++) s[i][j]='0';
    }
    qsort(s, n, 121, cmp);
    getDis(s[0]+maxlen-strlen(s[0]), s[n-1]);
    return 0;
}