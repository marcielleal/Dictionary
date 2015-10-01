#include <iostream>
#include "dictionary.hpp"

int main(void){
	DictionaryAL *novo=new DictionaryAL(4);
	Data nova;
	Key aux;
	if(!novo->insert(2,"Marciel")) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"First: "<<*novo<<std::endl;
	if(!novo->insert(3,"I")) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"Second: "<<*novo<<std::endl;
	if(!novo->insert(4,"sx")) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"Third: "<<*novo<<std::endl;
	if(!novo->insert(1,"Bth")) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"Fourth: "<<*novo<<std::endl;
	
	std::cout<<"MAX: "<<novo->max()<<std::endl;
	std::cout<<"MIN: "<<novo->min()<<std::endl;
	if(!novo->sucessor(4,aux)) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"SUCESSOR: "<<aux<<std::endl; aux=0;
	if(!novo->sucessor(1,aux)) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"SUCESSOR: "<<aux<<std::endl; aux=0;
	if(!novo->predecessor(4,aux)) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"ANTECESSOR: "<<aux<<std::endl; aux=0;
	if(!novo->predecessor(2,aux)) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"ANTECESSOR: "<<aux<<std::endl; aux=0;
	
	
	if(!novo->search(2,nova)) std::cout<<"NO ACHAMO TÍO"<<std::endl;
	std::cout<<nova<<std::endl;
	
	delete novo;
	return 0;
}
