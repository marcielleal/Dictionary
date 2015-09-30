#include <iostream>
#include "dictionary.hpp"

typedef int Key;
//Retorna a posicao da lista
int DictionaryAL::_search(Key _x) const{
	int i;
	for(i=0;(i<mi_Length);i++)
		if((mpt_Data+i)->id==_x) return i;
	return -1;
}

bool DictionaryAL::remove(Key _x,Data &_s){return 1;}
bool DictionaryAL::search(Key _x,Data &_s){
	int aux=this._search(_x);
	if(aux<0) return false;
	_s=(mpt_Data+aux)->info;
	return true;
}
bool DictionaryAL::insert(Key _newKey, Data _newInfo){
	if(mi_Length>=mi_Capacity)
}

Key DictionaryAL::min() const{
	Key min=this->mpt_Data->id;

	int i;
	for(i=0;i<mi_Length;i++)
		if(((mpt_Data+i)->id)<min) 
			min=(mpt_Data+i)->id;

	return min;
}

Key DictionaryAL::max() const{
	Key max=this->mpt_Data->id;

	int i;
	for(i=0;i<mi_Length;i++)
		if(((mpt_Data+i)->id)>max) 
			max=(mpt_Data+i)->id;

	return max;
}

bool DictionaryAL::sucessor(Key _x, Key &_y) const{
	int aux=this._search(_x);
	if(aux<0||(aux+1)==mi_Length) return false;	//Se encontrou||se nao possui suces
	_y=(mpt_Data+aux+1)->id;
	return true;
}

bool DictionaryAL::predecessor(Key _x, Key &_y) const{
	int aux=this._search(_x);
	if(aux<=0) return false;		//Se encontrou||se nao possui pred
	_y=(mpt_Data+aux-1)->id;
	return true;
}
