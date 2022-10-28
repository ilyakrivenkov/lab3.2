#include<stdio.h>   
#include<stdlib.h>  
#include <locale.h>

struct node   
{  
    int data;   
    struct node *next;  
}; 
void insert();  
void del();  
void display(); 
struct node *front;  
struct node *rear;   
  

void main ()  {  	
	setlocale(LC_ALL, "Rus");
    int choice = 1;   
    while(choice != 4)   
    {     
        printf("\n************************* ���� *****************************\n");  
        printf("\n=================================================================\n");  
        printf("\n1.�������� �������\n2.������� �������\n3.������� �������\n4.�����\n");  
        printf("\n������� ��� �����: ");  
        scanf("%d",& choice);  
        switch(choice)  
        {  
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
            exit(0);  
            break;  
            default:   
            printf("\n�����, ������ ���...\n");  
        }  
    }  
}  
void insert()  {	
	setlocale(LC_ALL, "Rus");
    struct node *ptr;  
    int item;   
      
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  {  
        printf("\n������������\n");  
        return;  
    }  
    else  {   
        printf("\n������� ��������\n");  
        scanf("%d",&item);  
        ptr -> data = item;  
        if(front == NULL)  {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }  
    }  
}     
void del ()  {  	
	setlocale(LC_ALL, "Rus");
    struct node *ptr;  
    if(front == NULL)  
    {  
        printf("\n������������� �����\n");  
        return;  
    }  
    else   
    {  
        ptr = front;  
        front = front -> next;  
        free(ptr);  
    }  
}  
void display()  
{  	
	setlocale(LC_ALL, "Rus");
    struct node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\n������� �����\n");  
    }  
    else  
    {   printf("\n����� �������� .....\n");  
        while(ptr != NULL)   
        {  
            printf("\n%d\n",ptr -> data);  
            ptr = ptr -> next;  
        }  
    }  
}  