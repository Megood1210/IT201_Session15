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
        printf("Hang doi rong");
        return -1;
    }

    return q->data[q->front];
}
// Hàm kiểm tra xem dãy này có phải là dãy tăng dần đều 1 đơn vị giữa các phần tử hay không
int isIncrease(Queue *q){
    // Duyệt
    for (int i = q->front; i < q->rear; i++){
        // Kiểm phần tử phần tử sau không bằng phần tử hiện tại + 1
        if (q->data[i + 1] != q->data[i] + 1){
            return 0; // Không phải là dãy tăng dần đều 1 đơn vị giữa các phần tử
        }
    }
    return 1; // Là dãy tăng dần đều 1 đơn vị giữa các phần tử
}
int main(){
    Queue q;
    initialQueue(&q);
    // Nhập số phần tử trong hàng đợi
    int n, value;
    printf(" ");
    scanf("%d", &n);\
    // Lưu tất cả phần tử
    for (int i = 0; i < n; i++){
        scanf("%d", &value);
        enqueue(&q, value);
    }
    // In kết quả
    if (isIncrease(&q)){
        printf("True\n");
    }else{
        printf("False\n");
    }
    return 0;
}
