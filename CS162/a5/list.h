struct node {
	int val;
	struct node *next;
};

int length(struct node *head);

void push(struct node **head, int i);

void append(struct node **head, int i);

void print(struct node *head, int i);

