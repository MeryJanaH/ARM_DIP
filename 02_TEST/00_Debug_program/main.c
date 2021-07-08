
int Global_variable = 5;

int add (int,int);
int sub (int,int);

int main(void)
{
	int main_local_variable = 0;
	Global_variable++;
	
	main_local_variable = add(5,6);
	main_local_variable = sub(6,5);
}

int add(int x,int y)
{
	int add_local_variable = 0;
	add_local_variable = x+y;
	return add_local_variable;
}

int sub(int x,int y)
{
	int sub_local_variable = 0;
	sub_local_variable = x-y;
	return sub_local_variable;
}