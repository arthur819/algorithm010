#define MAX_LEN 10000
bool isValid(char * s){
	char stack[MAX_LEN];
	int top = 0, iterator = 1;

	if (s[0] == '\0')
		return true;

	stack[top++] = s[0];
	while (s[iterator] != '\0') {
		switch (s[iterator]) {
		case '(':
		case '[':
		case '{':
			stack[top++] = s[iterator];
			break;
		case ')':
			if (!top || stack[--top] != '(')
				return false;
			break;
		case ']':
			if (!top || stack[--top] != '[')
				return false;
			break;
		case '}':
			if (!top || stack[--top] != '{')
				return false;
			break;
		}
		++iterator;
	}
	return top == 0;
}
