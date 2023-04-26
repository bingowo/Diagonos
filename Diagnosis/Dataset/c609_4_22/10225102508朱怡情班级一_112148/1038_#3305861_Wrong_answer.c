#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int cmp(const void *a,const void *b)
{
    char *x=(char*)a;
    char *y=(char*)b;
    return strcmp(x,y);
}

int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    for(int i=0;i<t;i++){
        char check[501][501];
        char c;
        int pos1=0,pos2=0;
        while((c=getchar())!='\n'){
            if((pos1!=0||pos2!=0)&&(c==' '||c==','||c=='.'||c=='!'||c=='?')){
                check[pos1][pos2]=0;
                pos2=0;
                int flag=1;
                for(int j=0;j<pos1;j++){
                    if(strcmp(check[j],check[pos1])==0){
                        flag=0;
                        break;
                    }
                }
                if(flag)pos1++;
                while((c=getchar())==' ');
            }
            if(c=='\n')break;
            if(c!=' '&&c!=','&&c!='.'&&c!='!'&&c!='?')check[pos1][pos2++]=c;
        }
        if(pos2!=0){
        check[pos1][pos2]=0;
        int flag=1;
        for(int j=0;j<pos1;j++){
            if(strcmp(check[j],check[pos1])==0){
                flag=0;
                break;
            }
        }
        if(flag)pos1++;}
        qsort(check,pos1,sizeof(check[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<pos1;j++)printf("%s ",check[j]);
        printf("\n");
    }
    return 0;
}
