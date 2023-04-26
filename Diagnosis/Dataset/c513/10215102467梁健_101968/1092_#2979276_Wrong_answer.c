#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    char c[1500];scanf("%s",c);
    char res[800];
    res[0]='1';
    for(int i=1;i<800;i++)res[i]=0;
    int len=strlen(c);
    if(len==1);
    else if(len==2)
        if(c[0]!=c[1])res[0]='4';
    else{
        if(c[0]!=c[1])res[0]=(res[0]-48)*2+48;
        if(c[len-2]!=c[len-1])res[0]=(res[0]-48)*2+48;
        for(int i=1;i<len-1;i++){
            if(c[i]!=c[i-1]&&c[i]!=c[i+1]&&c[i-1]!=c[i+1]){
                for(int m=0;m<strlen(res);m++)
                    res[m]=(res[m]-48)*3+48;
                int k=0;
                while(res[k]>'9'){
                    res[k]-=10;
                    if(isdigit(res[k+1]))res[k+1]++;
                    else res[k+1]='1';
                    k++;
                }
            }
            else if(c[i]==c[i-1]&&c[i]==c[i+1]);
            else {
                for(int m=0;m<strlen(res);m++)
                    res[m]=(res[m]-48)*2+48;
                int k=0;
                while(res[k]>'9'){
                    res[k]-=10;
                    if(isdigit(res[k+1]))res[k+1]++;
                    else res[k+1]='1';
                    k++;
                }
            }
        }
    }
    for(int i=strlen(res)-1;i>=0;i--)
            printf("%c",res[i]);
    return 0;
}
