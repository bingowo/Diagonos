#include<stdio.h>
#include<string.h>

void func(char s[], int i, int arr[]){
    int used[128]={0};
    for (int j=1; j<4; j++)used[s[j+i]]=1;
    if (used['R']==0) {s[i]='R';arr['R']++;}
    else if (used['B']==0) {s[i]='B';arr['B']++;}
    else if (used['Y']==0) {s[i]='Y';arr['Y']++;}
    else if (used['G']==0) {s[i]='G';arr['G']++;}
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
        for (int index=0; index<slen; index++){
            while(index<slen&&(s[index]=='!'||arr[s[index]]!=0))index++;
            if (index>=slen) break;
            char c=s[index];
            for (int i=index+4; i<slen; i+=4){
                if (s[i]=='!'){
                    arr[c]++;
                    s[i]=c; 
                }      
            }
            for (int i=index-4; i>=0; i-=4){
                if (s[i]=='!'){
                    arr[c]++;
                    s[i]=c;                        
                }
            }
        }
        for (int i=0; i<slen-4; i++){
            if (s[i]=='!'){
                func(s, i, arr);
            }
        }
        printf("%d %d %d %d\n", arr['R'],arr['B'],arr['Y'],arr['G']);
    }
    return 0;
}