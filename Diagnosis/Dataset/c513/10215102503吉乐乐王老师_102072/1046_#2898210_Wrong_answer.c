#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int t;scanf("%d",&t);getchar();int cas=0;
    while(t--){
        int cnt=0;
        char tem[20];
        while(scanf("%s",tem)){
            if(strcmp(tem,"the")!=0&&strcmp(tem,"a")!=0&&strcat(tem,"an")!=0&&strcmp(tem,"of")!=0&&strcmp(tem,"for")!=0&&strcmp(tem,"and")!=0)cnt++;
            if(getchar()=='\n')break;
        }
        printf("case #%d:\n%d\n",cas++,cnt);
    }
}