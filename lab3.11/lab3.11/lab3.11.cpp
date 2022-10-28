#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

void insert(); //��������
void del(); // �������
void display(); //����������
struct node{
	int priority;
	int info;
	struct node *link;
}*front = NULL;

int main(){
	setlocale(LC_ALL, "Rus");
	int choice;
	
	while(1){
		printf("\n\n--------------------------- ���� -------------------------------------\n\n");
		printf("1.��������.\n\n");
		printf("2.�������.\n\n");
		printf("3.����������.\n\n");
		printf("4.�����.\n\n");
		printf("�������� : ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				insert();
				break;
			case 2:
				del();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
			default :
				printf("�����, ������ ���...\n");
		}
	}
}

void insert(){
	setlocale(LC_ALL, "Rus");
	struct node *tmp,*q;
	int added_item,item_priority;
	tmp = (struct node *)malloc(sizeof(struct node));
	printf("\n------------------------------------------------------------------------------\n");
	printf("\n�������� �������� � ������� : ");
	scanf("%d",&added_item);
	printf("\n\n������ ��������� : ");
	scanf("%d",&item_priority);
	printf("\n\n------------------------------------------------------------------------------\n");
	tmp->info = added_item;
	tmp->priority = item_priority;
	if( front == NULL || item_priority < front->priority ){
		tmp->link = front;
		front = tmp;
	}
	else{
		q = front;
		while( q->link != NULL && q->link->priority <= item_priority ) q=q->link;
		tmp->link = q->link;
		q->link = tmp;
	}
}

void del(){
	struct node *tmp;
	if(front == NULL){
		printf("\n--------------------------------------------------------------------");
		printf("\n\n������������� ����� ��������\n");
		printf("\n------------------------------------------------------------------------");
	}
	else{
		tmp = front;
		printf("\n----------------------------------------------------------------------------\n");
		printf("\n\n������� ������� %d\n",tmp->info);
		printf("\n-----------------------------------------------------------------------------\n\n");
		front = front->link;
	free(tmp);
	}
}

void display(){
	setlocale(LC_ALL, "Rus");
	struct node *ptr;
	ptr = front;
	if(front == NULL){
		printf("\n-----------------------------------------------------------------------");
		printf("\n\n������� �����\n");
		printf("\n--------------------------------------------------------------------------");
	}
	else{
		printf("\n\n---------------------- ������� --------------------------------\n\n");
		printf("���������\t�������\n\n");
		while(ptr != NULL){
			printf("%d \t\t%d\n\n",ptr->priority,ptr->info);
			ptr = ptr->link;
		}
	}
}