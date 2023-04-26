#include<stdio.h>
#include<string.h>

void func(char s[], int slen, int arr[]){
    for (int index=0; index<slen; index++){
        while(index<slen&&(s[index]=='!'||arr[s[index]]!=0))index++;
        if (index>=slen) break;
        arr[s[index]]++;
        for (int i=index; i<slen; i+=4) if (s[i]=='!') {arr[s[index]]++;s[i]=s[index];}
        for (int i=index; i>=0; i-=4) if (s[i]=='!') {arr[s[index]]++;s[i]=s[index];}
    }
    return;
}

int main(){
    int T;
    scanf("%d ", &T);
    for (int t=0; t<T; t++){
        printf("case #%d:\n", t);
        char s[105]={};
        gets(s);
        int slen = strlen(s);
        int arr[128]={0};
        func(s, slen, arr);
        int count=1;
        for (int i=0; i<slen; i++) if (s[i]=='!') count++;
        if (arr['R']==0) arr['R']+=count;
        else if (arr['B']==0) arr['B']+=count;
        else if (arr['Y']==0) arr['Y']+=count;
        else if (arr['G']==0) arr['G']+=count;
        printf("%d %d %d %d\n", arr['R']-1,arr['B']-1,arr['Y']-1,arr['G']-1);
    }
    return 0;
}