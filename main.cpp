#include <iostream>
#include "dictionary.hpp"
#include "dictionarySAL.cpp"
#include "dictionaryAL.cpp"
class MyKeyComparator{
	public :
		int operator()(int lhs ,int rhs )const {
			if(lhs<rhs) return -1;
			else if (lhs == rhs) return 0;
			else return 1; // lhs > rhs
		}
};
int main(void){
	DictionaryAL<int,std::string,MyKeyComparator> *novo=new DictionaryAL<int,std::string,MyKeyComparator>(4);
	std::string nova;
	int aux;
	if(!novo->insert(5,"Marciel")) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"First: "<<*novo<<std::endl;
	if(!novo->insert(3,"I")) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"Second: "<<*novo<<std::endl;
	if(!novo->insert(4,"sx")) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"Third: "<<*novo<<std::endl;
	if(!novo->insert(1,"Bth")) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"Fourth: "<<*novo<<std::endl;
	if(!novo->insert(1,"sd")) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"Fourth: "<<*novo<<std::endl;
	if(!novo->remove(5,nova)) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"Fifth: "<<*novo<<"\nValor:"<<nova<<std::endl; nova="";
	if(!novo->remove(4,nova)) std::cout<<"DEU MERDA"<<std::endl;nova="";
	std::cout<<"Sixth: "<<*novo<<"\nValor:"<<nova<<std::endl;
	if(!novo->remove(3,nova)) std::cout<<"DEU MERDA"<<std::endl;nova="";
	std::cout<<"Sixth: "<<*novo<<"\nValor:"<<nova<<std::endl;
	if(!novo->remove(1,nova)) std::cout<<"DEU MERDA"<<std::endl;nova="";
	std::cout<<"Sixth: "<<*novo<<"\nValor:"<<nova<<std::endl;
	if(!novo->remove(5,nova)) std::cout<<"DEU MERDA"<<std::endl;nova="";
	std::cout<<"Sixth: "<<*novo<<"\nValor:"<<nova<<std::endl;
	
	std::cout<<"MAX: "<<novo->max()<<std::endl;
	std::cout<<"MIN: "<<novo->min()<<std::endl;aux=0;
	if(!novo->sucessor(5,aux)) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"SUCESSOR4: "<<aux<<std::endl; aux=0;
	if(!novo->sucessor(1,aux)) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"SUCESSOR1: "<<aux<<std::endl; aux=0;
	if(!novo->sucessor(10,aux)) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"SUCESSOR10: "<<aux<<std::endl; aux=0;
	
	if(!novo->predecessor(3,aux)) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"ANTECESSOR3: "<<aux<<std::endl; aux=0;
	if(!novo->predecessor(1,aux)) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"ANTECESSOR1: "<<aux<<std::endl; aux=0;
	if(!novo->predecessor(11,aux)) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"ANTECESSOR11: "<<aux<<std::endl; aux=0;
	
	
	if(!novo->search(2,nova)) std::cout<<"NO ACHAMO TÍO"<<std::endl;nova="";
	std::cout<<nova<<std::endl;
	if(!novo->search(5,nova)) std::cout<<"NO ACHAMO TÍO"<<std::endl;
	std::cout<<nova<<std::endl;
	
	delete novo;
	return 0;
}
