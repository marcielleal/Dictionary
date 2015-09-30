#include <iostream>
#include "dictionary.hpp"
typedef int Key;
int DictionaryAL::_search(Key _x) const{
}

bool DictionaryAL::remove(Key _x,Data &_s){return 1;}
bool DictionaryAL::search(Key _x,Data &_s){
	
}
bool DictionaryAL::insert(Key _newKey, Data _newInfo){return 1;}

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
	int i;
	for(i=0;(i<mi_Length) && ((mpt_Data+i)->id!=_x);i++);
	if(i==mi_Length||(i+1)==mi_Length) return false;	//Se encontrou||se nao possui suces
	_y=(mpt_Data+i+1)->id;
	return true;
}

bool DictionaryAL::predecessor(Key _x, Key &_y) const{
	int i;
	for(i=0;(i<mi_Length) && ((mpt_Data+i)->id!=_x);i++);
	if(i==mi_Length||i==0) return false;				//Se encontrou||se nao possui pred
	_y=(mpt_Data+i-1)->id;
	return true;
}
