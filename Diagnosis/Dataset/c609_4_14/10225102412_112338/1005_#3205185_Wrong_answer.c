#include<stdio.h><string.h><math.h>
int main(){
    int T;char a[100][10000];int i;
    for (i=0;i<T;i++){
        scanf("%s\n",&a[i]);
    }
    for (i=0;i<T;i++){
        printf("case #%d:\n%d\n",i,trans(a[i]));
    }
    return 0;
}

int trans(char s[10000])
{
    int n=0;
    int len=strlen(s);
    int i;
    for (i=0;i<len-1;i++){
        if (s[i]=='-'){
            n -= pow(3,len-i-2);
        }
        if (s[i]=='0'){
            n += 0;
        }
        if (s[i]=='1'){
            n += pow(3,len-i-2);
        }
    }
    return n;
}