#include<stdio.h>
#include<string.h>

int main(){
    char s[100];
    while(~scanf("%s", s)){
        char graph[200][100] = {0};
        int len = strlen(s);
        graph[100][0] = s[0];
        int ceil = 100, floor = 100, forward = 100;
        for (int i = 1; i != len; i++){
            if (s[i] > s[i-1]){
                graph[--forward][i] = s[i];
                for (int j = strlen(graph[forward]); j < i; j++)
                    graph[forward][j] = ' ';
            }
            else if (s[i] < s[i-1]){
                graph[++forward][i] = s[i];
                for (int j = strlen(graph[forward]); j < i; j++)
                    graph[forward][j] = ' ';
            }
            else if (s[i] == s[i-1]){
                graph[forward][i] = s[i];
                for (int j = strlen(graph[forward]); j < i; j++)
                    graph[forward][j] = ' ';
            }
            if (ceil < forward) ceil = forward;
            if (floor > forward) floor = forward;
        }
        for (; floor <= ceil; floor++)
            printf("%s\n", graph[floor]);
    }
    return 0;
}