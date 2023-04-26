#include <stdio.h>
typedef struct{
    char a[20];
}str;
int main(){
    int T;
    scanf("%d\n",&T);
    for(int t=0;t<T;t++){
        str data[501];
        char s[501],stemp[501];
        int index=0;
        gets(s);
        char *p=s;
        int j=0;
        while(*p){
            if(isalpha(*p)){
                stemp[index++]=*p;
                p++;
            }
            else{
                int i=0;
                for(;i<index;i++){
                     data[j].a[i]=stemp[i];
                }
                data.a[i]='\0';
                index=0;
                j++;
            }
        }
        
        
        
    }
}