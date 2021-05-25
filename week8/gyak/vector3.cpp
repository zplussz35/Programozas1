#include"std_lib_facilities.h"

class My_out_of_range{};

class My_vector{
	int sz;
	double* elem;
	int space;

	void debug(const string& str)
	{
		cerr<<this<<" -> "<<str<<"elem ptr:"<<elem<<endl;
	}

public:
	My_vector(): sz{0},elem{nullptr},space{0}{}
	explicit My_vector(int s): sz(s),elem{new double[s]},space(s)
	{
		for(int i=0;i<s;++i) elem[i]=0;
		//debug("int construcotor");
	}

	My_vector(initializer_list<double>lst): sz(lst.size()),elem{new double[sz]},space(lst.size())
	{
		copy(lst.begin(),lst.end(),elem);
		//debug("lst constructor");  //mettol medddig és hova
	}
	My_vector(const My_vector& arg): sz{arg.sz},elem{new double[sz]},space{arg.sz}
	{
		copy(arg.elem,arg.elem+arg.sz,elem);
		//debug("copy constructor");
	}
	My_vector& operator=(const My_vector& arg)
	{
		if(this==&arg) return *this;  //v=v

		if(arg.sz<=space)
		{
			for(int i=0;i<arg.sz;++i)
				elem[i]=arg.elem[i];
			sz=arg.sz;
			return *this;
		}
		double* p=new double[arg.sz];
		copy(arg.elem,arg.elem+arg.sz,p);
		delete[] elem;
		elem=p;
		sz=arg.sz;
		space=arg.space;
		//debug("assignment constructor");
		return *this;
	}
	My_vector(My_vector&& arg):
	sz{arg.sz},elem{arg.elem},space{arg.space}
	{
		arg.sz=0;
		arg.elem=nullptr;
		//debug("move constructor");
	}
	My_vector& operator=(My_vector&& arg)
	{
		delete[] elem;
		space=arg.space;
		sz=arg.sz;
		elem=arg.elem;
		arg.sz=0;
		arg.elem=nullptr;
		//debug("move assignment");
		return *this;
	}
	
	~My_vector(){/*debug("destructor");*/delete[] elem;}
	int size() const{return sz;}
	int capacity() const{return space;}
	//double get(int i) const {return elem[i];}
	//void set(int i,double val){elem[i]=val;}

	double& operator[](int n){return elem[n];}
	const double& operator[](int n) const {return elem[n];}

	double& at(int n)
	{
		if(n<0||n>=sz) throw My_out_of_range();
		return elem[n];
	}

	const double& at(int n) const
	{
		if(n<0||n>=sz) throw My_out_of_range();
		return elem[n];
	}

	void reserve(int newalloc)
	{
		if(newalloc<=space) return;
		double* p=new double[newalloc];
		for(int i=0;i<sz;++i) p[i]=elem[i];
		delete[] elem;
		elem= p;
		space= newalloc;
	}

	void resize(int newsize)
	{
		reserve(newsize);
		for(int i=sz;i<newsize;++i) elem[i]=0;
		sz=newsize;
	}

	void push_back(double d)
	{
		if(space==0)
			reserve(8);
		else if(sz==space)
			reserve(2*space);
		elem[sz]=d;
		++sz;
	}

};

/*My_vector fill()
{
	My_vector t {10.2,100.3,43.2};
	return t;
}

My_vector glob(10);
*/
int main()
{
	My_vector mv;
	for(int i=0;i<18;++i)
	{
		cout<<mv.capacity()<<endl;
		mv.push_back(8.5);
	}
	cout<<mv.capacity()<<endl;




	for(int i=0;i<mv.size();++i)
		cout<<mv.at(i)<<endl;
	cout<<endl;

	
	return 0;
}
