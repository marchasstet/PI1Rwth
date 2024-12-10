/*
 * Versuch02.cpp
 *
 *  Created on: 16.04.2024
 *      Author: marcd
 */
#include<iostream>
#include<string>

int iRekFibonacci(int z,int x=1, int y=1,int i=0);
int iItFibonacci(unsigned int x);
int iiRekFibonacci(int x, int y,int z);
int main() {
	int x = iRekFibonacci(7);
	//std::cout << x << std::endl;
	unsigned int y = iItFibonacci(7);
	std::cout << x << std::endl;
	std::cout << y << std::endl;

	return 0;

}
int iRekFibonacci(int z,int x, int y,int i) {//z=wei vielte Zahl, x=0 fib(0)=0 , y=1 fib(1)=1,i=0 iterator falls fkt nicht einen gibt
	int h = 0;
	h=x;
	int j = y;

	h = x + y;
	if (i >= z) {
		return x;
	} else {
		i++;
		int b = iRekFibonacci(z,j, h, i);

		return b;
	}
}
int iiRekFibonacci(int x, int y,int z) {
	int h=x;
	int j=y;

	h=x+y;
	if(y>=z) {
		return x;
	}
	else {

		int b= iiRekFibonacci(j,h,z);

		return b;
	}
}
int iItFibonacci(unsigned int x) {
	unsigned int i=1;
	unsigned int y=0;
	unsigned int z=1;
 while (i<=x){
	 unsigned int n=0;
	 i++;
	 n=y;
	 y=z;
	 z=n+z;
 }
 return z;
}
//ab 47 error weil die zal zu groß ist unsinged sollte es beheben
