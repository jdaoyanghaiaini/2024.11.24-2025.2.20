#include"Stack.h"
int main()
{
	ST ps;
	STInit(&ps);
	STPush(&ps, 1);
	STPush(&ps, 2);
	STPush(&ps, 3);
	STPush(&ps, 4);
	STSize(&ps);
	while (!STEmpty(&ps))
	{
		printf("%d ", ps.a[ps.top - 1]);
		ps.top--;
	}
	STDestroy(&ps);
}