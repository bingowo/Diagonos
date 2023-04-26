#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[1000000];

int main(){
    int table[128];
    scanf("%s",s);
    long long int l=0,r=0;
    long long int l1=0,r1=0;
    for(int a=0;a<128;a++)table[a]=-1;
    for(;r1<strlen(s);r1++){
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