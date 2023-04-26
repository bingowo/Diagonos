#include <stdio.h>
#include <string.h>
int main(){
char s[50];
fgets(s,50,stdin);
int max=1,sign=1;
int l=0,r;
for(int i=l;i<strlen(s)-1;i++){
    if(s[i]!=s[i+1])
        if((i-l+2)>max) max=i-l+2;
    else{
        sign=0;
        if((i-l+1)>max) max=i-l+1;
        l=i+1;
    }
}
if(sign==1)
    max=strlen(s)-1;
printf("%d\n",max);
return 0;
}
