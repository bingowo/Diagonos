#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char alp[27];
int strcmp1(char* s1,char* s2){
    int count=0;
    char temp1,temp2;
    while(s1[count]!='\0'&&s2[count]!='\0'){
        temp1=s1[count];
        if((int)temp1>=97&&(int)temp1<=122){
            temp1-=32;
        }
        if((int)temp2>=97&&(int)temp2<=122){
            temp2-=32;
        }
        if(temp1==temp2){
            count++;
        }
        else if(strchr(alp,temp1)>strchr(alp,temp2)){
            return 1;
        }
        else{
            return -1;
        }
    if(s1[count]=='\0'&&s2[count]=='\0'){
        return 0;
    }
    if(s1[count]=='\0'){
        return -1;
    }
    if(s2[count]=='\0'){
        return 1;
    }
    }
}
int cmp(void const* x,void const* y){
    return (strcmp1((char*)x,(char*)y));
}
int main(){
    char **s,c;
    int count,num;
    while(scanf("%s",alp)!=EOF){
        s=(char**)malloc(sizeof(char*)*100);
        count=0;
        num=0;
        s[num]=(char*)malloc(sizeof(char)*21);
        getchar();
        scanf("%c",&c);
        while(c!='\n'){
            if(c!=' '){
                s[num][count++]=c;
            }
            else{
                s[num][count]='\0';
                num++;
                s[num]=(char*)malloc(sizeof(char)*21);
                count=0;
            }
            scanf("%c",&c);
        }
        s[num][count]='\0';
        num++;
        qsort(s,num,sizeof(s[0]),cmp);
        for(int i=0;i<num;i++){
           printf("%s ",s[i]);
           if(i==num-1){
               printf("\n");
           }
           }
        
    }
    
    
    return 0;
}