#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d",&n);
    char alpa[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    for(int i=0;i<n;i++){
        char a[101];
        scanf("%s",a);
        char *out;
        int len;
        if(strlen(a)%3==0)len=strlen(a)/3*4;
        else len=(strlen(a)/3+1)*4;
        out=(char*)malloc((len+1)*sizeof(char));
        out[len]='\0';
        for(int i=0;i<len;i++)out[i]='=';
        for(int i=0,j=0,k=0;k<strlen(a)/3;i+=3,j+=4,k++){
            out[j]=alpa[a[i]>>2];
            out[j+1]=alpa[((a[i]&3)<<4)^(a[i+1]>>4)];
            out[j+2]=alpa[((a[i+1]&15)<<2)^(a[i+2]>>6)];
            out[j+3]=alpa[a[i+2]&63];
        }
        if(strlen(a)%3==1){
            out[len-4]=alpa[a[strlen(a)-1]>>2];
            out[len-3]=alpa[(a[strlen(a)-1]&3)<<4];
        }
        if(strlen(a)%3==2){
            out[len-4]=alpa[a[strlen(a)-2]>>2];
            out[len-3]=alpa[((a[strlen(a)-2]&3)<<4)^(a[strlen(a)-1]>>4)];
            out[len-2]=alpa[(a[strlen(a)-1]&15)<<2];
    }
    printf("case #%d:\n",i);
    printf("%s\n",out);
    }
    return 0;
}
