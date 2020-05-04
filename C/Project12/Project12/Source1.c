#include <stdio.h>

void fun1(int num1,int* num2);
void fun2(int arr1, int arr2);
void fun3(int* arr1, int* arr2);
void fun4(int *arr1, int *arr2);

void main()
{
	int num = 10;
	int arr[5] = { 1,2,3,4,5 };

	fun1(num,&num);//0,1

	fun2(arr[2], arr[4]);//0,0

	fun3(&arr[1], &arr[3]);//1,1

	fun4(arr, arr + 3);//1,1

	
}

void  fun1(int num, int* num2)
{

}
void fun2(int arr1, int arr2)
{

}
void fun3(int* arr1, int* arr2)
{

}
void fun4(int *arr1, int *arr2)
{

}