#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int fac(int n){return n>1?n*fac(n-1):1;}

int main()
try {
	unsigned long long int szam=fac(20);
	cout<<szam<<endl;
	
	
	
	
	return 0;
	

} catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	return 1;
	
} catch (...) {
	cerr << "exception\n";
	return 2;
	
}
