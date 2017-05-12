struct node{
	int val;
	struct node* next;
};

int length(struct node*);
void print(struct node*, int);

void push(struct node**, int);
void append(struct node**, int);
