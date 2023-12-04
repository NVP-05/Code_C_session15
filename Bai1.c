#include<stdio.h>
#include<string.h>
struct Student{
		char name[50];
		int age;
		char phone[12];
		char email[50];
	};
int main(){
	struct Student sv1;
	printf("Ten: ");
	gets(sv1.name);
	printf("\nTuoi: ");
	scanf("%d", &sv1.age);
	printf("\nSo dien thoai: ");
	fflush(stdin);
	gets(sv1.phone);
	printf("\nEmail: ");
	fflush(stdin);
	gets(sv1.email);
	printf("\nTen vua nhap danh cho sv1 la: %s", sv1.name);
	printf("\nTuoi vua nhap danh cho sv1 la: %d", sv1.age);
	printf("\nSDT vua nhap danh cho sv1 la: %s", sv1.phone);
	printf("\nEmail vua nhap danh cho sv1 la: %s", sv1.email);
	
	return 0;
}
