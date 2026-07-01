#include <stdio.h>
#define size 10

int queue[size];
int front = -1;
int rear = -1;

void enqueue(int data) {

    
    if(rear == size - 1) {
        printf("Queue is Full\n");
        return;
    }

    if(front == -1) {
        front = 0;
    }

    queue[++rear] = data;
}

int dequeue() {

    if(front == -1) {
        printf("Queue is Empty\n");
        return -1;
    }

    int item = queue[front];

    if(front == rear) {
        front = rear = -1;
    }
    else {
        front++;
    }

    return item;
}

void main(){
    int adj[5][5] = {{0,1,1,0,0},{1,0,1,1,0},{1,1,0,0,1},{1,0,0,0,1},{0,0,1,1,0}};
    int visited[5] = {0};
    enqueue(0);
    visited[0] = 1;
    while(front!=-1){
        int curr = dequeue();
        printf("%d ",curr);
        for(int i=0;i<5;i++){
            if(adj[curr][i]==1 && visited[i]==0){
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

