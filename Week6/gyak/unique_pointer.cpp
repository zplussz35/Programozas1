#include"std_lib_facilities.h"

void suspicious(int s,int x)
{
	int* p= new int[s];
    if(x==0) throw exception();
    
    

	delete[] p;
}

int main()
try{
	suspicious(5,1); 


	return 0;
} catch(...){
	cerr<<"Error: "<<endl;
    return 1;
}
