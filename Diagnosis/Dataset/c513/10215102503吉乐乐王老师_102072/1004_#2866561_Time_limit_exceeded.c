#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char temp[100];
    while(scanf("%s",temp)){
        int flag=0;
        int n=strlen(temp);
        for(int i=0;i<n;i++){
            if(temp[i]=='.'){flag=1;break;}
        }
        if(flag==1){
            double n=atof(temp);
            int p=sizeof(double);
            unsigned char*e=(unsigned char*)&n;
            while(p--)printf("%02x ",*e++);
        }
        if(flag==0){
            int n=atoi(temp);
            int p=sizeof(int);
            unsigned char*e=(unsigned char*)&n;
            while(p--)printf("%02x ",*e++);
        }
    }
}