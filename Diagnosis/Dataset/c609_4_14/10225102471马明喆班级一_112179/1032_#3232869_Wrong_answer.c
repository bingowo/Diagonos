#include <stdio.h>
#include <string.h>
int main(){
char s[50];
fgets(s,51,stdin);
int max=1,sign=1;
int l=0,i;
for(i=l;i<strlen(s);i++){
    if(s[i]!=s[i+1])
        continue;
    else{
        sign=0;
        if((i-l+1)>max) max=i-l+1;
        l=i+1;
    }
}
if((i-l+1)>max) max=i-l+1;
if(sign==1)
    max=strlen(s);
printf("%d\n",max);
return 0;
}
