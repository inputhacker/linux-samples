#include <stdio.h>
#include <unistd.h>

void func1(void);
void func2(void);
void func3(void);
void func4(void);

void func1(void)
{
	func2();
}

void func2(void)
{
	func3();
}

void func3(void)
{
	func4();
}

void func4(void)
{
	close(1);
}

int main()
{
	func1();

	return 0;
}
