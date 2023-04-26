#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char s[100];
    while(scanf("%s",s)==1&&strcmp("END",s)!=0){
        getchar();
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
            int hour=0,min=0,sec=0;
            left++;
            for(int i=0;i<2;i++){
                hour=hour*10+*left-'0';
                zhi^=*left;left++;
            }
            hour+=8;
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
                printf("%02d:%02d:%02d\n",hour,min,sec);
            }
        }
    }
}
