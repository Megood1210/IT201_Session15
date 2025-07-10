#include <stdio.h>
#define MAX 100

// Khai báo cấu trúc của một Queue
typedef struct Queue {
    int data[MAX];
    int front, rear;
    int capacity;
} Queue;

// Khởi tạo Queue
void initialQueue(Queue *q, int size){
    q->front = 0;
    q->rear = -1;
    q->capacity = size;
}

// Kiểm tra hàng đợi có rỗng không?
int isEmpty(Queue *q){
    return q->front > q->rear;
}

// Kiểm tra xem hàng đợi dã đầy chưa
int isFull(Queue *q) {
    return q->rear == q->capacity - 1;
}

// Thêm phần tử vào hàng đợi
void enqueue(Queue *q, int value){
    // Kiểm tra xem hàng đợi đã đầy chưa
    if (isFull(q)){
        printf("Hang doi da day!");
        return;
    }

    q->rear++;
    q->data[q->rear] = value;
}
// Hiển thị toàn bộ hàng đợi
void printQueue(Queue *q){
    if (isEmpty(q)){
        printf("Hang doi rong!");
        return;
    }

    // Duyệt
    printf("Hang doi: \n ");
    for (int i = q->front; i <= q->rear ; i++) {
        printf("%d ", q->data[i]);
    }
}
// Hàm nhập từ người dùng và thêm vào hàng đợi
void addQueue(Queue *q){
    int value;
    printf("\nNhap so nguyen bat ki: ");
    scanf("%d", &value);
    enqueue(q, value);
}
int main() {
    Queue q;
    int size;
    // Nhập số lượng phần tử tối đa trong hàng đợi
    printf("Nhap so phan tu trong hang doi: ");
    scanf("%d", &size);
    // Kiểm tra số lượng phần tử tối đa
    if ( size > MAX){
        printf("queue is full");
        return 1;
    }
    // Khởi tạo hàng đợi
    initialQueue(&q, size);
    // Nhập vào số nguyên bất kỳ
    for (int i = 0; i < 5; i++){
        printf("Nhap so thu %d: ", i + 1);
        addQueue(&q);
    }
    // In kết quả
    printQueue(&q);

    return 0;
}
