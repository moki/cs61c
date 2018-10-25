#include <stdio.h>
#include <stdint.h>

#define TORTOISE_STEP (1)
#define HARE_STEP (2)

typedef struct node {
	int value;
	struct node *next;
} node;

extern int ll_has_cycle(node *head);

static struct node *cycle(struct node* node, uint32_t depth);
static void test_ll_has_cycle(void);


int main(void) {
  test_ll_has_cycle();
  return 0;
}

extern int ll_has_cycle(node *head) {
	if (!head) return 0;

	struct node *tortoise = cycle(head, TORTOISE_STEP);
	if (!tortoise) return 0;

	struct node *hare = cycle(head, HARE_STEP);
	if (!hare) return 0;

	while (tortoise != hare) {
		tortoise = cycle(tortoise, TORTOISE_STEP);
		hare = cycle(hare, HARE_STEP);
	}

	return tortoise && hare;
}

static void test_ll_has_cycle(void) {
	node nodes[25]; //enough to run our tests
	int i;

	for(i=0; i < sizeof(nodes)/sizeof(node); i++) {
		nodes[i].next = 0;
		nodes[i].value = 0;
	}

	nodes[0].next = &nodes[1];
	nodes[1].next = &nodes[2];
	nodes[2].next = &nodes[3];
	printf("Checking first list for cycles. There should be none, ll_has_cycle says it has %s cycle\n", ll_has_cycle(&nodes[0])?"a":"no");

	nodes[4].next = &nodes[5];
	nodes[5].next = &nodes[6];
	nodes[6].next = &nodes[7];
	nodes[7].next = &nodes[8];
	nodes[8].next = &nodes[9];
	nodes[9].next = &nodes[10];
	nodes[10].next = &nodes[4];
	printf("Checking second list for cycles. There should be a cycle, ll_has_cycle says it has %s cycle\n", ll_has_cycle(&nodes[4])?"a":"no");

	nodes[11].next = &nodes[12];
	nodes[12].next = &nodes[13];
	nodes[13].next = &nodes[14];
	nodes[14].next = &nodes[15];
	nodes[15].next = &nodes[16];
	nodes[16].next = &nodes[17];
	nodes[17].next = &nodes[14];
	printf("Checking third list for cycles. There should be a cycle, ll_has_cycle says it has %s cycle\n", ll_has_cycle(&nodes[11])?"a":"no");

	nodes[18].next = &nodes[18];
	printf("Checking fourth list for cycles. There should be a cycle, ll_has_cycle says it has %s cycle\n", ll_has_cycle(&nodes[18])?"a":"no");

	nodes[19].next = &nodes[20];
	nodes[20].next = &nodes[21];
	nodes[21].next = &nodes[22];
	nodes[22].next = &nodes[23];
	printf("Checking fifth list for cycles. There should be none, ll_has_cycle says it has %s cycle\n", ll_has_cycle(&nodes[19])?"a":"no");

	printf("Checking length-zero list for cycles. There should be none, ll_has_cycle says it has %s cycle\n", ll_has_cycle(NULL)?"a":"no");
}

static struct node *cycle(struct node* node, uint32_t depth) {
	if (!node) return NULL;
	struct node *cursor = node;

	while (cursor && depth--) {
		cursor = cursor->next;
	}

	return cursor;
}