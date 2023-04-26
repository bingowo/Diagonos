#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compar(char a[],char b[]){
    if(strlen(a)!=strlen(b)){
        return strlen(a)>strlen(b)?1:-1;
    }else{
        for(int i=0;i<strlen(a);i++){
            if(a[i]!=b[i])return a[i]>b[i]?1:-1;
        }
        return 0;
    }
}

void sub(char a[],char b[],int res[]){
    int carry=0,temp=0,p=501;
    char p1,p2;
    for(int i=(int)strlen(a)-1,j=(int)strlen(b)-1;i>=0||j>=0||carry;i--,j--){
        p1=i<0?'0':a[i];
        p2=j<0?'0':b[j];
        temp=(p1-'0')-(p2-'0')+carry;
        if(temp<0){
            temp+=10;
            carry=-1;
        }else carry=0;
        res[p--]=temp;
    }
    
}


int main(){
    char A[501],B[501];
    while(scanf("%s %s",A,B)!=EOF){
        if(compar(A,B)){
            int res[502]={0};
            if(compar(A, B)==-1){
                sub(B,A,res);
                printf("-");
            }else{
                sub(A,B,res);
            }
            int i=0;
            while(!res[i])i++;
            for(;i<502;i++)printf("%d",res[i]);
        }else{
            printf("0");
        }
        printf("\n");
    }
    return 0;
}

