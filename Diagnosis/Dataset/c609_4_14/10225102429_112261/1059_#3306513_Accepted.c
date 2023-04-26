#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    char s[101];
}num;
int cmp(const void* a, const void* b){
    char *sa = (*(num*)a).s, *sb = (*(num*)b).s;
    int i = 0,j = 0,signa = 1,signb = 1;
    if(sa[i]=='-'||sa[i]=='+'){
        if(sa[i]=='-') signa = -1;
        i++;
    }
    if(sb[j]=='-'||sb[j]=='+'){
        if(sb[j]=='-') signb = -1;
        j++;
    }
    if(signa!=signb){
        return signa-signb;
    }
    else{
        int lenInta = i+1,lenIntb = j+1,lena = strlen(sa),lenb = strlen(sb);
        if(signa>0){
            while(lenInta<lena&&sa[lenInta]!='.') lenInta++;
            while(lenIntb<lenb&&sb[lenIntb]!='.') lenIntb++;
//            lenInta--,lenIntb--;
            if(lenInta-i!=lenIntb-j){
                return lenInta-lenIntb-i+j;
            }
            else{
                while(i<lenInta&&sa[i]==sb[j]){
                    i++;
                    j++;
                }
                if(i==lenInta){
                    return strcmp(sa+i,sb+j);
                }
                return sa[i]-sb[j];
            }
        }
        else {
            while(lenInta<lena&&sa[lenInta]!='.') lenInta++;
            while(lenIntb<lenb&&sb[lenIntb]!='.') lenIntb++;
//            lenInta-=i,lenIntb-=j;
            if(lenInta-i!=lenIntb-j){
                return lenIntb-lenInta-j+i;
            }
            else{
                while(i<lenInta&&sa[i]==sb[j]){
                    i++;
                    j++;
                }
                if(i==lenInta){
                    return -strcmp(sa+i,sb+j);
                }
                return -sa[i]+sb[j];
            }
        }
    }
}
int main(){
    int t; scanf("%d",&t);
    num a[t];
    for(int i = 0; i<t; i++){
        memset(a[i].s,0,sizeof(a[i].s));
    }
    for(int i = 0; i<t; i++){
        scanf("%s",a[i].s);
    }
    qsort(a,t,sizeof(a[0]),cmp);
    for(int i = 0; i<t; i++) printf("%s\n",a[i].s);
    return 0;
}