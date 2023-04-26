#include<stdio.h>
#include<math.h>
#include<stdlib.h>

char st[123][1234];
char st1[123][1234];
char st2[123][1234];

int check(int i,int j){
    if (strcmp(st2[i],st2[j])>0) return 0;
    else if (strcmp(st2[i],st2[j])<0) return 1;
    else if (strcmp(st1[i],st1[j])>0) return 1;
    else return 0;
}

int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%s",st[i]);
        int j;
        for (j=0;j<strlen(st[i]);j++)
            if (st[i][j]=='@') break;
            else st1[i][j]=st[i][j];
        int k=0;
        while (j<strlen(st[i])){
            st2[i][k]=st[i][j];
            k++;
            j++;
        }
    }
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++){
            if (check(i,j)){
                char temp[1234];
                strcpy(temp,st1[i]);
                strcpy(st1[i],st1[j]);
                strcpy(st1[j],temp);
                strcpy(temp,st2[i]);
                strcpy(st2[i],st2[j]);
                strcpy(st2[j],temp);
            }
        }
    for (int i=0;i<n;i++)
        printf("%s%s\n",st1[i],st2[i]);

    return 0;
}
