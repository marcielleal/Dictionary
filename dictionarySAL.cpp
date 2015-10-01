#include "dictionary.hpp"
/**********************************************************************/
/*Retorna o indice de uma Key no mpt_Data se ela existir nele. Senao, retorna
 * um inteiro negativo indicando o local onde ela poderia ser colocada sem
 * alterar a ordenacao do vetor. Para saber esse indice, basta multiplicar por
 * -1 e subtrair 1 desse inteiro negativo retornado pela funcao*/
template <typename Key,typename Data,typename KeyComparator>
int DictionarySAL<Key,Data,KeyComparator>::_search(Key _x) const{
	int e,m,d;
	e=-1; d=this->mi_Length;
	while(e<d-1){
		m=(e+d)/2;
		if((((this->mpt_Data)+m)->id)<_x) e=m;
		else if((((this.mpt_Data)+m)->id)>_x) d=m;
		else return m;
	}
	return -(e+2);
}
template <typename Key,typename Data,typename KeyComparator>
bool DictionarySAL<Key,Data,KeyComparator>::search(Key _x,Data &_s){
	if(!this->mpt_Data) return false;
	int aux=_search(_x);
	if(aux<0) return false;
	
	_s=((this->mpt_Data)+aux)->info;
	return true;
}

template <typename Key,typename Data,typename KeyComparator>
bool DictionarySAL<Key,Data,KeyComparator>::remove(Key _x,Data &_s){
	if(!this->mpt_Data) return false;
	int aux=this->_search(_x);
	if(aux<0) return false;
	
	_s=((this->mpt_Data)+aux)->info;
	for(int i=aux+1;i<this->mi_Length;i++)
		*((this->mpt_Data)+i-1)=*((this->mpt_Data)+i);
	this->mi_Length--;
	
	return true;
	
}
template <typename Key,typename Data,typename KeyComparator>
bool DictionarySAL<Key,Data,KeyComparator>::insert(Key _newKey, Data _newInfo){
	if(!this->mpt_Data) return false;
	int aux=this->_search(_newKey);
	if(aux>-1) return false;					//Se jah existe essa chave
	if(this->mi_Length==this->mi_Capacity) return false;	//Se ainda ha lugar
	
	aux=(-1*aux)-1;
	
	for(int i=this->mi_Length;i>aux;i--)
		*((this->mpt_Data)+i)=*((this->mpt_Data)+(i-1));
	
	((this->mpt_Data)+aux)->id=_newKey;
	((this->mpt_Data)+aux)->info=_newInfo;
	(this->mi_Length)++;
	
	return true;
}

template <typename Key,typename Data,typename KeyComparator>
Key DictionarySAL<Key,Data,KeyComparator>::min() const{
	return ((this->mpt_Data)+(this->mi_Length-1))->id;
}
template <typename Key,typename Data,typename KeyComparator>
Key DictionarySAL<Key,Data,KeyComparator>::max() const{
	return this->mpt_Data->id;
}

/*Considerou-se que a chave Key _x precisa estar no
 * dicionario para os dois metodos a seguir */
template <typename Key,typename Data,typename KeyComparator>
bool DictionarySAL<Key,Data,KeyComparator>::sucessor(Key _x, Key &_y) const{
	if(!this->mpt_Data) return false;
	int aux=this->_search(_x);
	if((aux<0)||(aux+1)==this->mi_Length) return false;	//Se nao esta na lista||nao possui sucessor
	
	_y=((this->mpt_Data)+(aux+1))->id;
	
	return true;
}
template <typename Key,typename Data,typename KeyComparator>
bool DictionarySAL<Key,Data,KeyComparator>::predecessor(Key _x, Key &_y) const{
	if(!this->mpt_Data) return false;
	int aux=this->_search(_x);
	if(aux<=0) return false;		//Se encontrou||se nao possui predecessor
	
	_y=((this->mpt_Data)+(aux-1))->id;
	
	return true;
}
/**********************************************************************/
