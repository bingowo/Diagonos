#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int table[130]={0};

void count(char *s)
{
    for(int i=0;i<strlen(s);i++){
        table[s[i]]++;
    }
}

int cmp(const void* a,const void* b)
{
    int x=*((int*)a);
    int y=*((int*)b);
    return x-y;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        int res[10]={0};
        for(int j=0;j<130;j++){
            table[j]=0;
        }
        char s[20]={0};
        scanf("%s",s);
        count(s);
        int t=table['Z'],d=0,len=0;
        for(int i=0;i<t;i++){
            table['Z']--;
            table['E']--;
            table['R']--;
            table['O']--;
            res[d++]=0;
            len++;
        }
        //2
        t=table['W'];
        for(int i=0;i<t;i++){
            table['T']--;
            table['W']--;
            table['O']--;
            res[d++]=2;
            len++;
        }
        //4
        t=table['U'];
        for(int i=0;i<t;i++){
            table['F']--;
            table['O']--;
            table['U']--;
            table['R']--;
            res[d++]=4;
            len++;
        }
        //6
        t=table['X'];
        for(int i=0;i<t;i++){
            table['S']--;
            table['I']--;
            table['X']--;
            res[d++]=6;
            len++;
        }
        //7
        t=table['S'];
        for(int i=0;i<t;i++){
            table['S']--;
            table['E']--;
            table['V']--;
            table['E']--;
            table['N']--;
            res[d++]=7;
            len++;
        }
        //8
        t=table['G'];
        for(int i=0;i<t;i++){
            table['E']--;
            table['I']--;
            table['G']--;
            table['H']--;
            table['T']--;
            res[d++]=8;
            len++;
        }
        //5
        t=table['V'];
        for(int i=0;i<t;i++){
            table['F']--;
            table['I']--;
            table['V']--;
            table['E']--;
            res[d++]=5;
            len++;
        }
        //3
        t=table['T'];
        for(int i=0;i<t;i++){
            table['T']--;
            table['H']--;
            table['R']--;
            table['E']--;
            table['E']--;
            res[d++]=3;
            len++;
        }
        //1
        t=table['O'];
        for(int i=0;i<t;i++){
            table['O']--;
            table['N']--;
            table['E']--;
            res[d++]=1;
            len++;
        }
        //9
        t=table['I'];
        for(int i=0;i<t;i++){
            table['N']--;
            table['I']--;
            table['N']--;
            table['E']--;
            res[d++]=9;
            len++;
        }
        qsort(res,len,sizeof(int),cmp);
        for(int j=0;j<len;j++){
            printf("%d",res[j]);
        }
        printf("\n");
    }
    return 0;
}
