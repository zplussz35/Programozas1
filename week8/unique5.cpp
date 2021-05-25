#include <vector>
#include <iostream>
#include <memory>

std::vector<int> suspicious()
{	
	//std::vector<int>* si= new std::vector<int>;
	//std::unique_ptr<std::vector<int>> v{new std::vector<int>};
	std::vector<int> v; //std vector mozgato szemantika

	for(int i;std::cin>>i;)
	{
		if(i) v.push_back(i);
		else throw std::exception();
	}

	return v;
	
}

int main()
try{
	auto vi = suspicious();

	for(int i=0;i<vi.size();++i)
	{
		std::cout<<vi.at(i)<<std::endl;
	}

	return 0;
	
}catch(std::exception& e){
	std::cerr<<e.what()<<std::endl;
	return -1;
}