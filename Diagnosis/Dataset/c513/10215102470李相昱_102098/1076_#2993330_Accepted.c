#include <stdio.h>
#include <string.h>
int main() {
    int T;
    scanf("%d",&T);
    while (T--){
        char s[101];
        scanf("%s",s);
        int len=strlen(s);
        int a[101]={0};
        int sign=0,j=0;
        for(int i=0;i<len;i++){
            if(s[i]=='{'){
                if(a[j-1]!=3&&j-1>=0){
                    sign=1;
                    break;
                }
                a[j]=1;
                j++;
            }
            else if(s[i]=='['){
                if(a[j-1]!=1&&j-1>=0){
                    sign=1;
                    break;
                }
                a[j]=2;
                j++;
            }
            else if(s[i]=='('){
                if(a[j-1]!=2&&j-1>=0){
                    sign=1;
                    break;
                }
                a[j]=3;
                j++;
            }
            else if(s[i]=='}'){
                if(a[j-1]!=1||j-1<0){
                    sign=1;
                    break;
                }
                j--;
            }
            else if(s[i]==']'){
                if(a[j-1]!=2||j-1<0){
                    sign=1;
                    break;
                }
                j--;
            }
            else if(s[i]==')'){
                if(a[j-1]!=3||j-1<0){
                    sign=1;
                    break;
                }
                j--;
            }
        }
        if(sign||j!=0){
            printf("No\n");
        }else{
            printf("Yes\n");
        }
    }
    return 0;
}
