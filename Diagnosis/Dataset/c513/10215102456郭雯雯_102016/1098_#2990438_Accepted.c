#include<stdio.h>
#include<string.h>

int main(){
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        char s[110];
        scanf("%s",s);
        int l=strlen(s),num[4]={0},tl[4]={0},n[4]={0};
        for(int i=0;i<l;i++){
            tl[i%4]++;
            switch(s[i]){
                case 'R':num[0]++;n[0]=i%4;break;
                case 'B':num[1]++;n[1]=i%4;break;
                case 'Y':num[2]++;n[2]=i%4;break;
                case 'G':num[3]++;n[3]=i%4;break;
            }
        }
        printf("case #%d:\n",a);
        printf("%d %d %d %d\n",tl[n[0]]-num[0],tl[n[1]]-num[1],tl[n[2]]-num[2],tl[n[3]]-num[3]);
        a++;
    }
    return 0;
}