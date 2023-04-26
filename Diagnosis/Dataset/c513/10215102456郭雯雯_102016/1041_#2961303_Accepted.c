#include<stdio.h>
#include<string.h>

int main(){
    char s[55];
    gets(s);
    int max=0,m=0,l=strlen(s);
    for(int i=0;i<l-1;i++){
        if(s[i]!=s[i+1])m++;
        else{
            if(m>max)max=m+1;
            m=0;
        }
    }
    if(m>max)max=m+1;
    if(max==0)max=1;
    printf("%d",max);
}