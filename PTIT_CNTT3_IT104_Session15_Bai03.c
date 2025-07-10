#include <stdio.h>
#define MAX 100

// Khai báo cấu trúc của một Queue
typedef struct Queue {
    int data[MAX];
    int front, rear;
} Queue;

// Khởi tạo Queue
void initialQueue(Queue *q){
    q->front = q->rear = -1; // Đă cả phần front và rear về -1 để biểu thị hàng đợi rỗng
}

// Kiểm tra hàng đợi có rỗng không?
int isEmpty(Queue *q){
    return q->front == -1;
}

// Kiểm tra xem hàng đợi dã đầy chưa
int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

// Thêm phần tử vào hàng đợi
void enqueue(Queue *q, int value){
    // Kiểm tra xem hàng đợi đã đầy chưa
    if (isFull(q)){
        printf("Hang doi da day!");
        return;
    }

    // Trong trường hợp, nếu hàng đợi chưa có gì => Khởi tạo ra front
    if (isEmpty(q)){
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = value; // Thm giá trị vào cuối hàng đợi
}

// Xem phần tử ở đầu hàng đợi
int peek(Queue *q){
    if (isEmpty(q)){
        return -1;
    }

    return q->data[q->front];
}

// Xem phần từ ở đầu hàng đợi và xóa khỏi hàng đợi
int dequeue(Queue *q){
    if (isEmpty(q)){
        printf("Hang doi rong!");
        return -1;
    }

    // Lấy ra giá trị đầu tiên của ngăn xếp
    int frontValue =  q->data[q->front];

    if (q->front == q->rear){
        // Nếu như trong hàng đợi chỉ có phần tử => Reset lại hàng đợi
        q->front = q->rear = -1;
    } else {
        // Nếu nhuw có nhiều phần tử => Dịch front sáng phần tử tiếp tiếp
        q->front++;
    }

    return frontValue;
}

// Hiển thị toàn bộ hàng đợi
void printQueue(Queue *q){
    if (isEmpty(q)){
        printf("Hang doi rong!");
        return;
    }

    // Duyệt
    printf("Cac phan tu co trong hang doi: \n");
    for (int i = q->front; i <= q->rear ; i++) {
        printf("%d ", q->data[i]);
    }
}
int main() {
    Queue q;
    initialQueue(&q); // Khởi tạo hàng đợi

    // Thêm phần tử vào hàng đợi
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    // Kiểm tra hàng đợi rỗng
    if (isEmpty(&q)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}