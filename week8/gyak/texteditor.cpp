#include<iostream>
#include<stdexcept>
#include<vector>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>

using Line = std::vector<char>;

class Text_iterator{
	std::list<Line>::iterator ln; //hanyadik sor
	Line::iterator pos; //hanyadik "oszlop" (karakter a sorban)
public:
	Text_iterator(std::list<Line>::iterator ll,Line::iterator pp) : ln{ll},pos{pp}{}
	char& operator*(){return *pos;} // konkrét karakter
	Text_iterator& operator++();
	bool operator==(const Text_iterator& other) const{return ln==other.ln && pos==other.pos;}
	bool operator!=(const Text_iterator& other) const{return !(*this==other);}

	Line& get_line() const {return *ln;}
	Line::iterator get_pos() const {return pos;} // karakter sorszama
};

Text_iterator& Text_iterator::operator++()
{
	++pos;
	if(pos==(*ln).end()){
		++ln;
		pos = (*ln).begin();
	}
	return *this;
}

namespace std{  //felülírjuk  az std névteret, hogy működjön a text editorhoz!
	template<>
	struct iterator_traits<Text_iterator>{
		typedef ptrdiff_t difference_type;
		typedef char value_type;
		typedef char* pointer;
		typedef char& reference;
		typedef input_iterator_tag iterator_category;  
	};
}

struct Document{
	std::list<Line> line;
	Document(){line.push_back(Line{});}

	Text_iterator begin() {return Text_iterator(line.begin(),(*line.begin()).begin());}
	Text_iterator end()
	{
		auto last = line.end();
		--last;
		return Text_iterator(last,(*last).end());
	}
};

std::istream& operator>> (std::istream& is,Document& d)
{
	for (char ch;is.get(ch);)    // beturol beture bemásoljuk az új sort
	{
		if(ch=='|') break;
		d.line.back().push_back(ch);
		if(ch=='\n') d.line.push_back(Line{});
	}
	if(d.line.back().size()) d.line.push_back(Line{});
	return is;                 
}	

void print(Document& d) //Doksi kiirasa
{
	for (auto p: d) std::cout<<p;
}

void erase_line(Document& d, int n)
{
	if(n<0||d.line.size()-1<=n) return;
	auto p = d.line.begin();
	advance(p,n);  //iteratort léptet vmennyivel (számossággal) ,alap std függvény
	d.line.erase(p);

}

template<typename Iter>
void advance(Iter& p,int n)
{	
	while (0<n){++p;--n;}
	while (n<0){--p;++n;}

}

bool match(Text_iterator p, Text_iterator last, const std:: string& s){
for(auto q=s.begin();q!=s.end();++q)
{
	if(*q!=*p||p==last) return false;
	++p;
}
return true;

}

Text_iterator find_txt(Text_iterator first, Text_iterator last, const std::string& s)
{
	if(s.size()==0) return last;
	char first_char =s[0];
	while(true)
	{
		auto p=std::find(first,last,first_char); //find egy iteratort ad vissza, alap std függvény
		if(p==last||match(p,last,s)) return p; //p az elso betü első előfordulását fogja megtalálni
		first=++p; //ha nincs egyezés irány a következő karakter


	}

}

find_replace( Text_iterator first, Text_iterator last,const std::string& fs,const std::string& rs)
{
	Text_iterator p = find_txt(first,last,fs);
	if(p==last) return;

	Line& li = p.get_line();
	const int diff = rs.size()-fs.size(); //replace txt, find txt ??
	if (diff>0&&li.size()+diff>li.capacity())
	{
		li.reserve(li.size()+diff);
	}
	p=find_txt(first,last,fs);
	auto q=p.get_pos();
	q=li.erase(q,q+fs.size());
	for(auto rit=rs.crbegin();rit!=rs.crend();++rit)
	{
		q=li.insert(q,*rit);	
	}
}














int main()
try{

	Document my_doc;
	std::istringstream iss {"Today is the greatest\nday I've ever know\ncan't wait for tomorrow"};
	iss >> my_doc;
	print(my_doc);
	//nem müködik egyenlöre;
	erase_line(my_doc,2);
	print(my_doc);
	//keresés használata:
	find_txt(my_doc.begin(),my_doc.end(),"greatest");
	find_replace(my_doc.begin(),my_doc.end(),"greatest","superbliest");
	find_replace(my_doc.begin(),my_doc.end(),"tomorrow","later");
	find_replace(my_doc.begin(),my_doc.end(),"the","t");
	
} catch (std::exception& e)
{
	std::cerr<<"Exeption: "<<e.what()<<std::endl;
	return 1;
} catch(...){
	std::cerr<<"Unknow exeption!"<<std::endl;
	return 2;
}
