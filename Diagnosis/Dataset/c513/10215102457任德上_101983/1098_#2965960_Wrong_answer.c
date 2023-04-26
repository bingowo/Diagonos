#include<stdio.h>
#include<string.h>
typedef struct{
    int c;
    int item;
}light;
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char s[101];
        scanf("%s",s);
        light r={0,0},b={0,0},y={0,0},g={0,0};
        for(int k=0;k<strlen(s);k++){
            if(s[k]!='!'){
                char *p;
                p=strchr(s+k,'R');
                r.item=(p-s)%4;
                p=strchr(s+k,'B');
                b.item=(p-s)%4;
                p=strchr(s+k,'Y');
                y.item=(p-s)%4;
                p=strchr(s+k,'G');
                g.item=(p-s)%4;
                break;
            }
        }
        for(int k=0;k<strlen(s);k++){
            if(s[k]=='!'){
                if(r.item==k%4)r.c++;
                else if(b.item==k%4)b.c++;
                else if(y.item==k%4)y.c++;
                else g.c++;
            }
         }
        printf("case #%d:\n%d %d %d %d\n",i,r,b,y,g);

    }
    return 0;
}