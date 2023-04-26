#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Path(int p[20],int index,int len,char s[20]){
    if(index==len){
        // printf("\n");
        for(int i=1;i<20;i++){
            s[i]='\0';
        }
        return;
    }
    else{
        char ss[2];
        ss[0]=p[index];
        ss[2]='\0';
        strcat(s,ss);
        printf("%s\n",s);
        for(int i=index;i<len;i++){
            Path(p,i+1,len,s);
//            printf("\n __%s__ \n",s);
//            strcat(s,ss);
//            printf("\n __%s__ \n",s);
        }
    }
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char p0[20];
        scanf("%s",p0);
        int p1[255]={0};
        for(int i=0;i<strlen(p0);i++){
            p1[p0[i]]=p0[i];
        }
        int p2[20];
        int len=0;
        for(int i=0;i<254;i++){
            if(p1[i]!=0){
                p2[len]=p1[i];
                len++;
            }
        }
        printf("case #%d:\n",t);
        char s[20]={'\0'};
//        Path(p2,0,len,s);
//        printf("\n\n");
        for(int i=0;i<len;i++){
            Path(p2,i,len,s);
            for(int i=0;i<20;i++){
                s[i]='\0';
            }
        }
    }


    return 0;
}
