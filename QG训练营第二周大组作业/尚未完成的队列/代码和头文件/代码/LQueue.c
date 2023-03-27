#define _CRT_SECURE_NO_WARNINGS 1
#include "LQueue.h" 
extern char type;
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q) {
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue* Q) {
	Node* p = (Node*)malloc(sizeof(Node));
	p = Q->front;
	while (p != NULL)
	{
		Q->front = Q->front->next;
		free(p);
		p = Q->front;
	}
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* Q) {
	if (Q->front == Q->rear)
		return TRUE;
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue* Q, void* e) {
	if (IsEmptyLQueue(Q)) 		
		return FALSE;
	else {
		e = Q->front->next->data;
		return TRUE;
	}
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue* Q) {
	Node* p = (Node*)malloc(sizeof(Node));
	int i = 0;
	p = Q->front->next;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	if (p == Q->length)
		return 1;
	else
		return 0;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue* Q, void* data) {
	if (IsEmptyLQueue(Q)) 
		return FALSE;
	else {
		Node* p = (Node*)malloc(sizeof(Node));
		p->data = data;
		Q->rear->next = p;
		Q->rear = p->next;
		Q->length++;
		return TRUE;
	}
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q) {
	if (IsEmptyLQueue(Q)) 
		return FALSE;
	else {
		Node* p = (Node*)malloc(sizeof(Node));
		p = Q->front->next;
		Q->front->next =p->next;
		free(p);
		return TRUE;
	}
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue* Q) {
	Node* p = (Node*)malloc(sizeof(Node));
	p = Q->front;
	while (p->next != NULL)
	{
		Q->front = Q->front->next;
		free(p);
		p = Q->front;
	}
	Q->front->data = 0;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {
	Node* p = (Node*)malloc(sizeof(Node));
	p = Q->front->next;
	foo = LPrint;
	while (p != NULL);
	{
		foo(p->data);
		p = p->next;
	}
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
void LPrint(void* q) {
	if (type == 'i')
		printf("%d",q);
	else if (type == 'f')
		printf("%fl",q);
	else if (type == 'c')
		printf("%s",q);

}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/

