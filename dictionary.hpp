#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP
#include <iostream>

typedef int Key;
typedef std::string Data;

class DictionaryAL{
	protected:
		struct NodeAl{
			Key id;
			Data info;
		};
		
		static const int SIZE=50;
		int mi_Length;
		int mi_Capacity;
		NodeAl *mpt_Data;
		
		int _search(Key _x) const;	//const serve para mostrar que o metodo nao ira alterar nenhum atributo da classe
		
	public:
		DictionaryAL(int _MaxSz=SIZE);
		virtual ~DictionaryAL(){delete [] mpt_Data;};
		bool remove(Key _x,Data &_s);
		bool search(Key _x,Data &_s);
		bool insert(Key _newKey, Data _newInfo);
		Key min() const;
		Key max() const;
		bool sucessor(Key _x, Key &_y) const;
		bool predecessor(Key _x, Key &_y) const;
		
		inline friend
		std::ostream &operator <<(std::ostream &_os,const DictionaryAL &_oList){
			_os<<"[";
			for(int i(0);i<_oList.mi_Length;i++)
				_os<<"{id: "<<_oList.mpt_Data[i].id<<", info: "<<_oList.mpt_Data[i].info<<"}";
			_os<<"]";
			return _os;
		}
};

class DictionarySAL:public DictionaryAL{
	public:
		DictionarySAL(int _MaxSz):DictionaryAL(_MaxSz){/* Empty */};
		virtual ~DictionarySAL(){ /* Empty */ };
		bool remove(Key _x, Data &_s);
		bool insert(Key _novaId, Data _novaInfo);
		Key min() const;
		Key max() const;
		bool sucessor(Key _x, Key & _y) const ;
		bool predecessor(Key _x, Key & _y) const ;
	private:
		int _search (Key _x) const ; 
};
#endif
