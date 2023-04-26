#include<stdio.h>
#include<stdlib.h>//结构体的构建
#include<string.h>
typedef struct a{
    char date[12];
    char time[7];
    long long size;
    char name[150];
}data;
int cmpname(const void*a1,const void*a2){
    data*p1=(data*)a1;data*p2=(data*)a2;
    return strcmp(p1->name,p2->name); 
}
int cmpsize(const void*a1,const void*a2){
    data*p1=(data*)a1;data*p2=(data*)a2;
    if(p1->size!=p2->size){
        if(p1->size>p2->size)return 1;
        else return -1;
    }
    else return strcmp(p1->name,p2->name); 
}
int cmptime(const void*a1,const void*a2){
    data*p1=(data*)a1;data*p2=(data*)a2;
     if(strcmp(p1->date,p2->date)!=0){
        return strcmp(p1->date,p2->date);
    }
    else if(strcmp(p1->date,p2->date)==0){
        if(strcmp(p1->time,p2->time)!=0){
            return strcmp(p1->time,p2->time);
        }
        else return strcmp(p1->name,p2->name);
    }  
}
int main(){
int n;
data s[110];
scanf("%d",&n);
if(n!=0){
  for(int i=0;i<n;i++){
  scanf("%s",&s[i].date);
  scanf("%s",&s[i].time);
  scanf("%lld",&s[i].size);
  scanf("%s",&s[i].name);
  }
  char cc;
  cc=getchar();
  char command[15];
  gets(command);
  if(command[6]=='N'){
    qsort(s,n,sizeof(data),cmpname);
  }
  else if(command[6]=='S'){
    qsort(s,n,sizeof(data),cmpsize);
  }
   else if(command[6]=='T'){
    qsort(s,n,sizeof(data),cmptime);
  }
  for(int i=0;i<n;i++){
    printf("%s %s %16d %s\n",s[i].date,s[i].time,s[i].size,s[i].name);
  }
}
return 0;
}