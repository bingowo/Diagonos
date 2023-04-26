#include <stdio.h>
#include <string.h>

int main()
{
    char base64[65]={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};
    char s[101];
    int t,i,j,k,l,a,b,x;
    int x0[4];
    scanf("%d",&t);
    getchar();
    for(i=0;i<t;i++){
        gets(s);
        l=strlen(s);
        a=l/3;
        b=l%3;
        printf("case #%d:\n",i);
        for(j=0;j<a;j++){
            x=(s[j*3]<<16)+(s[j*3+1]<<8)+s[j*3+2];
            for(k=3;k>=0;k--){
                x0[k]=x-((x>>6)<<6);
                x=x>>6;
            }
            for(k=0;k<4;k++)
                printf("%c",base64[x0[k]]);
        }
        if(b==1){
            x=s[l-1]<<4;
            x0[0]=x>>6;
            x0[1]=x-(x0[0]<<6);
            printf("%c%c==",base64[x0[0]],base64[x0[1]]);
        }
        else if(b==2){
            x=((s[l-2]<<8)+s[l-1])<<2;
            x0[0]=x>>12;
            x0[1]=(x-(x0[0]<<12))>>6;
            x0[2]=x-((x>>6)<<6);
            printf("%c%c%c=",base64[x0[0]],base64[x0[1]],base64[x0[2]]);
        }
        printf("\n");
    }
    return 0;
}
