#include<stdio.h>
#include<stdlib.h>

int main(){
int t,d=0;
scanf("%d",&t);
while(t>0){
int x[100],n,k,i,j;
scanf("%d",&n);
char str[100][20];
for(i=0;i<n;i++){
scanf("%s",str[i]);
x[i]=1;
for(j=1;j<strlen(str[i]);j++){
for(k=0;k<=j-1;k++){
if(str[i][j]==str[i][k]){
break;
}else if(k==j-1){
x[i]++;
}
}
}
}

    for(i=n-1;i>=1;i--){
        for(j=1;j<=i;j++){
           if(x[j]>x[j-1]){
                 char shu[20];
                 strcpy(shu,str[j]);
                 strcpy(str[j],str[j-1]);
                 strcpy(str[j-1],shu);
                 int p=x[j-1];x[j-1]=x[j];x[j]=p;
           }else if(x[j]==x[j-1]){
              if(strcmp(str[j],str[j-1])<0){
                 char shu[20];
                 strcpy(shu,str[j]);
                 strcpy(str[j],str[j-1]);
                 strcpy(str[j-1],shu);
                 int p=x[j-1];x[j-1]=x[j];x[j]=p;
              }
           }
        }
    }
    printf("case #%d:\n",d);
    for(i=0;i<=n-1;i++){
       puts(str[i]);
    }
    t--;d++;
}
}