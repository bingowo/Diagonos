#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Maxlen 1001

void count(char word[],int choice[],int len);
void multiply(int num[],int n);
void add(int num1[],int num2[]);

int main(){
    char word[Maxlen];
    scanf("%s",word);
    int len=(int)strlen(word);
    int choice[len];
    if(len==1)choice[0]=1;
    else count(word,choice,len);
    int number[Maxlen]={0};
    number[Maxlen-1]=1;
    for(int i=0;i<len;i++)multiply(number,choice[i]);
    int index=0;
    while(!number[index])index++;
    for(;index<Maxlen;index++)printf("%d",number[index]);
    printf("\n");
    return 0;
}

void count(char word[],int choice[],int len){
    if(word[0]==word[1])choice[0]=1;
    else choice[0]=2;
    for(int i=1;i<len-1;i++){
        if(word[i]!=word[i-1]&&word[i]!=word[i+1]&&word[i-1]!=word[i+1])choice[i]=3;
        else if(word[i]!=word[i-1]||word[i]!=word[i+1])choice[i]=2;
        else choice[i]=1;
    }
    if(word[len-1]==word[len-2])choice[len-1]=1;
    else choice[len-1]=2;
}
void multiply(int num[],int n){
    int num0[Maxlen];
    memmove(num0, num, sizeof(num0));
    for(int i=1;i<n;i++)add(num,num0);
}
void add(int num1[],int num2[]){
    for(int i=Maxlen-1;i>0;i--){
        num1[i]+=num2[i];
        for(int j=i;num1[j]>=10;j--){
            num1[j-1]+=1;
            num1[j]-=10;
        }
    }
}
