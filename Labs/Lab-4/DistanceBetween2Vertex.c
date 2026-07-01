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
void clearQueue(){
    for(int i=0;i<size;i++){
        queue[i] = 0;
    }
    front = -1;
    rear = -1;
}

void main(){
    int adj[6][6] = {{0,1,0,0,0,0},{1,0,1,1,0,0},{0,1,0,0,0,0},{0,1,0,0,1,1},{0,0,0,1,0,0},{0,0,0,1,0,0}};
    int distance[6][6] = {0};
    int visited[6] = {0};
    int sourceNode = 0;
    for(int i=0;i<6;i++){
        sourceNode = i;
        enqueue(sourceNode);
        visited[sourceNode] = 1;
        while(front!=-1){
            int curr = dequeue();
            printf("%d \n",curr);
            for(int i=0;i<6;i++){
                if(adj[curr][i]==1 && visited[i]==0){
                    enqueue(i);
                    visited[i] = 1;
                    distance[sourceNode][i] = distance[sourceNode][curr] + 1;
                }
            }
        }
        clearQueue();
        for(int i=0;i<6;i++) visited[i] = 0;
    }
    
    printf("\n\n\n\n");

    // for(int i=0;i<6;i++){
    //     for(int j=0;j<6;j++){
    //         printf("%d ",distance[i][j]);
    //     }
    //     printf("\n");
    // }



    // Ecentricity ------

    int ecentricity[6];
    int max = 0;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(max < distance[i][j]) max = distance[i][j];
            // printf("%d ",distance[i][j]);
        }
        ecentricity[i] = max;
        max = 0;
        // printf("\n");
    }
    printf("\nEcentricity of every node ");
    for(int i=0;i<6;i++){
        printf("\nEcentricity of %d = %d",i,ecentricity[i]);
    }

    // Center----
    int center1 = -1;
    int center2 = -1;
    int minEcentricity = 100;

    for(int i=0;i<6;i++){
        if(ecentricity[i] < minEcentricity){
            minEcentricity = ecentricity[i];
        }
        if(ecentricity[i] == minEcentricity) center1 = i;
    }
    printf("Center of Graph is = %d",center);

}

