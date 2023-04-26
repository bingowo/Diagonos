//string\1048.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
/*
    
*/


#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

struct single
{
    int coe;
    int pow;
};
typedef struct single item;

item A[60];
int Alen;
item B[60];
int Blen;

int getformula(item arr[],int *len)
{
    char c=getchar();
    while(c!=' '&&c!='\n'&&c!=EOF){
        int neg=FALSE;
        if(c=='+'||c=='-'){
            if(c=='-'){
                neg=TRUE;
            }
            c=getchar();//if signal, getnext
        }
        //coefficient module------------------
        int temcoe=0;
        int tempow=0;
        if(isdigit(c)){
            while(c!=' '&&c!='\n'&&c!=EOF&&c!='x'){
                temcoe=temcoe*10+c-'0';
                c=getchar();
            }
            if(c!='x'){
                arr[*len].pow=0;
                arr[*len].coe=neg?-temcoe:temcoe;
                ++(*len);
                continue;//a leave area
            }
        }else if(c=='x'){
            temcoe=1;
        }else{
            printf("ERROR");
        }
        //coefficient module------------------
        if((c=getchar())=='^'){
            while(isdigit(c=getchar())){
                tempow=tempow*10+c-'0';
            }
        }else{
            tempow=1;
        }
        arr[*len].pow=tempow;
        arr[*len].coe=neg?-temcoe:temcoe;
        ++(*len);
    }
    if(c=='\n')
        return 1;
    else if(c==EOF)
        return -1;
    else
        return 0;
}

#define MAX 2000
int calcarea[MAX];
void mult_and_pr()
{
    memset(calcarea,0,MAX*sizeof(calcarea[0]));
    for(int ib=0;ib<Blen;++ib){
        for(int ia=0;ia<Alen;++ia){
            calcarea[A[ia].pow+B[ib].pow]
            +=A[ia].coe * B[ib].coe;
        }
    }
    //this is not a high ac calculation
    int first=TRUE;
    for(int i=MAX-1;i>=0;--i){
        if(calcarea[i]!=0){
            if(!first){
                putchar(' ');
            }
            printf("%d",calcarea[i]);
            first=FALSE;
        }
    }
    putchar('\n');
}

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int no_end=TRUE;
    while(no_end){
        Alen=0;
        Blen=0;
        if(getformula(A,&Alen)==-1){
            no_end=FALSE;
            break;
        }
        if(getformula(B,&Blen)==-1){
            no_end=FALSE;
        }
        mult_and_pr();
    }
}

