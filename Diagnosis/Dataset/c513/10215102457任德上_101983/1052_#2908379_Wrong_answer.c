#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
    int *m1,*m2;
    m1=(int *)a;
    m2=(int *)b;
    return *m1-*m2;

}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char s[21],*k;
        int num[127],key[10],u=0;
        for(int n=0;n<127;n++)num[n]=0;
        scanf("%s",s);
        k=s;
        while(*k){
            num[*k]++;
            k++;
        }
        while(num['Z']!=0){
            key[u++]=0;
            num['Z']--;
            num['E']--;
            num['R']--;
            num['O']--;
        }
        while(num['W']!=0){
            key[u++]=2;
            num['T']--;
            num['W']--;
            num['O']--;
        }
        while(num['U']!=0){
            key[u++]=4;
            num['F']--;
            num['O']--;
            num['U']--;
            num['R']--;
        }
        while(num['X']!=0){
            key[u++]=6;
            num['S']--;
            num['I']--;
            num['X']--;
        }
        while(num['G']!=0){
            key[u++]=8;
            num['E']--;
            num['I']--;
            num['G']--;
            num['H']--;
            num['T']--;
        }
        while(num['O']!=0){
            key[u++]=1;
            num['O']--;
            num['N']--;
            num['E']--;
        }
        while(num['S']!=0){
            key[u++]=7;
            num['S']--;
            num['N']--;
            num['E']-=2;
            num['V']--;
        }
        while(num['F']!=0){
            key[u++]=5;
            num['F']--;
            num['I']--;
            num['E']--;
            num['V']--;
        }
        while(num['T']!=0){
            key[u++]=3;
            num['T']--;
            num['H']--;
            num['E']-=2;
            num['R']--;
        }
        while(num['N']!=0){
            key[u++]=9;
            num['N']-=2;
            num['I']--;
            num['E']--;
        }
        qsort(key,u,sizeof(int),cmp);
        printf("case #%d:\n",i);
        for(int b=0;b<u;b++){
            printf("%d",key[b]);
        }
        return 0;
    }





}