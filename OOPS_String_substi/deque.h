/*
Name : Akshay Joshi
Project: deque wrapper
*/
#include <deque>
using namespace std;
template<class dType>
class TrackingDeque: public deque<dType>
{
	public:
		TrackingDeque();
		~TrackingDeque();
    void push_back(const dType&);
    void pop_back();
    void push_front(const dType&);
    void pop_front();

  private:
    int max_size;
		int size;
};

template<class dType>
TrackingDeque<dType>::TrackingDeque()
{
		size=0;
     max_size= 0;
}

template<class dType>
TrackingDeque<dType>::~TrackingDeque()
{
//	cerr<<"..."<<size<<"..."<<endl;
}

template<class dType>
void TrackingDeque<dType>:: push_back(const dType& value)
{
deque<dType>::push_back(value);
++max_size;
if(size<max_size)
{
	size=max_size;
}
}
template<class dType>
void TrackingDeque<dType>:: pop_back()
{
  deque<dType>::pop_back();
	--max_size;
	if(size<max_size)
	{
		size=max_size;
	}
}

template<class dType>
void TrackingDeque<dType>:: push_front(const dType& value)
{
  deque<dType>::push_front(value);
  ++max_size;
	if(size<max_size)
	{
		size=max_size;
	}

}

template<class dType>
void TrackingDeque<dType>:: pop_front()
{
  deque<dType>::pop_front();
	--max_size;
	if(size<max_size)
	{
		size=max_size;
	}

}
