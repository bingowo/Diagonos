#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,i,l,j=0,k;
    char s[101],c;
    scanf("%s",&s);
    char a[strlen(s)*2+1];
    l=1;
    c=s[0];
    if(strlen(s)==1) a[0]=s[0];
    for(i=1;i<strlen(s);i++){
        if(i==strlen(s)-1){
            if(s[i]>c){
                for(k=0;k<2*l;k++){
                    a[j++]=c;
                }
            }
            else {
                for(k=0;k<l;k++){
                    a[j++]=c;
                }
            }
            a[j]=s[i];
        }
        else if(s[i]==c) l++;
        else if(s[i]>c){
            for(k=0;k<2*l;k++){
                a[j++]=c;
            }
            c=s[i];
            l=1;
        }
        else {
            for(k=0;k<l;k++){
                a[j++]=c;
            }
            c=s[i];
            l=1;
        }
    }
    printf("%s",a);
    return 0;
}
