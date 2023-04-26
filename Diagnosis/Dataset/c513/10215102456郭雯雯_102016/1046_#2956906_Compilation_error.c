#include<stdio.h>
#include<string.h>

int main(){
    int t,a=0;
    scanf("%d",&t);
    char s[110];
    while(a<t){
        getline(s);
        int l=strlen(s),n=0;
        char w[25];
        for(int i=0,j=0;i<l;i++){
            if(s[i]!=' '){w[j]=s[i];j++;}
            else{
                if((strcmp(w,"this")!=0)&&(strcmp(w,"a")!=0)&&(strcmp(w,"an")!=0)&&(strcmp(w,"of")!=0)&&(strcmp(w,"for")!=0)&&(strcmp(w,"and")!=0)){
                    n++;
                }
                j=0;
            }
        }
        prfintf("case #%d:\n%d\n",a,n);
    }
}