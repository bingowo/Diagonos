#include<stdio.h>
#include<string.h>

void chu(char s[]){
    int slen = strlen(s), carry=0;
    int temp[350]={0};
    for (int i=0; i<slen; i++){
        temp[i] = (s[i]-'0'+carry*10)/2;
        carry = (s[i]-'0'+carry*10)%2;
    }
    for (int i=0; i<slen; i++) s[i]=temp[i]+'0';
    while(s[slen]=='0') {s[slen]='\0'; slen--;}
    return;
}
int notZero(char s[]){
    int slen=strlen(s), flag=0;
    for (int i=0; i<slen; i++){
        if (s[i]!='0'){flag=1; break;}
    }
    return flag;
}
void toTwo(char ten[], char two[]){
    int index=0;
    while (notZero(ten)){
        two[index++]=(ten[strlen(ten)-1]-'0')%2+'0';//ten%2
        chu(ten);//ten/=2
    }
    return;
}
void process(char s[]){
    int slen=strlen(s);
    while (s[slen]=='0') slen--;
    int begin=0;
    while (s[begin]=='0') begin++;
    for (int i=begin, j=0; i<=slen; i++,j++) s[j]=s[i];
    s[slen+1]='\0';
    return;
}
void multi(int res[]){
    int index=99;
    while(res[index]==0) index--;
    for (int i=index; i>=0; i--){
        res[i]*=2;
        if (res[i]>=10){
            res[i+1] += res[i]/10;
            res[i] %= 10;
        }
    }
    return;
}
void toTen(char two[], int res[]){
    int index=0, len2=strlen(two);
    for (int i=0; i<len2; i++){
        multi(res);//res*=2;
        res[index]+=two[i]-'0';
        if (res[index]>=10) {
            res[index+1] += res[index]/10;
            res[index] %= 10;
            index++;
        }
    }
    return;
}
int main(){
    int T;
    scanf("%d ",&T);
    for (int t=0; t<T; t++){
        char ten[100]={0}, two[350]={0};
        gets(ten);
        toTwo(ten, two);
        process(two);
        int res[100]={0};
        toTen(two, res);
        int index=99;
        while(res[index]==0) index--;
        if (index==-1) printf("0");
        else for (int i=index; i>=0; i--) printf("%d", res[i]);
        printf("\n");
    }
    return 0;
}