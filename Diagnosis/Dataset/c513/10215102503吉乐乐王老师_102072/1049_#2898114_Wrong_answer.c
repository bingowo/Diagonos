#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int cmp(const void *a,const void *b){
    return strcmp((char*)a,(char*)b);
}
int main(){
    int t;scanf("%d",&t);getchar();int cas=0;
    while(t--){
        char list[100][100];int lislen=0;
        while(1){
            char temp[100];
            scanf("%s",temp);
            for(int i=0;i<strlen(temp);i++){
                if(!isalpha(temp[i])){
                    temp[i]='\0';
                    break;
                }
            }
            strcpy(list[lislen],temp);
            lislen++;
            if(getchar()=='\n')break;
        }
        qsort(list,lislen,sizeof(list[0]),cmp);
        strcpy(list[lislen],"-1");
        printf("case #%d:\n",cas++);
        for(int i=0;i<lislen;i++){
            if(strcmp(list[i],list[i+1])==0)continue;
            else printf("%s ",list[i]);
        }
        printf("\n");
    }
}