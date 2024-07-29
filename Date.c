#include <stdio.h>
struct date
{
	int d, m ,y;
};
int main()
{
	struct date Date;
	
	scanf("%d", &Date.d);
	scanf("%d", &Date.m);
	scanf("%d", &Date.y);
	
	printf("%d - ", Date.d);
	printf("%d - ", Date.m);
	printf("%d \n", Date.y);
	
	return 0;
}
