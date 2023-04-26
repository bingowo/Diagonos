#include<stdio.h>
#include<string.h>

void minu(int a[], int b[]){
    int maxlen = a[0]>b[0]?a[0]:b[0];
    for (int i=1; i<=maxlen; i++){
        if (a[i]<b[i]){
            a[i]+=10;
            a[i+1]--;
        }
        a[i]-=b[i];
    }
    return;
}

int main(){
    while(1){
        int a[501]={0}, b[501]={0};
        char c[1005]={0};
        if (gets(c)==NULL) break;
        char *p = strstr(c, " ");
        int pos = p-c, clen = strlen(c);
        for (int i=pos-1, j=1; i>=0; i--, j++) a[j]=c[i]-'0';
        a[0]=pos;
        for (int i=clen-1, j=1; i>=pos+1; i--, j++) b[j]=c[i]-'0';
        b[0]=clen-pos-1;
        int flag=1;
        if (pos < clen-pos+1) {flag=-1;}
        else if (pos==clen-pos+1){
            for (int i=pos-1; i>0; i--){
                if (a[i]<b[i]) {flag=-1;break;}
            }
        }

        int maxlen = a[0]>b[0]?a[0]:b[0];
        int index=maxlen;
        if (flag==-1) {
            printf("-");
            minu(b, a);
            while (index>=1 && b[index]==0) index--;
            if (index<1) printf("0");
            else for (int i=index; i>=1; i--) printf("%d", b[i]);
            printf("\n");
        }
        else {
            minu(a, b);
            while (index>=1 && a[index]==0) index--;
            if (index<1) printf("0");
            else for (int i=index; i>=1; i--) printf("%d", a[i]);
            printf("\n");
        }
       

    }
    return 0;
}