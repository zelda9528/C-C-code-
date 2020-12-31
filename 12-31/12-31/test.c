#define _CRT_SECURE_NO_WARNINGS 1

typedef struct {
	int front;  //����Ԫ��
	int rear;   //��βԪ�ص���һ��λ��
	int size;      //��ЧԪ�ظ���
	int* data;  //���Ԫ�ص������ռ���׵�ַ
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->data = (int *)malloc(sizeof(int) * (k + 1));
	cq->size = k;
	cq->front = cq->rear = 0;   //0~k������
	return cq;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
	//�ж�ѭ����������������(rear+1)%�ռ䳤��==front d
	return (obj->rear + 1) % (obj->size + 1) == obj->front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(obj))       //�������������޷����
		return false;
	//��β���
	obj->data[obj->rear++] = value;
	//�ж϶�β�Ƿ�Խ��
	if (obj->rear == obj->size + 1)
		obj->rear = 0;
	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	//������Ϊ�գ����ܳ���
	if (myCircularQueueIsEmpty(obj))
		return false;

	obj->front++;

	//�ж϶����Ƿ�Խ��
	if (obj->front == obj->size + 1)
		obj->front = 0;
	return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
		return -1;
	else
		return obj->data[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
		return -1;
	//��βԪ����rear������ǰһ��λ�ã����rearΪ0��
	//���βԪ������������һ��λ��
	if (obj->rear == 0)
		return obj->data[obj->size];
	else
		return obj->data[obj->rear - 1];
}



void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->data);
	free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/