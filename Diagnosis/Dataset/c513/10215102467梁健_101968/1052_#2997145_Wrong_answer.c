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
int main()
{
    int T;scanf("%d",&T);
    for(int step=0;step<T;step++){
        int k=0;
        printf("case #%d:\n",step);
        char s[21];scanf("%s",s);
        char judge[128];char res[10];
        judge[0]=0;
        for(int i=0;i<strlen(s);i++){
            judge[s[i]]++;
        }
        if(judge['Z']>0){
            for(int i=0;i<judge['Z'];i++){
                res[k++]='0';
            }
            judge['W']-=judge['Z'];
            judge['X']-=judge['Z'];
            judge['G']-=judge['Z'];
            judge['S']-=judge['Z'];
            judge['T']-=judge['Z'];
            judge['U']-=judge['Z'];
            judge['F']-=judge['Z'];
            judge['O']-=judge['Z'];
            judge['N']-=judge['Z'];
        }
        if(judge['W']>0){
            for(int i=0;i<judge['W'];i++){
                res[k++]='2';
            }
            judge['X']-=judge['W'];
            judge['G']-=judge['W'];
            judge['S']-=judge['W'];
            judge['T']-=judge['W'];
            judge['U']-=judge['W'];
            judge['F']-=judge['W'];
            judge['O']-=judge['W'];
            judge['N']-=judge['W'];
        }
        if(judge['X']>0){
            for(int i=0;i<judge['X'];i++){
                res[k++]='6';
            }
            judge['G']-=judge['X'];
            judge['S']-=judge['X'];
            judge['T']-=judge['X'];
            judge['U']-=judge['X'];
            judge['F']-=judge['X'];
            judge['O']-=judge['X'];
            judge['N']-=judge['X'];
        }
        if(judge['G']>0){
            for(int i=0;i<judge['G'];i++){
                res[k++]='8';
            }
            judge['S']-=judge['G'];
            judge['T']-=judge['G'];
            judge['U']-=judge['G'];
            judge['F']-=judge['G'];
            judge['O']-=judge['G'];
            judge['N']-=judge['G'];
        }
        if(judge['S']>0){
            for(int i=0;i<judge['S'];i++){
                res[k++]='7';
            }
            judge['T']-=judge['S'];
            judge['U']-=judge['S'];
            judge['F']-=judge['S'];
            judge['O']-=judge['S'];
            judge['N']-=judge['S'];
        }
        if(judge['T']>0){
            for(int i=0;i<judge['T'];i++){
                res[k++]='3';
            }
            judge['U']-=judge['T'];
            judge['F']-=judge['T'];
            judge['O']-=judge['T'];
            judge['N']-=judge['T'];
        }
        if(judge['U']>0){
            for(int i=0;i<judge['U'];i++){
                res[k++]='4';
            }
            judge['F']-=judge['U'];
            judge['O']-=judge['U'];
            judge['N']-=judge['U'];
        }
        if(judge['F']>0){
            for(int i=0;i<judge['F'];i++){
                res[k++]='5';
            }
            judge['O']-=judge['F'];
            judge['N']-=judge['F'];
        }
        if(judge['O']>0){
            for(int i=0;i<judge['O'];i++){
                res[k++]='1';
            }
            judge['N']-=judge['O'];
        }
        if(judge['N']>0){
            for(int i=0;i<judge['N'];i++){
                res[k++]='9';
            }
        }
        res[k]=0;
        qsort(res,k,sizeof(char),strcmp);
        printf("%s\n",res);
    }
    return 0;
}
