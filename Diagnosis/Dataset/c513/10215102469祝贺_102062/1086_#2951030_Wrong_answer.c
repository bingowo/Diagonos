#include<stdio.h>
#include<string.h>
typedef struct{
    int bin[505];
    int nim[505];
    int bp,np;
}bdou;
void init (char *s,bdou* n){
    int p=strchr(s,'.')==NULL?-1:strchr(s,'.')-s;
    if(p==-1){
        n->np=1;n->nim[0]=0;
        for(int i=strlen(s)-1;i>=0;i--)
            n->bin[n->bp++]=s[i]-'0';
    }
    else if(p==0){
        n->bp=1;n->bin[0]=0;
        for(int i=1;i<strlen(s);i++){
            n->nim[n->np++]=s[i]-'0';
        }
    }
    else if(p==strlen(s)-1){
        n->np=1;n->nim[0]=0;
        for(int i=strlen(s)-2;i>=0;i--)
            n->bin[n->bp++]=s[i]-'0';
    }
    else{
        for(int i=p-1;i>=0;i--)
            n->bin[n->bp++]=s[i]-'0';
        for(int i=p+1;i<strlen(s);i++){
            n->nim[n->np++]=s[i]-'0';
        }
    }
}
void sub(bdou* ret,bdou* n1,bdou* n2,int n){
    ret->np=n1->np>n2->np?n1->np:n2->np;
    ret->bp=n1->bp>n2->bp?n1->bp:n2->bp;
    for(int i=0;i<ret->np;i++){
        ret->nim[i]=n1->nim[i]-n2->nim[i];
    }
    for(int i=0;i<ret->bp;i++){
        ret->bin[i]=n1->bin[i]-n2->bin[i];
    }

    for(int i=ret->np-1;i>0;i--){
        while(ret->nim[i]<0){
            ret->nim[i-1]--;
            ret->nim[i]+=10;
        }
    }
    while(ret->nim[0]<0){
        ret->bin[0]--;
        ret->nim[0]+=10;
    }
    if(ret->np>n && ret->nim[n]>=5){
        ret->nim[n-1]++;
        for(int i=n-1;i>0;i--){
            if(ret->nim[i]>=10){
                ret->nim[i-1]+=ret->nim[i]/10;
                ret->nim[i]=ret->nim[i]%10;
            }
        }
        if(ret->nim[0]>=10){
            ret->bin[0]+=ret->nim[0]/10;
            ret->nim[0]%=10;
        }
    }
    ret->np=n;
    for(int i=0;i<ret->bp || (ret->bin[i]<0 || ret->bin[i]>9);i++){
        while(ret->bin[i]<0 || ret->bin[i]>9){
            if(ret->bin[i]<0){
                ret->bin[i+1]--;
                ret->bin[i]+=10;
            }
            else{
                ret->bin[i+1]+=ret->bin[i]/10;;
                ret->bin[i]%=10;
            }
        }
    }
    ret->bp+=5;
    while(ret->bp>1 && ret->bin[ret->bp-1]==0)ret->bp--;
}

int main(){
    char s1[505],s2[505];int n;
    bdou n1={{0},{0},0,0},n2={{0},{0},0,0};
    bdou ret={{0},{0},0,0};
    scanf("%s%s%d",s1,s2,&n);
    init(s1,&n1);init(s2,&n2);
    int sign=1;
    if(strcmp(s1,s2)>=0){
        sub(&ret,&n1,&n2,n);
    }
    else {
        sign=-1;
        sub(&ret,&n2,&n1,n);
    }
    if(sign==-1)printf("-");
    for(int i=ret.bp-1;i>=0;i--)printf("%d",ret.bin[i]);
    printf(".");
    for(int i=0;i<ret.np;i++)printf("%d",ret.nim[i]);
    return 0;
}
