#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct list
{
	int field;
	struct list* next;
};

void add(struct list* head, int t) {
	while ((head->next) != NULL) {
		head = head->next;
	}
	struct list* temp = (struct list*)malloc(sizeof(list*));
	head->next = temp;
	temp->field = t;
	temp->next = NULL;
}

struct list* pos(list* head, int i, int n) {
	list* h = head;
	for (int j = 0; j < n; ++j) {
		if (j == i)
			return h;
		h = h->next;
	}
	return h;
}

void print_list(list* head) {
	struct list* p = head;
	while (p != NULL) {
		printf("%5d ", p->field);
		p = p->next;
	}
}

int count(list* head) {
	int c = 0;
	while (head) {
		c++;
		head = head->next;
	}
	return(c);
}


void InsertionSort(list* head){
	//int c = count(head);
	int nl, l;
	list* h = head;
	list* h1 = head;
	list* h2 = head;
	/*for (int i = 1; i < c; ++i) {
		h = pos(head, i, c);
		nl = h->field;
		l = i - 1;
		h = pos(head, l, c);
		while ((l >= 0) && (h->field > nl)){
			int temp;
			temp = h->field;
			h = h->next;
			h->field = temp;
			l = l - 1;
			h = pos(head, l, c);
		}
		h = pos(head, l+1, c);
		h->field = nl;
		printf("\nПосле %d итерации: ", i);
		print_list(head);
	}*/
	int i = 1;
	h2 = h->next;
	while (h2) {
		h = h2;
		nl = h->field;
		h1 = head;
		while (h1->next != h2) {
			h1 = h1->next;
		}
		h = h1;
		l = i-1;
		while ((l >= 0) && (h->field > nl)) {
			int temp;
			temp = h->field;
			h = h->next;
			h->field = temp;
			l = l - 1;
			h1 = head;
			while (h1->next != h) {
				h1 = h1->next;
			}
			h = h1;
			if (l>=0){
				h = head;
				while (h->next != h1) {
					h = h->next;
				}
				if (h->field <= nl) {
					h = h1;
				}
			}
		}
		h->field = nl;
		printf("\nПосле %d итерации: ", i);
		print_list(head);
		i++;
		h = h2;
		h2 = h->next;
	}
}




int main() {
	setlocale(LC_ALL, "Rus");
	int n, i, t;
	struct list* head = NULL;
	FILE* fp;
	fp = fopen("Text.txt", "r");
	fscanf(fp, "%d", &n);
	for (i = 0; i < n; ++i) {
		if (i == 0) {
			struct list* temp = (struct list*)malloc(sizeof(list*));
			fscanf(fp, "%d", &temp->field);
			temp->next = head;
			head = temp;
		}
		else {
			fscanf(fp, "%d", &t);
			add(head, t);
		}
	}
	printf("Список до сортировки: ");
	print_list(head);
	int c = count(head);
	InsertionSort(head);
	printf("\n\nСписок после сортировки: ");
	print_list(head);
	printf("\n");
	fclose(fp);
}
