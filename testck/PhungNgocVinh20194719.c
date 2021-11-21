#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct nk{
	char diadiem[40];
	int h;
	int m;
}elementtype;

typedef struct linkedlist{
	elementtype data;
	struct linkedlist *next;
}*node;

node head = NULL;
node creatNode(elementtype value) //Tạo node
{
    node tmp;
    tmp = (node)malloc(sizeof(struct linkedlist));
    strcpy(tmp->data.diadiem, value.diadiem);
    tmp->data.h = value.h;
    tmp->data.m = value.m;
    tmp->next = NULL;
    return tmp;
}

node insert(node head, elementtype value)
{
    if(head == NULL)
    {
        head = creatNode(value);
    }
    else
    {
        node tmp = head;
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = creatNode(value);
    }
    return head;
}

void clearBuffer()
{
    char c;
    c = getchar();
}

int n=0;
void docFile(){
	FILE *fp = fopen("log.txt","r");
	elementtype a;
	
	if(fp == NULL){
		printf("File khong ton tai.\n");
		exit(0);
	}
	else{
		
		while(fscanf(fp, "%s %d %d", a.diadiem, &a.h,&a.m) != EOF)
            {
                //printf("%s %d\n", a.may, a.sl);
                head = insert(head, a);
                //printf("%s %d\n", head->next->data.may, head->next->data.sl);
            }
	}
}

node search(node head)
{
	int i;
    for(i = 0; i <11; i++)
    {
        head = head->next;
    }
    return head;
}

void xoa(node head)
{
    if(head == NULL)return;
    xoa(head->next);
    free(head);
}
void case1(){
	docFile();
}

void case2(){
	printf("%-50s%-10s%-10s\n","Dia diem","Gio","Phut");
	node tmp = head;
	while(tmp!=NULL){
		printf("%-50s%-10d%-10d\n",tmp->data.diadiem,tmp->data.h,tmp->data.m);
		tmp = tmp->next;
	}
}

void case3(){
	char nhap[40];
	int count = 0;
	printf("Nhap vao mot dia diem: ");
	scanf("%s",nhap);
	node tmp = head;
	while(tmp->next != NULL){
		if(strcmp(tmp->data.diadiem,nhap) == 0){
			count = count+1;
			printf("%d:%d,",tmp->data.h,tmp->data.m);
			tmp = tmp->next;
		}
		else tmp = tmp->next;
	}
	if(count == 0) printf("Ban chua den dia diem nay.\n");
	
}

void case4(){
	int gio,phut;
	printf("Nhap gio: ");
	scanf("%d",&gio);
	printf("Nhap phut: ");
	scanf("%d",&phut);
	while(gio < 0 || gio >23 || phut < 0 || phut > 59){
		printf("Nhap khong dung yeu cau: \n");
		printf("Nhap gio: ");
		scanf("%d",&gio);
		printf("Nhap phut: ");
		scanf("%d",&phut);
	}
	node tmp = head;
	int count = 0;
	while(tmp->next != NULL){
		if(tmp->data.h == gio && tmp->data.m == phut){
			count = count+1;
			printf("%s,",tmp->data.diadiem);
			tmp = tmp->next;
		}
		else tmp = tmp->next;
	}
	if(count == 0) printf("Khong tim thay lich su di chuyen.\n");
}

void case5(){
	char dd[40];
	int g,p;
	printf("Nhap thong tin di chuyen cua benh nhan covid: \n");
	printf("Dia diem: ");
	scanf("%s",dd);
	int count = 0;
	node tmp = head;
	while(tmp->next != NULL){
		if(strcmp(tmp->data.diadiem,dd) == 0){
			count = count+1;
			tmp = tmp->next;
		}
		else tmp = tmp->next;
	}
	if(count == 0) printf("Lich su di chuyen cua ban OK.\n");
	
//	else{
//		printf("Thoi gian: ");
//		scanf("%d%d",&g,&p);
////		clearBuffer();
//		while(g < 0 || g >23 || p< 0 || p> 59){
//			printf("Nhap khong dung yeu cau: \n");
//			printf("Nhap gio: ");
//			scanf("%d",&g);
//			printf("Nhap phut: ");
//			scanf("%d",&p);
//		}
//		node tmp1;
//		int m = 0;
//		while(tmp1->next != NULL){
//			if(strcmp(tmp1->data.diadiem,dd) == 0){
//				if(g > tmp1->data.h) m = m+1;
//				tmp1 = tmp1->next;
//			}
//			else tmp1 = tmp1->next;
//		}
//		if(m == 0) printf("Ban co kha nang bi covid,can phai khai bao y te.\n");
//		else printf("Lich su di chuyen cua ban OK.\n");
//	}
}
void menu()
{
    while(1)
    {
        printf("\n====================\n");
        printf("CHUONG TRINH TRUY VET COVID19\n");
        printf("1. Nap file lich su di chuyen\n");
        printf("2. In ra lich su di chuyen\n");
        printf("3. Tim kiem lich su theo dia diem\n");
        printf("4. Tim kiem dia diem theo thoi gian\n");
        printf("5. Kiem tra truy vet moi nhat\n");
        printf("6. Thoat\n");
        printf("====================\n");
        int x;
        printf("Ban chon: ");
        scanf("%d", &x);
        clearBuffer();
        switch(x)
        {
        case 1:
            case1();
            break;
        case 2:
            case2();
            break;
        case 3:
            case3();
            break;
        case 4:
            case4();
            break;
        case 5:
            case5();
            break;
        case 6:
        	xoa(head);
        	exit(0);
        	break;
        default:
            printf("Sai chuc nang! Moi nhap lai:");
        }
    }
}

int main(){
	menu();
	return 0;
}

//Phung Ngoc Vinh MSSV 20194719
