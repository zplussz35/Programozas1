#include<iostream>
#include<vector>

using namespace std;


template<typename T>
struct S{
private:
	T _val;
public:
	S(){};
	S(T val):_val{val}{}
	
	T& get();
	T& get() const;
	void set(T);
	T& operator=(const T&);

	void read_val(T&);
};

template<typename T>
T& S<T>::operator=(const T& arg){
	_val=arg;
	return _val;
}
template<typename T>
T& S<T>::get(){
	return _val;
}
template<typename T>
T& S<T>::get() const{
	return _val;
}
template<typename T>
void S<T>::set(T arg){
	_val=arg;
	return;
}
template<typename T> 
void S<T>::read_val(T& v){
	cin>>v;
	return;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v){

		for(int i=0;i<v.size();i++)
		{
			out<<v[i]<<", ";
		}
		return out;
	}
template<typename T>
istream& operator>>(istream& in,vector<T>& v){
		T val;
		while(in>>val)
		{
			v.push_back(val);
		}
		return in;
	}

int main()
{

	//-------------declarations
	int int_value;
	char char_value;
	double double_value;
	string string_value;
	vector<int> vector_value;

	S<int> i;
	S<char> c;
	S<double> d;
	S<string> s;
	S<vector<int>> v;


	//---------------read values
	cout<<"int: ";
	i.read_val(int_value);
	cout<<"char: ";
	c.read_val(char_value);
	cout<<"double: ";
	d.read_val(double_value);
	cout<<"string: ";
	s.read_val(string_value);

	cout<<"Vector elements, please type integers (type 'q' to end):\n";	
	v.read_val(vector_value);

	//-------------Set values
	i.set(int_value);
	c=char_value;
	d=double_value;
	s=string_value;
	v.set(vector_value);

	
	//---------------Output:
	cout<<"\n\n-------\n\nValues:\nint: "<<i.get()<<"\nchar: "<<c.get()<<"\ndouble: "<<d.get()<<"\nstring: "<<s.get()<<endl;
	cout<<"vector elements: ";
	for(int i=0;i<v.get().size();++i)
	{
		cout<<v.get()[i]<<" ";
	}
	cout<<endl;

	return 0;
}