#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cmp(const void* p3,const void* p4)
{
    char* p1=*((char** )p3);
    char* p2=*((char** )p4);
    return strcmp(p1,p2);
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int num=0;
        char** p=(char** )malloc(500*sizeof(char*));
        char* p1;
        char s[501],c=getchar();
        gets(s);
        int len=strlen(s),len1=0,i=0;
        while(i<len){
            c=s[i];
            if(isalpha(c)){
                if(len1==0) {
                    p1=(char* )malloc(500*sizeof(char));
                    p1[len1]=c;
                    i++;
                    len1++;
                }
                else{
                    p1[len1]=c;
                    i++;
                    len1++;
                }
            }
            else if(c==' '||c==','||c=='!'||c=='.'||'?'){
                if(len1>0){
                    p1[len1]=0;
                    *(p+num)=p1;
                    num++;
                    len1=0;
                    i++;
                }
                else i++;
            }
        }
        qsort(p,num,sizeof(char* ),cmp);
        printf("case #%d:\n",t);
        strcpy(s,*p);
        printf("%s ",s);
        for(int n=1;n<num;n++) {
            if(strcmp(*(p+n),s)==0);
            else printf("%s ",*(p+n));
            strcpy(s,(*(p+n)));
        }
        printf("\n");
        for(int j=0;j<num;j++){
            p1=*(p+j);
            free(p1);
        }
        free(p);
    }
    return 0;
}
