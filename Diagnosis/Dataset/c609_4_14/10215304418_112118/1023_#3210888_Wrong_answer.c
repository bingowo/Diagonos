#include<stdio.h>
#include<math.h>
#include<stdlib.h>

char st1[1234][1234];
char st2[1234][1234];
int year[1234];
int n;
char month[19][20]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};

int find(int x){
    for (int i=0;i<19;i++){
        if (strcmp(month[i],st2[x])==0) return i;
    }
}


int check(int i,int j){
    int num1=0,num2=0;
    for (int k=0;k<strlen(st1[i])-1;k++){
        num1*=10;
        num1+=st1[i][k]-'0';
    }
    for (int k=0;k<strlen(st1[j])-1;k++){
        num2*=10;
        num2+=st1[j][k]-'0';
    }
    printf("%d %d\n",find(i),find(j));
    if (year[i]<year[j]) return 0;
    else if (year[i]>year[j]) return 1;
    else if (find(i)>find(j)) return 1;
    else if (find(i)<find(j)) return 0;
    else if (num1<num2) return 0;
    else return 1;
}

int main(){
    int t;
    scanf("%d",&t);
    for (int l=1;l<=t;l++){
        scanf("%d",&n);
        for (int k=1;k<=n;k++){
            scanf("%s %s %d",st1[k],st2[k],&year[k]);
        }
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++){
                if (check(i,j)){
                    char tempst[1234];
                    strcpy(tempst,st1[i]);
                    strcpy(st1[i],st1[j]);
                    strcpy(st1[j],tempst);
                    strcpy(tempst,st2[i]);
                    strcpy(st2[i],st2[j]);
                    strcpy(st2[j],tempst);
                    int temp=year[i];
                    year[i]=year[j];
                    year[j]=temp;
                }
            }
        printf("case #%d:\n",l-1);
        for (int i=1;i<=n;i++){
            printf("%s %s %d\n",st1[i],st2[i],year[i]);
        }
    }
    return 0;
}
