#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int cmp(const void* p3,const void* p4)
{
    char* p1=(char* )p3;
    char* p2=(char* )p4;
    int x=*(p1)-'A';
    int y=*(p2)-'A';
    if((x<26)&&(y<26)&&(x>=0)&&(y>=0)) {
        if(x<y) return -1;
        else return 1;
    }
    else return -1;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    getchar();
    for(int t=0;t<T;t++){
        char* p=(char* )malloc(200*sizeof(char));
        char* p1=(char* )malloc(200*sizeof(char));
        char c;
        int n=0,n1=0;
        while((c=getchar())!='\n'){
            *(p1+n1)=c;
            n1++;
            if(isalpha(c)) {
                *(p+n)=c;
                n++;
            }
        }
        qsort(p,n,sizeof(char),cmp);
        printf("case #%d:\n",t);
        for(int i=0,j=0;i<n1;i++) {
            if(isalpha(*(p1+i))) {printf("%c",*(p+j));j++;}
            else printf("%c",*(p1+i));
        };
        printf("\n");
        free(p);
        free(p1);
    }
    return 0;
}
