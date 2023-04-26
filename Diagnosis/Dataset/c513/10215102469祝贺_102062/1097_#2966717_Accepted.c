#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct{
    int row;
    int col;
    char c;
}pos;

int cmp(const void*a, const void* b){
    pos* n1=(pos*)a,*n2=(pos*)b;
    if(n1->row!=n2->row) return n2->row-n1->row;
    else return n1->col-n2->col;
}
int main(){
    char s[100];
    while(scanf("%s",s)!=EOF){
        pos stack[strlen(s)];int sp=1;
        int rowp=1,colp=1;
        stack[0].row=0;
        stack[0].col=0;
        stack[0].c=s[0];
        for(int i=1;i<strlen(s);i++){
            if(s[i]-stack[sp-1].c>0) stack[sp].row=stack[sp-1].row+1;
            else if(s[i]-stack[sp-1].c<0) stack[sp].row=stack[sp-1].row-1;
            else stack[sp].row=stack[sp-1].row;

            stack[sp].col=stack[sp-1].col+1;
            stack[sp].c=s[i];
            sp++;
        }
        qsort(stack,sp,sizeof(stack[0]),cmp);

        pos last=stack[0];
        for(int i=0;i<last.col;i++) printf(" ");
        printf("%c",last.c);

        for(int i=1;i<sp;i++){
            if(stack[i].row==last.row){
                for(int j=0;j<stack[i].col-last.col-1;j++) printf(" ");
            }
            else {
                printf("\n");
                for(int j=0;j<stack[i].col;j++) printf(" ");
            }
            printf("%c",stack[i].c);
            last=stack[i];
        }
        printf("\n");
    }
}
