/*
Author: Akshay Joshi
Description: Stack.h is a stack template where dType can hold any data
type.
 */
#include<stdexcept>
using namespace std;

template<class dType>
class Stack
{
	public:
		Stack();
		Stack(const Stack&);
		~Stack();
		Stack& operator=(const Stack&);
		int size();
		void push(dType);
		dType pop();
	private:
		static const int chunk_size;
		unsigned maximum_size;
		int current_size;
		dType* base;
};

template<class dType>
const int Stack<dType>::chunk_size=10;

template<class dType>
Stack<dType>::Stack():current_size(-1),maximum_size(chunk_size),base(new dType[chunk_size])
{
}


template<class dType>
Stack<dType>::Stack(const Stack& s):maximum_size(s.maximum_size), base(new dType[s.maximum_size])
{
	if(s.current_size>-1){
	try{
		for(current_size=0; current_size<=s.current_size; current_size++)
			base[current_size]=s.base[current_size];
		current_size--;
	}catch(...){
		delete[] base;
		throw;
	}
   }
}

template<class dType>
Stack<dType>::~Stack()
{
  delete [] base;
}


template<class dType>
Stack<dType>& Stack<dType>::operator=(const Stack& s)
{
	int temp=maximum_size;
	maximum_size=s.maximum_size;
	dType* base_new;
	try{
		base_new=new dType[maximum_size];//If this new memory is not assigned
	}catch(...){						//then this block will throw an error and
	maximum_size=temp;
	throw;						//catch block handles it will let user know by re-throwing
	}
	int tempCurr=current_size;
	current_size=s.current_size;
		if(current_size>-1)
		{
			try{
	 		for(int x=0; x<=current_size; x++)
			{
				base_new[x]=s.base[x];
			}
		}catch(...){
			current_size=tempCurr;
			maximum_size=temp;
			delete [] base_new;
			throw;
		}
			delete [] base;
			base=base_new;
		}
	return *this;
}

template<class dType>
void Stack<dType>::push(dType element)
{
	current_size++;
	if(current_size==maximum_size-1)
	{
		int temp_maxSize=maximum_size;// I want maximum size to be maximum_size
		maximum_size=maximum_size+chunk_size;//if new throws an exception
		dType* new_buffer;
		try{
			 new_buffer = new dType[maximum_size];
		}catch(...){
			maximum_size=temp_maxSize;
			throw;	// rethrow the exception
		}
		try{
		for(int x=0; x<current_size; x++)
			new_buffer[x]=base[x];
		}catch(...){
			maximum_size=temp_maxSize;
			delete [] new_buffer;
			throw;
		}
		delete [] base;
		base=new_buffer;
	}
	base[current_size]=element;
}

template<class dType>
dType Stack<dType>::pop()
{
	try{
	if(current_size<0)
	{throw underflow_error("");}
	}catch(exception &e){
	current_size++;
	}
	return base[current_size--];
}

template<class dType>
int Stack<dType>::size()
{
	return current_size+1;
}
