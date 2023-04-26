#include<stdio.h>
#include<string.h>
int a[501], b[501];
char c[1005];
int res[501];

void minu(int a[], int b[]){
    int maxlen = a[0]>b[0]?a[0]:b[0];
    for (int i=1; i<maxlen; i++){
        if (a[i]<b[i]){
            a[i]+=10;
            a[i+1]--;
        }
        a[i]-=b[i];
    }
    return;
}

int main(){
    while(gets(c)!=NULL){
        char *p = strstr(c, " ");
        int pos = p-c, clen = strlen(c);
        for (int i=pos-1, j=1; i>=0; i--, j++) a[j]=c[i]-'0';
        a[0]=pos;
        for (int i=clen-1, j=1; i>=pos+1; i--, j++) b[j]=c[i-pos-1]-'0';
        b[0]=clen-pos-1;
        int flag=1;
        if (pos < clen-pos-1) {flag=-1;minu(b,a);}
        else if (pos==clen-pos-1){
            for (int i=0; i<pos; i++){
                if (a[i]<b[i]) {flag=-1;minu(b,a);break;}
            }
        }
        if (flag==1) minu(a, b);
        else if (flag==-1) printf("-");
        int maxlen = a[0]>b[0]?a[0]:b[0];
        int index=1;
        while(index<=maxlen && a[index]==0) index++;
        if (index>maxlen) printf("0");
        else for (int i=index; i<=maxlen; i++) printf("%d", a[i]);
        printf("\n");
    }
    return 0;
}