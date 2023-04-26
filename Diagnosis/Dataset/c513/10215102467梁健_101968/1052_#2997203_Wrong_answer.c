#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
//one two three four five six seven eight nine Zero
//one tWo three four five six seven eight nine
//one three four five siX seven eight nine
//one three four five seven eiGht nine
//one three four five Seven nine
//one Three four five nine
//one foUr five nine
//one Five nine
//One nine
//Nine
// Z,W,X,G,S,T,U,F,O,N;
int cmp(const void *a,const void *b)
{
    int a1=*(char *)a,b1=*(char *)b;
    return a1>b1?1:-1;
}
int main()
{
    int T;scanf("%d",&T);
    for(int step=0;step<T;step++){
        int k=0;
        printf("case #%d:\n",step);
        char s[21];scanf("%s",s);
        char judge[128];char res[10];
        for(int i=0;i<128;i++)judge[i]=0;
        for(int i=0;i<strlen(s);i++){
            judge[s[i]]++;
        }
        if(judge['Z']>0){
            for(int i=0;i<judge['Z'];i++){
                res[k++]='0';
            }
            judge['O']-=judge['Z'];
        }
        if(judge['W']>0){
            for(int i=0;i<judge['W'];i++){
                res[k++]='2';
            }
            judge['T']-=judge['W'];
            judge['O']-=judge['W'];
        }
        if(judge['X']>0){
            for(int i=0;i<judge['X'];i++){
                res[k++]='6';
            }
        }
        if(judge['G']>0){
            for(int i=0;i<judge['G'];i++){
                res[k++]='8';
            }
            judge['T']-=judge['G'];
        }
        if(judge['S']>0){
            for(int i=0;i<judge['S'];i++){
                res[k++]='7';
            }
            judge['N']-=judge['S'];
        }
        if(judge['T']>0){
            for(int i=0;i<judge['T'];i++){
                res[k++]='3';
            }
        }
        if(judge['U']>0){
            for(int i=0;i<judge['U'];i++){
                res[k++]='4';
            }
            judge['F']-=judge['U'];
            judge['O']-=judge['U'];
        }
        if(judge['F']>0){
            for(int i=0;i<judge['F'];i++){
                res[k++]='5';
            }
        }
        if(judge['O']>0){
            for(int i=0;i<judge['O'];i++){
                res[k++]='1';
            }
            judge['N']-=judge['O'];
        }
        if(judge['N']>0){
            for(int i=0;i<judge['N']/2;i++){
                res[k++]='9';
            }
        }
        qsort(res,k,sizeof(char),cmp);
        res[k]=0;
        printf("%s\n",res);
    }
    return 0;
}
