#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
int cmp(const void*a,const void*b){
    char *r;
    char *t;
    r=*(char**)a;
    t=*(char**)b;
    int c,d,m,n;
    c=strlen(r);
    d=strlen(t);
    int f=0,g=0,num1=0,num2=0;
    for(m=0;m<c;m++){
        if(isdigit(r[m])){
            f=1;
            num1=num1*10+r[m]-'0';
        }

    }
     for(n=0;n<d;n++){
         if(isdigit(t[n])){
            g=1;
            num2=num2*10+t[n]-'0';
        }

    }
    if(f!=g){
        return f-g;
       }
    else{
        if(f==1&&g==1){
            return num1-num2;
        }
        else{
            if(r==1&&t==1){
                return r[0]-t[0];
            }
            else{
                for(int k=1;k<c;k++){
                    if(r[k-1]==t[k-1]&&r[k]=='\0'&&t[k]!='\0'){
                        return -1;
                        break;
                    }
                    if(r[k-1]==t[k-1]&&t[k]=='\0'&&r[k]!='\0'){
                        return 1;
                        break;
                    }    
                    if(r[k]!=t[k]){
                        return r[k]-t[k];
                        break;
                    }
                }
            }
        }
            
    }

}





int main()
{
    char *s[100];
    int i=0;
    s[0]=(char*)malloc(sizeof(char));
    while(scanf("%s",s[i])!=EOF){
        i++;
        s[i]=(char*)malloc(sizeof(char));
    }
    qsort(s,i,sizeof(s[0]),cmp);
    for(int c=0;c<i;c++){
        printf("%s ",s[c]);
    }
    return 0;
}
