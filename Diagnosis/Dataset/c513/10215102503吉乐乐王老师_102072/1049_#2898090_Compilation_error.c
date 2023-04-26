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
        char ch=getchar();
        while(ch!='\n'){
            char temp[100];char *p=temp;
            while(isalpha(ch)){
                *p=ch;p++;ch=getchar();
            }
            *p='\0';
            strcpy(list[lislen],temp);
            lislen++;
            if(ch=='\n')break;
            else ch=getchar();
        }
        qsort(list,lislen,sizeof(list[0]),cmp);
        list[lislen]="-1";
        printf("case #%d:\n",cas++);
        for(int i=0;i<lislen;i++){
            if(strcmp(list[i],list[i+1])==0)continue;
            else printf("%s",list[i]);
            if(i==lislen-1)putchar('\n');
            else putchar(' ');
        }
    }
}