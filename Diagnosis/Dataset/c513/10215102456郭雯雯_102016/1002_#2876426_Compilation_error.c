#include<stdio.h>
#include<stdlib.h>
int num(char* a){
    int n=strlen(a);
    char s[n];
    strcpy(s,a);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[j]==s[i]){
                n--;break;
            }
        }
    }
}
int trans(char* a){
    int r=num(a),n=strlen(a);
    
    
}