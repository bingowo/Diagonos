#include <stdio.h>
#include <string.h>
const int ABO[4][4][4]=
{{{1,0,0,1},{1,1,1,0},{1,1,1,1},{1,0,0,1}},
{{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,0,1,0}},
{{1,1,1,1},{1,1,1,0},{0,0,1,1},{0,0,1,1}}, 
{{1,0,0,1},{1,0,1,0},{0,0,1,1},{0,0,0,1}}};
int read()
{
    char s[10];
    int flag=-1;
    scanf("%s",s);
    if(strcmp(s,"A")==0) flag = 0;
    else if(strcmp(s,"AB")==0) flag = 1;
    else if(strcmp(s,"B")==0) flag = 2;
    else if(strcmp(s,"O")==0) flag = 3;
    return flag;
}
void write(int num)
{
    if(num==0) printf("A");
    else if(num==1) printf("AB");
    else if(num==2) printf("B");
    else if(num==3) printf("O");
    else printf("impossible");
}
int main()
{
    int father,mother,child;
    father = read();
    mother = read();
    child = read();
    int temp[4],k=0;
    if(father==-1){
        for(int i=0;i<4;i++){
            if(ABO[i][mother][child]==1) temp[k++]=i;
        }
        if(k==0) write(-1);
        else {
            printf("{");
            for(int i=0;i<k;i++){
            if(i==k-1) write(temp[i]);
            else {write(temp[i]);printf(",");}
        	}
            printf("}");
        }
        printf(" ");
        write(mother);
        printf(" ");
        write(child);
    }
    else if(mother==-1){
        write(father);
        printf(" ");
        for(int i=0;i<4;i++){
            if(ABO[father][i][child]==1) temp[k++]=i;
        }
        if(k==0) write(-1);
        else{
            printf("{");
            for(int i=0;i<k;i++){
	            if(i==k-1) write(temp[i]);
            	else {write(temp[i]);printf(",");}
        	}
            printf("}");
        }
        printf(" ");
        write(child);
    }
    else if(child==-1){
        for(int i=0;i<4;i++){
            if(ABO[father][mother][i]==1) temp[k++]=i;
        }
        write(father);
        printf(" ");
        write(mother);
        printf(" ");
        if(k==0) write(-1);
        else {
            printf("{");
            for(int i=0;i<k;i++){
	            if(i==k-1) write(temp[i]);
            	else {write(temp[i]);printf(",");}
            }
            printf("}");
        }
    }
    return 0;
}