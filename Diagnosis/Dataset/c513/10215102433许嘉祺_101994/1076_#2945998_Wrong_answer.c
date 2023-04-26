#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int a[255];
int b[255];
int check(char *s,int len){
    if (len==0) return 1;
    if (len%2==1) return 0;
    if (len==2) 
        if (a[s[0]]==b[s[1]])return 1;
        else return 0;
    int find;
    int type=(a[s[0]]-1+3)%3;
    for (int i=1;i<len-1;i++){

        int num=1;
        int start=i;
        find=1;
        if (a[s[i]]!=type) {find=0;break;}
        while(num!=0){
            i++;
            if (s[i]=='{'||s[i]=='['||s[i]=='(') num++;
            else num--;
        }
        
        if (a[s[start]]!=b[s[i]]){find=0;break;}
        if (check(s+start,i-start+1)==0) {find=0;break;}
    }
    return find;
}

int main()
{
    int t;
    scanf("%d",&t);
    char s[101];
    getchar();
    a['{']=2;
    a['[']=1;
    a['(']=0;
    b['}']=2;
    b[']']=1;
    b[')']=0;
    int find;
    for(int i=0;i<t;i++){
        gets(s);
        for(int j=0;j<strlen(s);j++){
            int num=1;
            int start=j;
            find=1;
            while (num!=0) {
                j++;
                if (s[j]=='{'||s[j]=='['||s[j]=='(') num++;
                else num--;
            }
            if (check(s+start,j-start+1)==0) {find=0;break;}
        }
        if (find==0) printf("No\n");
        else printf("Yes\n");
    }




    return 0;
}