#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int res[1005]={0};
int cmp(const void*a, const void*b){
    return strcmp((char*)a, (char*)b);
}
void getDis(char *a, char *b){
    int f1=1, f2=1, alen=strlen(a), blen=strlen(b);
    if (a[0]=='-'){f1=-1; a[0]='0';}
    else {memmove(a+1, a, alen); a[0]='0';alen++;}
    if (b[0]=='-'){f2=-1; b[0]='0';}
    else {memmove(b+1, b, blen); b[0]='0';blen++;}
    if (strcmp(a, b)>0){
        char *temp=a;
        a=b;
        b=temp;
        int t=alen;
        alen=blen;
        blen=t;
    }
    int aarr[125]={0}, barr[125]={0};
    for (int i=0; i<blen; i++) barr[i]=b[blen-i-1]-'0';
    for (int i=0; i<alen; i++) aarr[i]=a[alen-i-1]-'0';
    if (f1==f2) {
        for (int i=0; i<blen; i++){
            res[i]+=barr[i]-aarr[i];
            if (res[i]<0) {res[i]+=10; res[i+1]--;}
        }
        int index=125;
        while(index>=0 && res[index]==0)index--;
        if (index<0) printf("0");
        for (int i=index; i>=0; i--) printf("%d", res[i]);
        printf("\n");
    }
    else {
        int up=0;
        for (int i=0; i<blen; i++){
            res[i]+=barr[i]+aarr[i]+up;
            up=0;
            if (res[i]>=10) {up=res[i]/10; res[i]-=10;}
        }
        int index=125;
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
    char s1[51][125]={0},s2[51][125]={0};
    int i1=0, i2=0, ml1=0, ml2=0;
    while(i1+i2<n){
        char stemp[125]={0};
        gets(stemp);
        int len=strlen(stemp);
        if (stemp[0]=='-') {
            strcpy(s2[i2], stemp);
            if (ml2<len) ml2=len;
            i2++;
        }
        else {
            strcpy(s1[i1], stemp);
            if (ml1<len) ml1=len;
            i1++;
        }
    }
    for (int i=0; i<i1; i++) {
        int len=strlen(s1[i]);
        memmove(s1[i]+ml1-len, s1[i], len);
        for (int j=0; j<ml1-len; j++) s1[i][j]='0';
    }
    for (int i=0; i<i2; i++) {
        int len=strlen(s2[i]);
        memmove(s2[i]+ml2-len, s2[i], len);
        for (int j=1; j<=ml2-len; j++) s2[i][j]='0';
    }
    qsort(s1, i1, 125, cmp);
    qsort(s2, i2, 125, cmp);
    char max[125]={0}, min[125]={0};
    if (s1[0][0]!='\0') {
        strcpy(max, s1[i1-1]);
        if (s2[0][0]!='\0') strcpy(min, s2[i2-1]); 
        else strcpy(min, s1[0]); 
    }
    else {
        strcpy(max, s2[0]);
        strcpy(min, s2[i2-1]);
    }
    getDis(min, max);
    return 0;
}