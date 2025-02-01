#include"Stack.h"
void STInit(ST* ps)
{
	assert(ps);
	ps->a = (ST*)malloc(sizeof(STDateType) * 4);
	assert(ps->a);
	ps->capacity = 4;
	ps->top = 0;
}
void STDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->capacity = 0;
	ps->top = 0;
}
void STPush(ST* ps, STDateType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		ST* tmp = (ST*)realloc(ps->a, sizeof(ps->a) * 2);
		assert(tmp);
		ps = tmp;
		ps->capacity *= 2;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void STPop(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));
	ps->top--;
}
bool STEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}
void STSize(ST* ps)
{
	assert(ps);
	printf("%d ", (ps->top));
}
