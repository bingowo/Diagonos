#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int rhour=0,rmin=0,rsec=0;
    char s[500];
    while(scanf("%s",s)==1){
        getchar();
        if(strcmp(s,"END")==0){
            printf("%02d:%02d:%02d\n",rhour,rmin,rsec);
            break;
        }
        char *left=s+1;
        int zhi=*left;
        char temp[10];char*p=temp;
        while(*left!=','){
            *p=*left;
            p++;left++;zhi^=*left;
        }
        *p='\0';
        if(strcmp(temp,"GPRMC")!=0)continue;
        else{
            left++;
            int hour=0,min=0,sec=0;
            for(int i=0;i<2;i++){
                hour=hour*10+*left-'0';
                zhi^=*left;left++;
            }
            hour+=8;
            if(hour>=24)hour-=24;
            for(int i=0;i<2;i++){
                min=min*10+*left-'0';
                zhi^=*left;left++;
            }
            for(int i=0;i<2;i++){
                sec=sec*10+*left-'0';
                zhi^=*left;left++;
            }
            while(*left!=','){
                zhi^=*left;left++;
            }
            zhi^=*left;left++;
            if(*left=='V')continue;
            else{
                while(*left!='*'){
                    zhi^=*left;left++;
                }
            }
            left++;
            int ret;
            sscanf(left,"%x",&ret);
            zhi%=65536;
            if(zhi==ret){
                rhour=hour;rmin=min;rsec=sec;
            }
        }
    }
}
