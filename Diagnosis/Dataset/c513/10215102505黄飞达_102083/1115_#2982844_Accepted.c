#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int lowwer(char num[]){
    int res=1;
    int slen = strlen(num);
    for (int i=0; i<slen; i++){
        if (num[i]<num[i+1]) {res=0;break;}
    }
    return res;
}
int cmp(const void*a, const void*b){
    return *(char*)a>*(char*)b?1:-1;
}
void change(char num[]){
    int slen=strlen(num), bigger=num[1]-'0', pos=1;
    for (int i=1; i<slen; i++){
        if (num[i]>num[0] &&num[i]-'0'<=bigger) {bigger=num[i]-'0'; pos=i;}
    }
    int temp=num[0]-'0';
    num[0]=bigger+'0';
    num[pos]=temp+'0';
    qsort(num+1, slen-1, 1, cmp);
    return;
}
int main(){
    int T;
    scanf("%d ", &T);
    for (int t=0; t<T; t++){
        printf("case #%d:\n", t);
        char num[25]={};
        gets(num);
        int slen = strlen(num), flag=0;
        for (int i=slen-2; i>=0; i--){
            if (lowwer(num+i)) continue;
            change(num+i);
            flag=1;
            break;
        }
        if (flag==0){
            qsort(num, slen, 1, cmp);
            if (num[0]=='0'){
                int bigger=10086, pos=0;
                for (int i=1; i<slen; i++){
                    if (num[i]!='0' && num[i]-'0'<bigger) {bigger=num[i]-'0';pos=i;}
                }
                num[0]=bigger+'0';
                num[pos]='0';
            }
            for (int i=slen; i>=2; i--) num[i]=num[i-1];
            num[1]='0';
        }
        printf("%s\n", num);
    }
    return 0;
}

