#include <iostream>
#include "dictionary.hpp"
/*Há um teste no início de cada método para garantir que só sejam usados
se houver um espaço de memória sequêncial alocado
*/
DictionaryAL::DictionaryAL(int _MaxSz){
	mpt_Data=new NodeAl[_MaxSz];
	if(!mpt_Data) std::cout<<"Falha na alocação de memória sequêncial!"<<std::endl;
	else mi_Capacity=_MaxSz;
}

int DictionaryAL::_search(Key _x) const{
	int i;
	for(i=0;(i<mi_Length);i++)
	if((mpt_Data+i)->id==_x) return i;
	return -1;
}

bool DictionaryAL::remove(Key _x,Data &_s){
	if(!mpt_Data) return false;
	int aux=this->_search(_x);
	int i;
	if(aux<0) return false;
	_s=(mpt_Data+aux)->info;
	for(i=aux;i<mi_Length;i++)
		*(mpt_Data+i)=*(mpt_Data+i+1);
	mi_Length--;
	return false;
	
}
bool DictionaryAL::search(Key _x,Data &_s){
	if(!mpt_Data) return false;
	int aux=this->_search(_x);
	if(aux<0) return false;
	_s=(mpt_Data+aux)->info;
	return true;
}
bool DictionaryAL::insert(Key _newKey, Data _newInfo){
	if(!mpt_Data) return false;
	if(_search(_newKey)>-1) return false;
	if(mi_Length==mi_Capacity){
		int i;
		std::cout<<"OLA:"<<mi_Length<<mi_Capacity<<std::endl;
		NodeAl *novo=new NodeAl[mi_Capacity*2];
		if(!novo) return false;
		for(i=0;i<mi_Length;i++)
			*(novo+i)=*(mpt_Data+i);
		std::swap(novo,mpt_Data);
		delete novo;
	}
	(mpt_Data+mi_Length)->id=_newKey;
	(mpt_Data+mi_Length)->info=_newInfo;
	mi_Length++;
	return true;
}

Key DictionaryAL::min() const{
	if(!mpt_Data) return *(new Key);
	Key min=this->mpt_Data->id;

	int i;
	for(i=0;i<mi_Length;i++)
		if(((mpt_Data+i)->id)<min) 
			min=(mpt_Data+i)->id;

	return min;
}

Key DictionaryAL::max() const{
	if(!mpt_Data) return *(new Key);
	Key max=this->mpt_Data->id;

	int i;
	for(i=0;i<mi_Length;i++)
		if(((mpt_Data+i)->id)>max) 
			max=(mpt_Data+i)->id;

	return max;
}

bool DictionaryAL::sucessor(Key _x, Key &_y) const{
	if(!mpt_Data) return false;
	int aux=this->_search(_x);
	if(aux<0||(aux+1)==mi_Length) return false;	//Se encontrou||se nao possui suces
	_y=(mpt_Data+aux+1)->id;
	return true;
}

bool DictionaryAL::predecessor(Key _x, Key &_y) const{
	if(!mpt_Data) return false;
	int aux=this->_search(_x);
	if(aux<=0) return false;		//Se encontrou||se nao possui pred
	_y=(mpt_Data+aux-1)->id;
	return true;
}

int main(void){
	DictionaryAL *novo=new DictionaryAL(2);
	Data nova;
	if(!novo->insert(2,"Marciel")) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<*novo<<std::endl;
	if(!novo->insert(3,"Irene")) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<*novo<<std::endl;
	if(!novo->insert(3,"Marciel")) std::cout<<"DEU MERDA"<<std::endl;
	std::cout<<*novo<<std::endl;
	if(!novo->insert(4,"sex")) std::cout<<"DEU MERDA"<<std::endl;
	/*
	std::cout<<*novo<<std::endl;
	novo->remove(2,nova);
	std::cout<<*novo<<std::endl;
	if(!novo->search(2,nova)) std::cout<<"NO ACHAMO TÍO"<<std::endl;*/
	std::cout<<nova<<std::endl;
	
	delete novo;
	return 0;
}
