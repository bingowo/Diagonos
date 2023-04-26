#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct {
    char b[20];
}string;
int cmp(const void *p1,const void *p2){
    char* a = (char *)p1;
    char* b = (char *)p2;
    return strcmp(a,b);
}
int cmp1(const void *p1,const void *p2){
    string * a= (string *)p1;
    string * b= (string *)p2;
    return strcmp(a,b);
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char s[20];
        char a[20];
        scanf("%s",s);
        int len = strlen(s);
        qsort(s,len,sizeof(char),cmp);
        a[0] = s[0];
        int p=1;
        for(int j=1;j<len;j++){
            if(s[j] != s[j-1]){
                a[p++] = s[j];
            }
        }
        a[p] = \0;
        len = strlen(a);
        string str[(int)pow(2,len)-1];
        for(int q=1;q<pow(2,len);q++){
            int m = 0;
            int n = 0;
            int k = q;
            while(k!=0){
                if(k%2==1){
                    str[q-1].b[m++] =a[n];
                }
                n++;
                k = k/2;
            }
            str[q-1].b[m] = 0;
        }
        qsort(str,(int)(pow(2,len)-1),sizeof(string),cmp1);
        printf("case #%d:\n",i);
        for(int h =0;h<(int)pow(2,len)-1;h++){
            printf("%s\n",str[h].b);
        }
    }
    return 0;
}