//string\1040.c


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
/*
    one word pressure test
*/

//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

struct blood{int A,B,O;};
struct pos_blood{int A,AB,B,O;};
char* ans[6];
int anslen=0;
typedef struct blood btype;
typedef struct pos_blood allbl;
btype possible_baby(char* p)//blood to
{
    btype ret={0,0,0};
    if(p[0]=='A'){
        if(p[1]=='B'){
            ret.A=TRUE;
            ret.B=TRUE;
            ret.O=FALSE;
            //AB blood
        }else{
            ret.A=TRUE;
            ret.B=FALSE;
            ret.O=TRUE;
            //A blood
        }
    }else if(p[0]=='O'){
        ret.A=FALSE;
        ret.B=FALSE;
        ret.O=TRUE;
    }else{
        ret.A=FALSE;
        ret.B=TRUE;
        ret.O=TRUE;
        //B blood
    }
    return ret;
}

char allblood[4][4]={"A","AB","B","O"};
char ts[4][30];
int unknown;
allbl check_poss_blood(btype x,btype y)
{
    allbl ret={0,0,0,0};
    if((x.A&&y.A)||(x.A&&y.O)||(x.O&&y.A))
        ret.A=TRUE;
    if((x.B&&y.A)||(x.A&&y.B))
        ret.AB=TRUE;
    if((x.B&&y.B)||(x.B&&y.O)||(x.O&&y.B))
        ret.B=TRUE;
    if(x.O&&y.O)
        ret.O=TRUE;
    return ret;
}

void conclude_parent(char *son,btype ano)
{
    if(son[0]=='A'){
        if(son[1]=='B'){
            //need an A and an B;
            for(int i=0;i<4;++i){
                allbl tp=check_poss_blood(possible_baby(allblood[i]),ano);
                if(tp.AB)
                    ans[anslen++]=(char*)allblood[i];
            }
        }else{
            for(int i=0;i<4;++i){
                allbl tp=check_poss_blood(possible_baby(allblood[i]),ano);
                if(tp.A)ans[anslen++]=(char*)allblood[i];
            }
        }
    }else if(son[0]=='B'){
        for(int i=0;i<4;++i){
                allbl tp=check_poss_blood(possible_baby(allblood[i]),ano);
                if(tp.B)ans[anslen++]=(char*)allblood[i];
            }
    }else{
        for(int i=0;i<4;++i){
            allbl tp=check_poss_blood(possible_baby(allblood[i]),ano);
            if(tp.O)
                ans[anslen++]=(char*)allblood[i];
        }
    }
}
void pr_ans()
{
    if(anslen==0){
        printf("impossible");
    }else{
        printf("{%s",ans[0]);
        for(int i=1;i<anslen;++i){
            printf(",%s",ans[i]);
        }
        putchar('}');
    }

}

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    for(int i=1;i<=3;++i){
        scanf("%s",ts[i]);
        if(ts[i][0]=='?')
            unknown=i;
    }
    if(unknown==3)//children unknown
    {
        btype p1=possible_baby(ts[1]);
        btype p2=possible_baby(ts[2]);
        allbl possible=check_poss_blood(p1,p2);
        if(possible.A)
            ans[anslen++]=(char*)allblood[0];
        if(possible.AB)
            ans[anslen++]=(char*)allblood[1];
        if(possible.B)
            ans[anslen++]=(char*)allblood[2];
        if(possible.O)
            ans[anslen++]=(char*)allblood[3];
        printf("%s %s ",ts[1],ts[2]);
        pr_ans();

    }else{//parents unknown
        btype x;
        if(unknown==1)
            x=possible_baby(ts[2]);
        else
            x=possible_baby(ts[1]);

        conclude_parent(ts[3],x);
        if(unknown==1){
            pr_ans();
            printf(" %s %s",ts[2],ts[3]);
        }else{
            printf("%s ",ts[1]);
            pr_ans();
            printf(" %s",ts[3]);
        }

    }
}

