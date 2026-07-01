#include <stdio.h>
void main(){
    int adj[5][5] = {{0,1,1,0,0},{1,0,1,1,0},{1,1,0,0,1},{1,0,0,0,1},{0,0,1,1,0}};
    int sum = 0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            sum+=adj[i][j];
        }
        if(sum==1){
            printf("%d vertex is pendent\n",i);
        }
        else{
            printf("Degree of %d vertex is %d\n",i,sum);
        }
    }
}