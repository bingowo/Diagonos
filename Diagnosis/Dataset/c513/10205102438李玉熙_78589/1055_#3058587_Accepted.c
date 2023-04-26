
#include<stdio.h>
int main()
{
    char s[1000001];
    int exist[128]={0},place[128]={-1};
    int length=0,head=0,temp=0,begin=0;
    scanf("%s",s);
    for(int i=0;s[i];i++){
        if(!exist[s[i]]||place[s[i]]<head-1){
            temp++;
            exist[s[i]]=1;
            place[s[i]]=i;
        }
        else{
            if(temp>length){
                length=temp;
                begin=head;
            }
            head=place[s[i]]+1;
            temp=i-place[s[i]];
            place[s[i]]=i;
        }
    }
    if(length==0)length=temp;
    for(int i=begin;i<begin+length;i++)printf("%c",s[i]);
}