#include <stdio.h>
#include <string.h>

int main()
{
    char s[100],a[7],b[7],t[7];
    int l,i,j,k,h,m,ss,x,y;
    scanf("%s",s);
    while(strcmp(s,"END")!=0){
        l=strlen(s);
        for(i=0;i<6;i++)
            a[i]=s[i];
        a[6]=0;
        if(strcmp(a,"$GPRMC")==0){
            while(s[i]!=',')
                i++;
            i++;
            for(j=0;j<6;j++){
                b[j]=s[i];
                i++;
            }
            b[6]=0;
            i=i+5;
            if(s[i]=='A'){
                k=1;
                while(s[k]!='*')
                    k++;
                x=s[1];
                for(j=2;j<k;j++){
                    x=x^s[j];
                    if(x>65536)
                        x=x%65536;
                }
                if(s[k+1]>='0'&&s[k+1]<='9')
                    y=s[k+1]-'0';
                else
                    y=s[k+1]-'A'+10;
                y=y*16;
                if(s[k+2]>='0'&&s[k+2]<='9')
                    y=y+s[k+2]-'0';
                else
                    y=y+s[k+2]-'A'+10;
                if(x==y)
                    strcpy(t,b);
            }
        }
        scanf("%s",s);
    }
    printf("%s\n",t);
    return 0;
}
