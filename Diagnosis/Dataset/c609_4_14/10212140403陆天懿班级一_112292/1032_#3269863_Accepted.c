#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>

typedef long long ll;
typedef unsigned long long ull;

int main(){
    char s[55];
    scanf("%s",s);
    int maxx=1,now=1;
    for(int i=1;s[i]!='\0';i++){
        if(s[i]!=s[i-1]) now++;
        else{
            if(now>maxx) maxx=now;
            now=1;
        }
    }
    if(now>maxx) maxx=now;
    printf("%d\n",maxx);
    return 0;
}

