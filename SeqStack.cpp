#include<stdio.h>
#include<stdlib.h>
//顺序栈的数据结构
typedef int DataType;
struct Stack
{
	int top; //栈顶指针，指向栈顶元素的下标
	int maxsize; //顺序栈的最大空间
	DataType* elements; //存放顺序栈的栈元素
};
typedef struct Stack SeqStack;
//创建一个空的数据栈
void InitStack(SeqStack *s, int maxsize) {
	s->maxsize = maxsize;
	s->top = -1;//top指栈顶元素的下标
	s->elements = new DataType[maxsize];
}
//判断是否为空
int IsEmpty(SeqStack *s) {
	return s->top == -1;
}
//判断是否为满
int IsFull(SeqStack *s) {
	return s->top == s->maxsize - 1;
}
//入栈
int Push(SeqStack *s, DataType val) {
	if (IsFull(s))
		return 0;
	s->top++;
	s->elements[s->top] = val;
	return 1;
}
//出栈
int pop(SeqStack *s, DataType *e){
	if (IsEmpty(s))
		return  0;
	*e = s->elements[s->top];
	s->top--;
	return 1;
}
//获取栈顶元素
int Gettop(SeqStack *s,DataType *e) {
	if (IsEmpty(s))
		return 0;
	*e = s->elements[s->top];
	return 1;
}
//释放栈内存
void FreeStack(SeqStack* s) {
	free(s->elements);
	s->elements = NULL;
	s->maxsize = 0;
	s->top = -1;
}
//十进制转换成其他不同进制
void alter(DataType number,DataType base) {
	SeqStack m;
	DataType h;
	InitStack(&m, 32);
	if (number == 0) {
		printf("转换结果:0\n");
		FreeStack(&m);
		return;
	}
	while (number > 0) {
		Push(&m, number % base);
		number = number / base;
	}
	printf("转换进制base=%d", base);
	while (!(IsEmpty(&m))) {
		pop(&m, &h);
		printf("%d", h);
	}
	printf("\n");
	FreeStack(&m);
}
// 主函数测试
int main(void)
{
	//===== 顺序栈功能测试 =====
	SeqStack s;
	InitStack(&s, 10);
	Push(&s, 10);
	Push(&s, 20);
	Push(&s, 30);
	int val;
	Gettop(&s, &val);
	printf("栈顶元素：%d\n", val);
	pop(&s, &val);
	printf("出栈元素：%d\n", val);
	Gettop(&s, &val);
	printf("新栈顶：%d\n", val);
	if (IsEmpty(&s)) printf("栈为空\n");
	else printf("栈不为空\n");
	if (IsFull(&s)) printf("栈已满\n");
	else printf("栈未满\n");
	FreeStack(&s);
	printf("--------------------------\n");
	//===== 进制转换测试 =====
	alter(13, 2);   //13转二进制 1101
	alter(20, 8);   //20转8进制 24
	alter(56, 9);   //56转9进制 62
	return 0;
}



