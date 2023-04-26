#include <stdio.h>
#include <string.h>
#define LEN 1000

void stof(char s[],int f[],int delta)
{
    char *p=NULL;
    int idx=LEN-1;
    for (p=s; *p; p++);
    delta=delta>0?delta:0;
    for (int i=0; i<delta; i++) {
        f[idx--]=0;
    }
    while (1) {
        p--;
        if(*p!='.'){
            f[idx--]=*p-'0';
        }
        if (p==s ) {
            break;
        }
    }
}

void add(int f[],int a[],int b[])
{
    for (int i=LEN-1; i;i--) {
        f[i]=f[i]+a[i]+b[i];
        for (int k=i; f[k]>=10; k--) {
            f[k]%=10;
            f[k-1]+=1;
        }
    }
}

void fround(int f[],int pidx,int n)
{
    int idx,cnt=0;
    for (idx=0; f[idx]==0; idx++);
    for (; idx<LEN; idx++) {
        if(idx>=pidx){
            cnt++;
        }
        if (cnt==n&&idx!=LEN-1) {
            if (f[idx+1]>=5) {
                f[idx]+=1;
                for (int k=idx; f[k]>=10; k--) {
                    f[k]%=10;
                    f[k-1]+=1;
                }
            }
            break;
        }
    }
}

int main(void){
    char a[LEN],b[LEN];
    int n;
    scanf("%s %s %d",a,b,&n);
    int fa[LEN]={0},pa=0,fb[LEN]={0},pb;
    int f[LEN]={0};
    pa=strstr(a, ".")?strlen(a)-(strstr(a, ".")-a)-1:0;
    pb=strstr(b, ".")?strlen(b)-(strstr(b, ".")-b)-1:0;
    stof(a, fa, pb-pa),stof(b, fb, pa-pb);
    add(f, fa, fb);
    int idx,fidx=LEN-((pa>pb)?pa:pb),cnt=0;
    fround(f, fidx, n);
    for (idx=0; f[idx]==0; idx++);
    if (idx==fidx) {
        printf("0");
    }
    for (; idx<LEN&&cnt!=n; idx++) {
        if(idx>fidx){
            cnt++;
        }
        else if(idx==fidx){
            printf(".");
            cnt++;
        }
        printf("%d",f[idx]);
    }
    if (pa==0&&pb==0) {
        printf(".");
    }
    for (; cnt<n; cnt++) {
        printf("0");
    }
    return 0;
}
