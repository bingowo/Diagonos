#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main()
{
    char s[50];
    while(scanf("%s",s)!=EOF){
        int xishu[4];
        int cishu[4];
        int dian[41];
        int xi=0,sig=1,len=strlen(s),n1=0,n2=0,i=5;
        while(i<len){
            if(isdigit(s[i])){
                xi=xi*10+s[i]-'0';
                i++;
            }
            if(s[i]=='x'){
                xi*=sig;
                if(xi==0) xi=sig;
                xishu[n1]=xi;
                xi=0,n1++,sig=1;
                i++;
                if(s[i]=='^'){
                    i++;
                    cishu[n2]=s[i]-'0';
                    n2++;
                    i++;
                }
                else {
                    cishu[n2]=1;
                    n2++;
                }
            }
            if(s[i]=='+'||s[i]=='-') {
                sig= s[i]=='+' ? 1:-1;
                i++;
            }
        }
        if(xi!=0) {
            xishu[n1]=xi*sig;
            n1++;
            cishu[n2]=0;
            n2++;
        }
        //for(int i=0;i<n1;i++) printf("%d %d\n",xishu[i],cishu[i]);
        for(int w=-20;w<=20;w++){
            int daan=0;
            for(int j=0;j<n1;j++){
                daan=daan+xishu[j]*pow(w,cishu[j]);
            }
            dian[w+20]=daan;
        }
        //for(int kk=0;kk<41;kk++) printf("%d ",dian[kk]);
        for(int y=0;y<41;y++){
            for(int x=0;x<41;x++){
                if(y==0&&x==20) printf("^");
                else if(y==20&&x==20&&dian[x]!=0) printf("+");
                else if(y==20&&x==40&&dian[x]!=0) printf(">");
                else if(y==20&&dian[x]!=0) printf("-");
                else if(x==20&&(dian[x]-20)*(-1)!=y) printf("|");
                else if((dian[x]-20)*(-1)==y) printf("*");
                else printf(".");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
