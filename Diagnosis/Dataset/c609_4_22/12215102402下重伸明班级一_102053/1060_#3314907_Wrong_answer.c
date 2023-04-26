#include<stdio.h>
#include<string.h>
int main(){
    char ming[101];
    scanf("%s",&ming);
    int l=strlen(ming)-1;
    for(int i=0;i<l;i++){
        int x=ming[i]-'A';
        int y=ming[i+1]-'A';
        if(x>y){
            printf("%c",ming[i]);
        }
        if(x<y){
            printf("%c",ming[i]);
            printf("%c",ming[i]);
        }
        if(x==y){
            int z;
            for(int j=2;i+j<l+1;j++){
                z=ming[i+j]-'A';
                if(z!=x){
                    break;
                }
            }
            if(x>z){
                printf("%c",ming[i]);
            }
            if(x<z){
                printf("%c",ming[i]);
                printf("%c",ming[i]);
            }
        }

    }
    printf("%c",ming[l]);
}