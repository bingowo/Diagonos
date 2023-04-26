#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n,year[100],month[100],day[100],hour[100],minute[100],size[100];
char name[100][63];

void swap_int(int* s,int x,int y){
    int temp = s[x];
    s[x] = s[y];
    s[y] = temp;
}
void swap_string(char s[][63],int x,int y){
    char c[63];
    strcpy(c,s[x]);
    strcpy(s[x],s[y]);
    strcpy(s[y],c);
}
void swap_file(int x,int y){
    swap_int(year,x,y);
    swap_int(month,x,y);
    swap_int(day,x,y);
    swap_int(hour,x,y);
    swap_int(minute,x,y);
    swap_int(size,x,y);
    swap_string(name,x,y);
}
int cmp(int x,int y){
    if(year[x] > year[y]){
        return 1;
    }else if(year[x] == year[y]){
        if(month[x] > month[y]){
            return 1;
        }else if(month[x] == month[y]){
            if(day[x] > day[y]){
                return 1;
            }else if(day[x] == day[y]){
                if(hour[x] > hour[y]){
                    return 1;
                }else if(hour[x] == hour[y]){
                    if(minute[x] > minute[y]){
                        return 1;
                    }else if(minute[x] == minute[y]){
                        if(strcmp(name[x],name[y]) > 0){
                            return 1;
                        }
                        else{
                            return -1;
                        }
                    }else{
                        return -1;
                    }
                }else{
                    return -1;
                }
            }else{
                return -1;
            }
        }else{
            return -1;
        }
    }else{
        return -1;
    }
}

int main()
{

    scanf("%d",&n);
    while(n){
        for(int i = 0;i < n;i++){
            scanf("%d-%d-%d %d:%d %d %s\n",&year[i],&month[i],&day[i],&hour[i],&minute[i],&size[i],name[i]);
        }
        char order[4];
        scanf("LIST /%s",order);
        if(strcmp(order,"NAME") == 0){
            for(int i = 0;i < n - 1;i++){
                for(int j = i + 1;j < n;j++){
                    if(strcmp(name[i],name[j]) > 0){
                        swap_file(i,j);
                    }
                }
            }

        }
        if(strcmp(order,"SIZE") == 0){
            for(int i = 0;i < n - 1;i++){
                for(int j = i + 1;j < n;j++){
                    if(size[i] > size[j]){
                        swap_file(i,j);
                    }else if(size[i] == size[j]){
                        if(strcmp(name[i],name[j]) > 0){
                            swap_file(i,j);
                        }
                    }
                }
            }
        }
        if(strcmp(order,"TIME") == 0){
            for(int i = 0;i < n - 1;i++){
                for(int j = i + 1;j < n;j++){
                    if(cmp(i,j) > 0){
                        swap_file(i,j);
                    }
                }
            }
        }
        for(int i = 0;i < n;i++){
            printf("%d-%02d-%02d %02d:%02d %16d %s\n",year[i],month[i],day[i],hour[i],minute[i],size[i],name[i]);
        }
        scanf("%d",&n);
        if(n != 0)printf("%\n");
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n,year[100],month[100],day[100],hour[100],minute[100],size[100];
char name[100][63];

void swap_int(int* s,int x,int y){
    int temp = s[x];
    s[x] = s[y];
    s[y] = temp;
}
void swap_string(char s[][63],int x,int y){
    char c[63];
    strcpy(c,s[x]);
    strcpy(s[x],s[y]);
    strcpy(s[y],c);
}
void swap_file(int x,int y){
    swap_int(year,x,y);
    swap_int(month,x,y);
    swap_int(day,x,y);
    swap_int(hour,x,y);
    swap_int(minute,x,y);
    swap_int(size,x,y);
    swap_string(name,x,y);
}
int cmp(int x,int y){
    if(year[x] > year[y]){
        return 1;
    }else if(year[x] == year[y]){
        if(month[x] > month[y]){
            return 1;
        }else if(month[x] == month[y]){
            if(day[x] > day[y]){
                return 1;
            }else if(day[x] == day[y]){
                if(hour[x] > hour[y]){
                    return 1;
                }else if(hour[x] == hour[y]){
                    if(minute[x] > minute[y]){
                        return 1;
                    }else if(minute[x] == minute[y]){
                        if(strcmp(name[x],name[y]) > 0){
                            return 1;
                        }
                        else{
                            return -1;
                        }
                    }else{
                        return -1;
                    }
                }else{
                    return -1;
                }
            }else{
                return -1;
            }
        }else{
            return -1;
        }
    }else{
        return -1;
    }
}

int main()
{

    scanf("%d",&n);
    while(n){
        for(int i = 0;i < n;i++){
            scanf("%d-%d-%d %d:%d %d %s\n",&year[i],&month[i],&day[i],&hour[i],&minute[i],&size[i],name[i]);
        }
        char order[4];
        scanf("LIST /%s",order);
        if(strcmp(order,"NAME") == 0){
            for(int i = 0;i < n - 1;i++){
                for(int j = i + 1;j < n;j++){
                    if(strcmp(name[i],name[j]) > 0){
                        swap_file(i,j);
                    }
                }
            }

        }
        if(strcmp(order,"SIZE") == 0){
            for(int i = 0;i < n - 1;i++){
                for(int j = i + 1;j < n;j++){
                    if(size[i] > size[j]){
                        swap_file(i,j);
                    }else if(size[i] == size[j]){
                        if(strcmp(name[i],name[j]) > 0){
                            swap_file(i,j);
                        }
                    }
                }
            }
        }
        if(strcmp(order,"TIME") == 0){
            for(int i = 0;i < n - 1;i++){
                for(int j = i + 1;j < n;j++){
                    if(cmp(i,j) > 0){
                        swap_file(i,j);
                    }
                }
            }
        }
        for(int i = 0;i < n;i++){
            printf("%d-%02d-%02d %02d:%02d %16d %s\n",year[i],month[i],day[i],hour[i],minute[i],size[i],name[i]);
        }
        scanf("%d",&n);
        if(n != 0)printf("%\n");
    }
    return 0;
}
