#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct Node* headlist;
struct Student {
	char name[20];
	int num;
	char sex[20];
};
struct Node {
	struct Student data;
	struct Node* next;
};
struct Node* createheadlist() {//����ͷ�ڵ�
	struct Node* headnode = (struct Node*)malloc(sizeof(struct Node));
	headnode->next = NULL;
	return headnode;
}
struct Node* createnewnode(struct Student data){
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = data;

	newnode->next = NULL;
	return newnode;
}
void inisertnode(struct Node* headlist, struct Student data) {
	struct Node* newnode = createnewnode(data);
	newnode->next = headlist->next;
	headlist->next = newnode;
}
void print(struct Node* headlist) {
	struct Node* temp= headlist->next;
	while (temp!= NULL)
	{
		printf("����\tѧ��\t�Ա�\t\n");
		printf("%s\t%d\t%s\t\n", temp->data.name, temp->data.num, temp->data.sex);
		//printf("%d\t",temp->data);

			temp = temp->next;
	}

}
void menu() {
	printf("********��ӭ����ѧ������ϵͳ*******\n");
	printf("********  1.����ѧ����Ϣ    *******\n");
	printf("********  2.��ӡѧ����Ϣ    *******\n");
}
int main() {
	headlist = createheadlist();
	int input = 0;
	while (1)
	{
		menu();
		printf("����������ѡ��ı��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������ѧ������������ţ��Ա� >");
			/*scanf("%s",student1.name);
			scanf("%s",student1.sex);
			scanf("%d",student1.num);*/
			struct Student student1;
			scanf("%s%d%s", &student1.name, &student1.num, &student1.sex);
			inisertnode(headlist, student1);
			break;
		case 2:
			print(headlist);
			break;
		default:
			break;
		}
	}
	return 0;
}