#include<stdio.h>
#include<string.h>

    char a[505]={0}, b[505]={0}, ax[505]={0},ay[505]={0},bx[505]={0},by[505]={0};
    int resx[505]={0}, resy[505]={0};

int carry=0, n=0;

void round(int res[]){
    int len=500;
    while(len>=n&&res[len]==0) len--;
    if (len>=n && res[n]>=5) res[n-1]++;
    if (len>=n-1){
        for (int i=n-1; i>=1; i--) if (res[i]>=10) {res[i-1]++;res[i]-=10;}
        if (res[0]>=10) {carry++; res[0]-=10;}
    }
    else {
        for (int i=len+1; i<n; i++) res[i]= 0;
    }
    return;
}
int main(){
    scanf("%s", a);
    scanf("%s", b);
    scanf("%d", &n);
    int pos = strstr(a, ".")-a;
    int lena=strlen(a), lenb=strlen(b);
    if (pos<0) for (int i=0; i<lena; i++) ax[i]=a[lena-1-i];
    else {
        //倒置ax
        for (int i=pos-1, j=0; i>=0; i--, j++) ax[j]=a[i];
        //正置ay
        for (int i=pos+1, j=0; i<=lena-1; i++, j++) ay[j]=a[i];
    }
    pos = strstr(b, ".")-b;
    if (pos<0) for (int i=0; i<lenb; i++) bx[i]=b[lenb-1-i];
    else{
        //倒置bx
        for (int i=pos-1, j=0; i>=0; i--, j++) bx[j]=b[i];
        //正置by
        for (int i=pos+1, j=0; i<=lenb-1; i++, j++) by[j]=b[i];
    }
    int lenay=strlen(ay), lenby=strlen(by);
    int maxlen_s=lenay>lenby?lenay:lenby;
    for (int i=lenay; i<maxlen_s||i<n; i++) ay[i]='0';
    for (int i=lenby; i<maxlen_s||i<n; i++) by[i]='0';
    int lenax=strlen(ax), lenbx=strlen(bx);
    int maxlen_q=lenax>lenbx?lenax:lenbx;
    for (int i=lenax; i<maxlen_q||i<n; i++) ax[i]='0';
    for (int i=lenbx; i<maxlen_q||i<n; i++) bx[i]='0';

    for (int i=0; i<maxlen_s||i<n; i++) resy[i]+=(ay[i]-'0')+(by[i]-'0');
    for (int i=maxlen_s-1; i>=1; i--){
        if (resy[i]>=10){resy[i-1]+=resy[i]/10;resy[i]%=10;}
    }
    if (resy[0]>=10) {
        carry++;
        resy[0]%=10;
    }
    round(resy);
    ax[0]+=carry;
    if (maxlen_q==0&&carry!=0) maxlen_q=1;
    for (int i=0; i<maxlen_q; i++){
        resx[i]+=(ax[i]-'0')+(bx[i]-'0');
        if (resx[i]>=10){
            resx[i+1]+=resx[i]/10;
            resx[i]%=10;
        }
    }
    int index=500;
    while(index>=0&&resx[index]==0) index--;
    if (index<0) printf("0");
    else for (int i=index; i>=0; i--) printf("%d", resx[i]);
    printf(".");
    for (int i=0; i<=n-1; i++) printf("%d", resy[i]);
    printf("\n");
    return 0;
}
