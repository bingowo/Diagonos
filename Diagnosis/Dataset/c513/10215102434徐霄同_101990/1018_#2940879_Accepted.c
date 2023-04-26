#include <stdio.h>
#include <string.h>
int ss[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
char ans[40];
char wq[25][40];
void mulwq(int n)
{
    int i,j,l,a,b,c;
    char a0[40],b0[40];
    wq[0][0]='1';
    wq[0][1]=0;
    if(n>=2){
        wq[1][0]='2';
        wq[1][1]=0;
    }
    if(n>=3){
        wq[2][0]='6';
        wq[2][1]=0;
    }
    if(n>=4){
        wq[3][0]='0';
        wq[3][1]='3';
        wq[3][2]=0;
    }
    if(n>=5){
        wq[4][0]='0';
        wq[4][1]='1';
        wq[4][2]='2';
        wq[4][3]=0;
    }
    for(i=6;i<=n;i++){
        a=ss[i-2]%10;
        b=ss[i-2]/10;
        l=0;
        c=0;
        while(l<strlen(wq[i-2])){
            a0[l]=(a*(wq[i-2][l]-'0')+c)%10+'0';
            c=(a*(wq[i-2][l]-'0')+c)/10;
            l++;
        }
        a0[l]=c+'0';
        a0[l+1]='0';
        b0[0]='0';
        l=0;
        c=0;
        while(l<strlen(wq[i-2])){
            b0[l+1]=(b*(wq[i-2][l]-'0')+c)%10+'0';
            c=(b*(wq[i-2][l]-'0')+c)/10;
            l++;
        }
        b0[l+1]=c+'0';
        c=0;
        for(j=0;j<=l+1;j++){
            wq[i-1][j]=((a0[j]-'0')+(b0[j]-'0')+c)%10+'0';
            c=((a0[j]-'0')+(b0[j]-'0')+c)/10;
        }
        wq[i-1][l+2]=c+'0';
        j=l+2;
        while(wq[i-1][j]=='0'){
            wq[i-1][j]=0;
            j--;
        }
    }
}
void mul(int x,int y)
{
    int a,b,c,i,j;
    char t;
    char a0[40],b0[40],c0[40];
    a=x%10;
    b=x/10;
    i=0;
    c=0;
    while(i<strlen(wq[y])){
        a0[i]=(a*(wq[y][i]-'0')+c)%10+'0';
        c=(a*(wq[y][i]-'0')+c)/10;
        i++;
    }
    a0[i]=c+'0';
    a0[i+1]='0';
    b0[0]='0';
    i=0;
    c=0;
    while(i<strlen(wq[y])){
        b0[i+1]=(b*(wq[y][i]-'0')+c)%10+'0';
        c=(b*(wq[y][i]-'0')+c)/10;
        i++;
    }
    b0[i+1]=c+'0';
    c=0;
    for(j=0;j<=i+1;j++){
        c0[j]=((a0[j]-'0')+(b0[j]-'0')+c)%10+'0';
        c=((a0[j]-'0')+(b0[j]-'0')+c)/10;
    }
    c0[i+2]=c+'0';
    c0[i+3]=0;
    if(strlen(ans)<strlen(c0)){
        for(i=strlen(ans);i<strlen(c0);i++)
            ans[i]='0';
        ans[strlen(c0)]=0;
    }
    else{
        for(i=strlen(c0);i<strlen(ans);i++)
            c0[i]='0';
        c0[strlen(ans)]=0;
    }
    c=0;
    for(i=0;i<strlen(ans);i++){
        t=ans[i];
        ans[i]=((t-'0')+(c0[i]-'0')+c)%10+'0';
        c=((t-'0')+(c0[i]-'0')+c)/10;
    }
    ans[i]=c+'0';
    ans[i+1]=0;
    while(ans[i]=='0'){
        ans[i]=0;
        i--;
    }
}
int main()
{
    char s[71];
    int a[25];
    int i,l,n;
    scanf("%s",s);
    l=strlen(s);
    n=0;
    memset(a,0,sizeof(a));
    memset(ans,0,sizeof(ans));
    while(i<=l){
        if(i==l||s[i]==',')
            n++;
        else
            a[n]=a[n]*10+s[i]-'0';
        i++;
    }
    if(n==1&&a[0]==0)
        printf("0\n");
    else{
        mulwq(n);
        for(i=n-1;i>=0;i--)
            mul(a[i],n-1-i);
        for(i=strlen(ans)-1;i>=0;i--)
            printf("%c",ans[i]);
        printf("\n");
    }
    return 0;
}
