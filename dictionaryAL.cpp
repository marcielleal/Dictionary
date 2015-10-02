#include "dictionary.hpp"
/**********************************************************************/
/*Há um teste no início de alguns métodos para garantir que estes só sejam usados
se houver um espaço de memória sequêncial alocado, ou seja, mpt_Data!=NULL*/
template <typename Key,typename Data,typename KeyComparator>
int DictionaryAL<Key,Data,KeyComparator>::compare(Key a,Key b) const{
	KeyComparator comparador;
	return comparador.operator()(a,b);
}

template <typename Key,typename Data,typename KeyComparator>
DictionaryAL<Key,Data,KeyComparator>::DictionaryAL(int _MaxSz){
	mpt_Data=new NodeAl[_MaxSz];
	if(!mpt_Data) std::cout<<"Falha na alocação de memória sequêncial!"<<std::endl;
	else mi_Capacity=_MaxSz;
}

template <typename Key,typename Data,typename KeyComparator>
int DictionaryAL<Key,Data,KeyComparator>::_search(Key _x) const{
	for(int i=0;(i<mi_Length);i++)
		if(!this->compare((mpt_Data+i)->id,_x)) return i;
	return -1;
}
template <typename Key,typename Data,typename KeyComparator>
bool DictionaryAL<Key,Data,KeyComparator>::search(Key _x,Data &_s){
	if(!mpt_Data||!mi_Length) return false;
	int aux=_search(_x);
	if(aux<0) return false;
	
	_s=(mpt_Data+aux)->info;
	return true;
}

template <typename Key,typename Data,typename KeyComparator>
bool DictionaryAL<Key,Data,KeyComparator>::remove(Key _x,Data &_s){
	if(!mpt_Data||!mi_Length) return false;
	int aux=_search(_x);		
	if(aux<0) return false;			//Se existe a chave no dicionario
	
	_s=(mpt_Data+aux)->info;
	for(int i=aux+1;i<mi_Length;i++)
		*(mpt_Data+(i-1))=*(mpt_Data+i);
	mi_Length--;
	return true;
	
}
template <typename Key,typename Data,typename KeyComparator>
bool DictionaryAL<Key,Data,KeyComparator>::insert(Key _newKey, Data _newInfo){
	if(!mpt_Data) return false;
	if(mi_Length==mi_Capacity) return false;	//Se ainda ha lugar
	if(_search(_newKey)>-1) return false;		//Se jah existe essa chave

	(mpt_Data+mi_Length)->id=_newKey;
	(mpt_Data+mi_Length)->info=_newInfo;
	mi_Length++;
	
	return true;
}

template <typename Key,typename Data,typename KeyComparator>
Key DictionaryAL<Key,Data,KeyComparator>::min() const{
	if(!mpt_Data||!mi_Length) return *(new Key);
	Key min=mpt_Data->id;
	
	for(int i=1;i<mi_Length;i++)
		if(compare((mpt_Data+i)->id,min)<0)
			min=(mpt_Data+i)->id;

	return min;
}
template <typename Key,typename Data,typename KeyComparator>
Key DictionaryAL<Key,Data,KeyComparator>::max() const{
	if(!mpt_Data||!mi_Length) return *(new Key);
	Key max=mpt_Data->id;

	for(int i=1;i<mi_Length;i++)
		if(compare((mpt_Data+i)->id,max)>0)
			max=(mpt_Data+i)->id;

	return max;
}
/*Considerou-se que a chave Key _x precisa estar no dicionario para os 
 * dois metodos a seguir */
template <typename Key,typename Data,typename KeyComparator>
bool DictionaryAL<Key,Data,KeyComparator>::sucessor(Key _x, Key &_y) const{
	if(!mpt_Data||!mi_Length) return false;
	//Procura-se a menor chave entre as maiores que _x
	Key max=_x; bool flag=false;
	for(int i=0;i<mi_Length;i++){
		Key aux=(mpt_Data+i)->id;
		if(compare(aux,_x)>0){
			if (!compare(max,_x)) max=aux;
			else if(compare(aux,max)<0)
				max=aux;
		}else if(!compare(aux,_x)) flag=true;	//Confirmar se esta no dicionario
	}
	if(!compare(max,_x)||!flag) return false;	//Se nao achou maior||nao existe no dicionario
	_y=max;
	return true;
}
template <typename Key,typename Data,typename KeyComparator>
bool DictionaryAL<Key,Data,KeyComparator>::predecessor(Key _x, Key &_y) const{
	if(!mpt_Data||!mi_Length) return false;
	//Procura-se a maior chave entre as menores que _x
	Key min=_x; bool flag=false;
	for(int i=0;i<mi_Length;i++){
		Key aux=(mpt_Data+i)->id;
		if(compare(aux,_x)<0){
			if (!compare(min,_x)) min=aux;
			else if(compare(aux,min)>0) 
				min=aux;
		}else if(!compare(aux,_x)) flag=true;
	}
	if(!compare(min,_x)|!flag) return false;	//Se nao achou menor||nao existe no dicionario
	_y=min;
	return true;
}
/**********************************************************************/
