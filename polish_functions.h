int ctr = 0;

//function that checks if end of string is reached, returns true if it is, else, false
bool EOS(char str){
	return str == '\0';
}

//function that checks if the current string is an operand or not, returns true if it is, otherwise false
bool IsOpnd(char *x){
	if(isalpha(*x)){
		return true;
	}else{
		return false;
	}
}

//function that returns the next token in the string
char *NEXTTOKEN(char str[]){
	static char token[4];
	memset(token, 0, sizeof(char)*4);
	int i=0;

	while(str[ctr] != ' '){		
		token[i] = str[ctr];
		if(token[i] == '(' || token[i] == ')'){
			return token;
		}

		if(str[ctr+1] == ')' && IsOpnd(token) ){
				i++;
				token[i] = ' ';
				return token;
		}
		i++;
		ctr++;
		token[i] = str[ctr];
	}
	return token;
}

//function that returns in-coming priority of token x
int ICP (char *x[]){

	if (strstr(*x,"+") != NULL || strstr(*x,"-") != NULL ){
		return 1;
	}

	if (strstr(*x,"<") != NULL || strstr(*x,">") != NULL || strstr(*x,"<=") != NULL || strstr(*x,">=") != NULL ){
		return 1;
	}

	if (strstr(*x,"!=") != NULL || strstr(*x,"==") ){
		return 1;
	}

	if (strstr(*x,"&") != NULL || strstr(*x,"|") ){
		return 1;
	}

	if (strstr(*x,"*") != NULL || strstr(*x,"/") != NULL ||  strstr(*x,"%") != NULL ){
		return 3;
	}

	if (strstr(*x,"^") != NULL ){
		return 6;
	}

	if (strstr(*x,"!") != NULL ){
		return 8;
	}
}

//function that returns in-stack priority of token x
int ISP (char *x[]){

	if (strstr(*x,"(") != NULL ){
		return 0;
	}

	if (strstr(*x,"+") != NULL || strstr(*x,"-") != NULL ){
		return 2;
	}

	if (strstr(*x,"<") != NULL || strstr(*x,">") != NULL || strstr(*x,"<=")  != NULL || strstr(*x,">=")  != NULL ){
		return 2;
	}

	if (strstr(*x,"!=") != NULL || strstr(*x,"==") ){
		return 2;
	}

	if (strstr(*x,"&") != NULL || strstr(*x,"|") ){
		return 2;
	}

	if (strstr(*x,"*") != NULL || strstr(*x,"/") != NULL ||  strstr(*x,"%") != NULL ){
		return 4;
	}

	if (strstr(*x,"^") != NULL ){
		return 5;
	}

	if (strstr(*x,"!")  != NULL ){
		return 7;
	}

}

//function that returns rank of token x
unsigned int RANK(char *x[]){
	if (IsOpnd(*x)){
		return 1;
	} else {
		return -1;
	}
}

//function that determines the rank of the generated postfix expression 
void FINDRANK(char postfix[], int r){
	r = 0;
	int i=0;
	char *x;

	ctr = 0;

	while(!EOS(postfix[ctr])) {
		x = NEXTTOKEN(postfix);
		r = r + RANK(&x);
		if (r < 1) return;

		ctr++;
	}
}

//function that generates the postfix expression in the string 'postfix'
void POLISH(char infix[], char postfix[], int r){
	Stack S;
	InitStack(&S);

	char *x, xtop[4];

	postfix[0] = '\0';
	
	while(!EOS(infix[ctr])){
		x = NEXTTOKEN(infix);
		if(IsOpnd(x)){
			strcat(postfix, x);
		}else if (*x == '('){
			PUSH(&S, x);
		}else if (*x == ')'){
			while(!IsEmptyStack(&S)){
				strcpy(xtop, S.top->INFO);
				POP(&S,S.top->INFO);
				if(*xtop != '('){
					strcat(postfix, xtop);
				} else if (IsEmptyStack(&S)) {
					FINDRANK(postfix, r);
					return;
				} else {
					break;
				}
			}
		}else{
			while (!IsEmptyStack(&S)) {
				strcpy(xtop, S.top->INFO);
				POP(&S,S.top->INFO);
				char *xTop = xtop;

				if (ICP(&x) < ISP(&xTop)) {
					strcat(postfix, xtop);
				} else {
					PUSH(&S, xtop);
					PUSH(&S, x);
					break;
				}
			}
		}
		ctr++;
	}
	r = 0;
}

//function that formats the input string to parenthesized infix expression
void FORMAT(char infix[], char input[]){
	int size = strlen(input);
	int i = 0, j = size - 1;
	char x[2]={')','\0'};

	if(input[0] != '(' || input[j] != ')'){
		infix[0] = '(';
		strcat(infix, input);
		infix[j] = '\0';
		strcat(infix, x);
	}
}

