#define _CRT_SECURE_NO_WARNINGS 1


bool isValid(char * s)
{

	if (s == NULL || s[0] == '\0') return true;


	char stack[10240];
	int top = 0;
	for (int i = 0; s[i]; ++i)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			stack[top++] = s[i];
		else
		{
			if ((--top)<0)  return false;
			if (s[i] == ')'&&stack[top] != '(')  return false;
			if (s[i] == ']'&&stack[top] != '[')  return false;
			if (s[i] == '}'&&stack[top] != '{')  return false;

		}
	}
	return (top ? true : false);
}


