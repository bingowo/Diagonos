#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char s[1000000];
    int table[128];
    scanf("%s",s);
    int sign=1;
    long long int l=0,r=0;
    long long int l1=0,r1=0;
    for(int a=0;a<128;a++)table[a]=-1;
    int length=strlen(s);
    for(;r1<length;r1++){
        if((r-l)<(r1-l1-1)){
            l=l1;
            r=r1-1;
        }
        if(table[s[r1]]==-1)
            table[s[r1]]=1;
        else{
            while(s[l1]!=s[r1]){
                table[s[l1]] = -1;
                l1++;
            }
            l1++;
            sign=0;
        }
    }
    if((r-l)<(r1-l1-1)) {
        l = l1;
        r = r1 - 1;
    }
    for(long long int i=l;i<=r;i++)
        printf("%c",s[i]);
    return 0;
}

