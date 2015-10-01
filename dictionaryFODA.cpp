#include <iostream>
#include "dictionary.hpp"

/**********************************************************************/
/*Há um teste no início de cada método para garantir que só sejam usados
se houver um espaço de memória sequêncial alocado
*/
DictionaryAL::DictionaryAL(int _MaxSz){
	mpt_Data=new NodeAl[_MaxSz];
	if(!mpt_Data) std::cout<<"Falha na alocação de memória sequêncial!"<<std::endl;
	else mi_Capacity=_MaxSz;
}

int DictionaryAL::_search(Key _x) const{//O(n)
	int i;
	for(i=0;(i<mi_Length);i++)
		if((mpt_Data+i)->id==_x) return i;
	return -1;
}
bool DictionaryAL::remove(Key _x,Data &_s){//O(n)
	if(!mpt_Data) return false;
	int aux=this->_search(_x);
	if(aux<0) return false;
	
	_s=(mpt_Data+aux)->info;
	for(int i=aux+1;i<mi_Length;i++)
		*(mpt_Data+i-1)=*(mpt_Data+i);
	mi_Length--;
	return true;
	
}
bool DictionaryAL::search(Key _x,Data &_s){//O(n)
	if(!mpt_Data) return false;
	int aux=this->_search(_x);
	if(aux<0) return false;
	_s=(mpt_Data+aux)->info;
	return true;
}
bool DictionaryAL::insert(Key _newKey, Data _newInfo){//O(n)
	if(!mpt_Data) return false;
	if(_search(_newKey)>-1) return false;		//Se jah existe essa chave
	if(mi_Length==mi_Capacity) return false;	//Se ainda ha lugar
	
	(mpt_Data+mi_Length)->id=_newKey;
	(mpt_Data+mi_Length)->info=_newInfo;
	mi_Length++;
	
	return true;
}

Key DictionaryAL::min() const{
	if(!mpt_Data) return *(new Key);
	Key min=mpt_Data->id;
	
	int i;
	for(i=0;i<mi_Length;i++)
		if(((mpt_Data+i)->id)<min) 
			min=(mpt_Data+i)->id;

	return min;
}

Key DictionaryAL::max() const{
	if(!mpt_Data) return *(new Key);
	Key max=mpt_Data->id;

	int i;
	for(i=0;i<mi_Length;i++)
		if(((mpt_Data+i)->id)>max) 
			max=(mpt_Data+i)->id;

	return max;
}
bool DictionaryAL::sucessor(Key _x, Key &_y) const{
	if(!mpt_Data) return false;
	
	for(int i=0,Key max=_x;i<mi_Length;i++)
		if((((mpt_Data+i)->id)>_x) && (((mpt_Data+i)->id)<max))
			max=(mpt_Data+i)->id;
	_y=max;
	return true;
}

bool DictionaryAL::predecessor(Key _x, Key &_y) const{
	if(!mpt_Data) return false;
	
	for(int i=0,Key min=_x;i<mi_Length;i++)
		if((((mpt_Data+i)->id)<_x) && (((mpt_Data+i)->id)>min))
			min=(mpt_Data+i)->id;
	_y=max;
	return true;
}

/**********************************************************************/
/*
int DictionaryAL::_search(Key _x) const{
	int i;
	for(i=0;(i<mi_Length);i++)
	if((mpt_Data+i)->id==_x) return i;
	return -1;
}
*/
bool DictionaryAL::remove(Key _x,Data &_s){
	if(!mpt_Data) return false;
	int aux=this->_search(_x);
	if(aux<0) return false;
	
	_s=(mpt_Data+aux)->info;
	for(int i=aux+1;i<mi_Length;i++)
		*(mpt_Data+i-1)=*(mpt_Data+i);
	mi_Length--;
	return true;
	
}/*
bool DictionaryAL::insert(Key _newKey, Data _newInfo){
	if(!mpt_Data) return false;
	if(_search(_newKey)>-1) return false;		//Se jah existe essa chave
	if(mi_Length==mi_Capacity) return false;	//Se ainda ha lugar
	
	(mpt_Data+mi_Length)->id=_newKey;
	(mpt_Data+mi_Length)->info=_newInfo;
	mi_Length++;
	
	return true;
}
*/
Key DictionarySAL::min() const{
	return mpt_Data+(mi_Length-1)->id;
}

Key DictionarySAL::max() const{
	return mpt_Data->id;
}

bool DictionarySAL::sucessor(Key _x, Key &_y) const{
	if(!mpt_Data) return false;
	int aux=this->_search(_x);
	if(aux<0||(aux+1)==mi_Length) return false;	//Se nao encontrou||se nao possui suces
	_y=(mpt_Data+aux+1)->id;
	return true;
}

bool DictionarySAL::predecessor(1Key _x, Key &_y) const{
	if(!mpt_Data) return false;
	int aux=this->_search(_x);
	if(aux<=0) return false;		//Se encontrou||se nao possui pred
	_y=(mpt_Data+aux-1)->id;
	return true;
}
