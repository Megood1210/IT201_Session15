#include <stdio.h>
#define MAX 100

// Khai báo cấu trúc của một Queue
typedef struct Queue {
    int data[MAX];
    int front, rear;
    int capacity; // Số lượng phần tử tối đa
} Queue;

// Khởi tạo Queue
void initialQueue(Queue *q,int size){
    q->front = 0;
    q->rear = -1;
    q->capacity = size;
}

int main(){

    return 0;
}