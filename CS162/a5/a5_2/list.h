struct node{
	int val;
	struct node* next;
};

int length(struct node*);
void print(struct node*);

struct node* push(struct node*, int);
struct node* append(struct node*, int);

struct node* clear(struct node*);
//struct node* remove(struct node*, int);
struct node* sort_ascending(struct node*);
struct node* sort_descending(struct node*);

struct node* insert_middle(struct node*, int, int);
