#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    char c[1500];scanf("%s",c);
    char res[1500],resadd[1500];
    res[0]=1;resadd[0]=0;
    for(int i=1;i<1000;i++)res[i]=resadd[i]=0;
    int len=strlen(c);
    int top=0,topadd=0;
    if(len==1);
    else if(len==2){
        if(c[0]!=c[1])res[0]=4;
    }
    else{
        if(c[0]!=c[1])res[0]=res[0]*=2;
        if(c[len-2]!=c[len-1])res[0]*=2;
        for(int i=1;i<len-1;i++){
            if(c[i]!=c[i-1]&&c[i]!=c[i+1]&&c[i-1]!=c[i+1]){
                for(int m=0;m<=top;m++){
                    res[m]*=3;
                    if(res[m]>9){
                        resadd[m+1]=res[m]/10;
                        res[m]%=10;
                        if(m+1>topadd)topadd=m+1;
                    }
                }
                if(topadd>top)top=topadd;
                for(int m=0;m<=top;m++){
                    res[m]=res[m]+resadd[m];
                    if(res[m]>9){
                        res[m+1]+=res[m]/10;
                        res[m]%=10;
                        if(m+1>top)top=m+1;
                    }
                    resadd[m]=0;
                }
            }
            else if(c[i]==c[i-1]&&c[i]==c[i+1]);
            else {
                for(int m=0;m<=top;m++){
                    res[m]*=2;
                    if(res[m]>9){
                        resadd[m+1]=res[m]/10;
                        res[m]%=10;
                        if(m+1>topadd)topadd=m+1;
                    }
                }
                if(topadd>top)top=topadd;
                for(int m=0;m<=top;m++){
                    res[m]=res[m]+resadd[m];
                    if(res[m]>9){
                        res[m+1]+=res[m]/10;
                        res[m]%=10;
                        if(m+1>top)top=m+1;
                    }
                    resadd[m]=0;
                }
            }
        }
    }
    for(int i=top;i>=0;i--)
            printf("%d",res[i]);
    return 0;
}
