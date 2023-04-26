#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
     while(a--){
        int b,c;
        scanf("%d %d",&b,&c);
        int n=b/c+1;
        char s[n];
        int i=0;
        int flag=0;
        if(b<0){
            flag=1;
            b=-b;
        }
        while(b/c){
            if (flag){printf("-");}
            if(b%c<10){
            s[i]='0'+b%c;}
            else 
            {s[i]='A'+b%c-10;}    
            b/=c;
            i++;
        
        }
        if(b<10){
            s[i]='0'+b%c;
        }
        else s[i]='A'+b%c-10;
        for(int j=n;j>=1;j--){
            printf("%c",s[j]);
        }
        printf("%c\n",s[0]);
     }
     return 0;
}