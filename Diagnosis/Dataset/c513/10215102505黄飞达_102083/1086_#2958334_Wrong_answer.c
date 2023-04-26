#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int max(int a, int b){return a>b?a:b;}

int main(){
    char A[505]={}, B[505]={};int n; 
    scanf("%s %s %d", A, B, &n);
    int lena=strlen(A),lenb=strlen(B),lenc=max(lena,lenb);
    A[lena]='.',B[lenb]='.';
    int posa=strstr(A, ".")-A, posb=strstr(B, ".")-B,posc=max(posa,posb);
    for (int i=lena+1; i<lenc; i++) A[i]='0';
    for (int i=lenb+1; i<lenc; i++) B[i]='0';
    memmove(A+posc-posa, A, lenc);
    for (int i=0; i<posc-posa; i++) A[i]='0';
    memmove(B+posc-posb, B, lenc);
    for (int i=0; i<posc-posb; i++) B[i]='0';
    if (strcmp(A, B)<0){
        char temp[505]={};
        for (int i=0; i<lenc; i++) {temp[i]=A[i];A[i]=B[i];B[i]=temp[i];}
        printf("-");
    }
    int res[505]={};
    lenc=strlen(A)-1,posc=strstr(A, ".")-A;
    for (int i=0; i<lenc; i++) res[i]=A[i]-B[i];
    for (int i=lenc-1; i>posc; i--) if (res[i]<0){res[i]+=10;res[i-1]--;}
    res[posc-1]+=res[posc];
    for (int i=posc-1; i>0; i--) if (res[i]<0) {res[i]+=10; res[i-1]--;}
    res[posc]=0;
    if (res[posc+n+1]>=5) res[posc+n]++;
    for (int i=posc+n; i>posc; i--) if (res[i]==10){res[i]=0; res[i-1]++;}
    if (res[posc]==1){
        res[posc-1]++;
        for (int i=posc-1; i>0; i--) if (res[i]==10){res[i]=0; res[i-1]++;}
    }
    for (int i=0; i<posc; i++) printf("%d", res[i]);
    if (0>=posc) printf("0");
    printf(".");

    for (int i=posc+1; i<=posc+n; i++) printf("%d", res[i]);
    return 0;
}