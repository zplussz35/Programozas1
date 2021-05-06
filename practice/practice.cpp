#include<iostream>

using std::cin;
using std::cout;
using std::endl;

class my_vector{
	int sz;
	double* elem;
public:
	my_vector(int size):sz{size},elem{new double[sz]}{
		for(int i=0;i<sz;++i)
		{
			elem[i]=0;
		}
	}
	~my_vector(){
		delete[] elem;
	}
	int size() const {return sz;} 
};

int main()
{	
	my_vector v(10);
	cout<<v.size()<<endl;

	return 0;
}