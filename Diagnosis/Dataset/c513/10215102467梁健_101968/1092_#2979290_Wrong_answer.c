#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    char c[1500];scanf("%s",c);
    static char res[1000];
    res[0]=1;
    for(int i=1;i<800;i++)res[i]=0;
    int len=strlen(c);
    int top=0;
    if(len==1);
    else if(len==2){
        if(c[0]!=c[1])res[0]=4;
    }
    else{
        if(c[0]!=c[1])res[0]=res[0]*=2;
        if(c[len-2]!=c[len-1])res[0]*=2;
        for(int i=1;i<len-1;i++){
            if(c[i]!=c[i-1]&&c[i]!=c[i+1]&&c[i-1]!=c[i+1]){
                for(int m=0;m<=top;m++)
                    res[m]*=3;
                int k=0;
                while(res[k]>9){
                    res[k+1]+=(res[k]/10);
                    res[k++]%=10;
                    if(k>top)top=k;
                }
            }
            else if(c[i]==c[i-1]&&c[i]==c[i+1]);
            else {
                for(int m=0;m<=top;m++)
                    res[m]*=2;
                int k=0;
                while(res[k]>9){
                    res[k+1]+=(res[k]/10);
                    res[k++]%=10;
                    if(k>top)top=k;
                }
            }
        }
    }
    for(int i=top;i>=0;i--)
            printf("%d",res[i]);
    return 0;
}
