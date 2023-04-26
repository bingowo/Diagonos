#include <stdio.h>
#include <stdlib.h>

char A[1234];
char B[1234];
int ans[1234];
int f=1;

void exchange(){
    char temp[1234];
    strcpy(temp,A);
    strcpy(A,B);
    strcpy(B,temp);
}

void check(){
    int i=0,j=0;
    int lena=strlen(A);
    int lenb=strlen(B);
    while (i<lena && A[i]!='.') i++;
    while (j<lenb && B[j]!='.') j++;
    if (i<j) {
        exchange();
        f=-1;
        return;
    }
    if (i==j){
        int k=0;
        while (A[k]==B[k] && k<strlen(A)) k++;
        if (A[k]<B[k]){
            exchange();
            f=-1;
            return;
        }
    }
}

int main()
{
    int m;
    scanf("%s %s %d",A,B,&m);
    check();
    int i=0,j=0;
    int lena=strlen(A);
    int lenb=strlen(B);
    while (i<lena && A[i]!='.') i++;
    while (j<lenb && B[j]!='.') j++;
    if (i==lena) A[lena]='.',lena++;
    if (j==lenb) B[lenb]='.',lenb++;
    while (i>j){
        for (int k=strlen(B);k>=1;k--)
            B[k]=B[k-1];
        B[0]='0';
        j++;
        lenb++;
    }
    while (lena<lenb){
        A[lena]='0';
        lena++;
    }
    while (lenb<lena){
        B[lenb]='0';
        lenb++;
    }
    int dot=0;
    while (A[dot]!='.') dot++;
    for (int i=strlen(A)-1;i>=0;i--){
        if (A[i]=='.') continue;
        int x=A[i]-'0';
        int y=B[i]-'0';
        int j=i-1;
        if (A[j]=='.') j--;
        if (x<y) {
            x+=10;
            A[j]--;
        }
        ans[i]=x-y;
    }
    if (ans[dot+m+1]>=5) {
        int i=dot+m;
        while (ans[i]==9){
            ans[i]=0;
            i--;
            if (i==dot) i--;
        }
        ans[i]++;
    }
    i=0;
    while (ans[i]==0 && i<dot) i++;
    if (i==dot) i--;
    if (f==-1) printf("-");
    if (A[i]=='.') printf("0");
    for (;i<=dot+m;i++){
        if (i==dot) printf(".");
        else printf("%d",ans[i]);
    }
    return 0;
}
