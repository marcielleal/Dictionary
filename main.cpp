/*Alguns testes para as classes dictionary*/
#include <iostream>
#include "dictionary.hpp"
#include "dictionarySAL.cpp"
#include "dictionaryAL.cpp"
class Fruit{
	private:
		float calorias;
		std::string nome;
	public:
		Fruit(){
			this->nome="Abacate";
			this->calorias=125;
		}
		Fruit(std::string nome,float num){
			this->nome=nome;
			this->calorias=num;
		}
		float getCalorias() const{return this->calorias;}
		std::string getNome() const{return this->nome;}
		inline friend
		std::ostream &operator <<(std::ostream &_os,const Fruit &_oList){
			_os<<"{Nome: "<<_oList.nome<<", Calorias: "<<_oList.calorias<<"}";
			return _os;
		}
};
class FruitKeyComparator{
	public :
		int operator()(Fruit& lhs ,Fruit& rhs )const {
			return (lhs.getCalorias())-(rhs.getCalorias());
		}
};
int main(void){
	//DictionaryAL<Fruit,int,FruitKeyComparator> *novo=new DictionaryAL<Fruit,int,FruitKeyComparator>(4);
	DictionarySAL<Fruit,int,FruitKeyComparator> *novo=new DictionarySAL<Fruit,int,FruitKeyComparator>(4);
	std::string nova;
	int aux;
	Fruit pera("Pera",12);
	Fruit abacaxi("Abacaxi",15);
	Fruit laranja("laranja",156);
	Fruit cupuacu("cupuacu",1485);
	Fruit fruta;
	if(!novo->insert(abacaxi,156)) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"First: "<<*novo<<std::endl;
	if(!novo->insert(cupuacu,151)) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"Second: "<<*novo<<std::endl;
	if(!novo->insert(pera,156)) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"Third: "<<*novo<<std::endl;
	if(!novo->insert(laranja,10)) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"Fourth: "<<*novo<<std::endl;
	if(!novo->insert(laranja,16)) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"Fourth: "<<*novo<<std::endl;
	//if(!novo->remove(cupuacu,nova)) std::cout<<"DEU MERDA"<<std::endl;
	//std::cout<<"Sixth: "<<*novo<<"\nValor:"<<nova<<std::endl;nova="";
	if(!novo->search(laranja,aux)) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"Sixth: "<<*novo<<"\nValor:"<<nova<<std::endl;nova="";
	if(!novo->predecessor(laranja,fruta)) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"Sixth: "<<*novo<<"\nValor:"<<fruta<<std::endl;nova="";
	if(!novo->sucessor(laranja,fruta)) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<"Sixth: "<<*novo<<"\nValor:"<<fruta<<std::endl;nova="";
	
	/*
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
	
	
	if(!novo->search(5,nova)) std::cout<<"NO ACHAMO TÍO"<<std::endl;nova="";
	std::cout<<nova<<std::endl;
	if(!novo->search(4,nova)) std::cout<<"NO ACHAMO TÍO"<<std::endl;
	std::cout<<nova<<std::endl;
	*/
	delete novo;
	return 0;
}
