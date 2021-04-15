#include<iostream>

int adder(int a,int b)
{
	return a+b;
}

int main(int argc,char* argv[]){
	int (*fv_pointer)(int a,int b);
	fv_pointer=adder;

	int result= fv_pointer(10,10);
	int result2= (*fv_pointer)(10,10);

	std::cout<<adder<<std::endl;
	std::cout<<reinterpret_cast<int*>(adder)<<std::endl;
	std::cout<<result<<std::endl;
	std::cout<<result2<<std::endl;

	return 0;
}