#include <stdio.h>
int size = 100;
int Stack[100];
int top = -1;
void push(int a){
    if(top>=(size-1)){
        printf("Stack Overflow");
        return;
    }
    Stack[++top] = a;
    return;
}
int pop(){
    if(top<0){
        printf("Stack Underflow");
        return -1;
    }
    return Stack[top--];
}

 int adj[5][5] = {{0,1,1,0,0},{1,0,1,0,0},{1,1,0,1,1},{0,0,1,0,0},{0,0,1,0,0}};
int visited[5] = {0};
// Recursion Logic:- first visit the node and then go to its adjacent nodes and repeat the process for each adjacent node.after visiting all the adjacent nodes of a node, backtrack to the previous node and repeat the process for its unvisited adjacent nodes.print at the time of backtracking.
void DFS(int n){
    for(int i=4;i>=0;i--){
        if(adj[n][i]==1 && visited[i]==0){  
            visited[i]=1;
            DFS(i); 
            printf("%d ",i);
        }
    }
}
void main(){
   

    // push(0);
    // visited[0]=1;
    // // printf("%d ",0);

    // while(top!=-1){
    //     int curr = pop();
    //     printf("%d ",curr);
    //     for(int i=5;i>=0;i--){
    //         if(adj[curr][i]==1 && visited[i]==0){
    //             push(i);
    //             visited[i]=1;
    //         }
    //     }
    // }

    DFS(0);



}