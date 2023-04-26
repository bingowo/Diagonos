#include<stdio.h>
#include<string.h>

int main(){
    int t,a=0;
    scanf("%d",&t);
    char s[110];
    gets(s);
    while(a<t){
        gets(s);
        int l=strlen(s),n=0;
        char w[50];
        for(int i=0,j=0;i<l;i++){
            if(s[i]!=' '){
                if(s[i]>='A'&&s[i]<='Z')w[j]=s[i]-'A'+'a';
                else w[j]=s[i];
                j++;
            }
            else {
                if((strcmp(w,"this")!=0)&&(strcmp(w,"a")!=0)&&(strcmp(w,"an")!=0)&&(strcmp(w,"of")!=0)&&(strcmp(w,"for")!=0)&&(strcmp(w,"and")!=0)){
                    n++;
                }
                j=0;memset(w,0,50);
            }
            if(i==l-i){
                if((strcmp(w,"this")!=0)&&(strcmp(w,"a")!=0)&&(strcmp(w,"an")!=0)&&(strcmp(w,"of")!=0)&&(strcmp(w,"for")!=0)&&(strcmp(w,"and")!=0)){
                    n++;
                }
            }
        }
        printf("case #%d:\n%d\n",a,n);
        a++;
    }
}