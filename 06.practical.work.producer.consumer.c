#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 10

typedef struct product
{
	char type;  // 0=fried chicken, 1=French fries
	int amount; // pieces or weight
	char unit;  // 0=piece, 1=gram
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void initChicken(item *smt) {
	smt->type = 0;
	smt->amount = 0;
	smt->unit = 0;
}

void produce(item *i)
{
	while ((first + 1) % BUFFER_SIZE == last)
	{
		printf("No free buffer item!\n");
		return;
	}
	memcpy(&buffer[first], i, sizeof(item));
	first = (first + 1) % BUFFER_SIZE;
	printf("First = %d\n", first);
}

void consume()
{
	item *i = malloc(sizeof(item));
	while (first == last)
	{
		printf("Nothing to consume!\n");
	}
	memcpy(i, &buffer[last], sizeof(item));
	last = (last + 1) % BUFFER_SIZE;
	printf("Last = %d\n", last);
	return;
}

int main()
{
	/* code */
	int option = 0;
	item *chicken, wing, *french, fries;
	chicken = &wing;
	french = &fries;
	printf("Welcome to fooradise! \n");
	printf("Our menu today: Chicken Wings and French Fries \n");
	printf("Chicken Wings: 1 || French fries: 2 \n");
	while (true)
	{
		/* code */
		scanf("%d", &option);
		if (option == 1)
		{
			printf("2 Chicken Wings coming right up!\n");
			initChicken(chicken);
			produce(chicken);
			initChicken(chicken);
			produce(chicken);
			printf("Consuming...\n");
			consume();
			break;
		}
		else if (option == 2)
		{
			printf("2 French Fries coming right up!\n");
			produce(french);
			produce(french);
			printf("Consuming...\n");
			consume();
			break;
		}
		else
		{
			printf("Try again!\n");
			printf("Chicken Wings: 1 || French fries: 2\n");
		}
	}
	return 0;
}
