#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main()
{
    int R,T;
    scanf("%d",&T);

    for(R = 0; R < T; R++){
        int index[255] = {0};
        int code[20] = {0};
        int cnt = 0;
        char s[21];
        scanf("%s",s);

        for(int i = 0; s[i]; i++){
            index[s[i]]++;
        }
        //0
        while(index['Z'] != 0){
            code[cnt++] = 0;
            index['Z']--,index['E']--,index['R']--,index['O']--;
        }
        //2
        while(index['W'] != 0){
            code[cnt++] = 2;
            index['T']--,index['W']--,index['O']--;
        }
        //4
        while(index['U'] != 0){
            code[cnt++] = 4;
            index['F']--,index['O']--,index['U']--,index['R']--;
        }
        //6
        while(index['X'] != 0){
            code[cnt++] = 6;
            index['S']--,index['I']--,index['X']--;
        }
        //8
        while(index['G'] != 0){
            code[cnt++] = 8;
            index['E']--,index['I']--,index['G']--,index['H']--,index['T']--;
        }
        //7
        while(index['S'] != 0){
            code[cnt++] = 7;
            index['S']--,index['E']--,index['V']--,index['E']--,index['N']--;
        }
        //5
        while(index['V'] != 0){
            code[cnt++] = 5;
            index['F']--,index['I']--,index['V']--,index['E']--;
        }
        //3
        while(index['R'] != 0){
            code[cnt++] = 3;
            index['T']--,index['H']--,index['R']--,index['E'] -= 2;
        }
        //9
        while(index['I'] != 0){
            code[cnt++] = 9;
            index['N'] -= 2,index['I']--,index['E']--;
        }
        //1
        while(index['O'] != 0){
            code[cnt++] = 1;
            index['O']--,index['N']--,index['E']--;
        }

        qsort(code,cnt,sizeof(int),cmp);
        printf("case #%d:\n",R);
        for(int k = 0; k < cnt; k++){
            printf("%d",code[k]);
        }
        printf("\n");
    }
    return 0;
}
