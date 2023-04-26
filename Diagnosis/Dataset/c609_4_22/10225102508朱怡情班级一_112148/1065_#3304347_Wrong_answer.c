#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        printf("case #%d:\n",i);
        char sign[109];
        char c[11];
        int pos=0;
        int flag=0;
        double temp;
        while(scanf("%s",c)){
            if(c[0]=='+'||c[0]=='-'||c[0]=='*'||c[0]=='/')sign[pos++]=c[0];
            else{
                double n=atof(c);
                if(flag){
                    pos--;
                    if(sign[pos]=='+')temp+=n;
                    else if(sign[pos]=='-')temp-=n;
                    else if(sign[pos]=='*')temp*=n;
                    else temp/=n;
                }
                else{
                    flag=1;
                    temp=n;
                }
            }
            if(getchar()=='\n')break;
        }
        printf("%lf\n",temp);
    }
    return 0;
}
