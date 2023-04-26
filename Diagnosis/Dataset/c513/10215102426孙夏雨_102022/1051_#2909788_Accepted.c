#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char s[101];
        scanf("%s",s);
        int len=strlen(s);
        int length=len*8,buwei=0;
        if((len*8)%6!=0) buwei=(((len*8)/6)+1)*6-len*8;
        length+=buwei;
        int* p=(int* )malloc(length*sizeof(int));
        int i=0,j=len-1;
        for(;i<buwei;i++) *(p+i)=0;
        for(;j>=0;j--){
            char c1=s[j];
            int c=(int)c1;
            for(int nn=0;nn<8;nn++){
                int ww=c&1;
                *(p+i)=ww;
                i++;
                c=c>>1;
            }
        }
        char* ans=(char* )malloc((length/6)*sizeof(char));
        int num=length/6;
        for(int k=0;k<num;k++){
            int x=0;
            for(int kk=0;kk<6;kk++) x+=(*(p+kk+k*6))*pow(2,kk);
            if(x<=25) *(ans+k)=x+'A';
            else if(x<=51) *(ans+k)=x-26+'a';
            else if(x<=61) *(ans+k)=x-52+'0';
            else if(x==62) *(ans+k)='+';
            else *(ans+k)='/';
        }
        printf("case #%d:\n",t);
        for(int o=0;o<num;o++) printf("%c",*(ans+num-1-o));
        int a=(4-(num%4))==4?0:(4-(num%4));
        for(int u=0;u<a;u++) printf("=");
        printf("\n");
        free(p);
        free(ans);
    }
    return 0;
}
