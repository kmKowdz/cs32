typedef char StackElemType;
typedef struct stacknode StackNode;

struct stacknode{
	StackElemType INFO[4];
	StackNode *LINK;
};

struct stack{
	StackNode *top;
};

typedef struct stack Stack;

void InitStack(Stack *S){
	S->top = NULL;
}

int IsEmptyStack(Stack *S){
	return (S->top == NULL);
}

void StackOverflow(void){
	printf("Stack overflow detected. \n");
	exit(1);
}

void StackUnderflow(void){
	printf("Stack underflow detected. \n");
	exit(1);
}

void PUSH(Stack *S, StackElemType k[]){
	StackNode *alpha;
	alpha = (StackNode *)malloc(sizeof(StackNode));
	if(alpha == NULL)
		StackOverflow();
	else{
		strcpy(alpha->INFO, k);
		alpha->LINK = S->top;
		S->top = alpha;
	}
}

void POP(Stack *S, StackElemType k[]){
	StackNode *alpha;
	if(S->top == NULL){
		StackUnderflow();
	}else{
		alpha = S->top;
		S->top = S->top->LINK;
		free(alpha);
	}
}
