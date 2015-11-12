/*
Name : Akshay Joshi
Project: deque wrapper
*/
#include <iostream>
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
};

template<class dType>
TrackingDeque<dType>::TrackingDeque()
{
     max_size= 0;
}

template<class dType>
TrackingDeque<dType>::~TrackingDeque()
{
//  cout<<"SIZE:"<<max_size<<endl;
}
template<class dType>
void TrackingDeque<dType>:: push_back(const dType& value)
{
//		cout<<"PUSH"<<endl;
deque<dType>::push_back(value);
++max_size;
}
template<class dType>
void TrackingDeque<dType>:: pop_back()
{
	//	cout<<"POP"<<endl;
  deque<dType>::pop_back();
	--max_size;
}

template<class dType>
void TrackingDeque<dType>:: push_front(const dType& value)
{
		//cout<<"PUSH"<<endl;
  deque<dType>::push_front(value);
  ++max_size;
}
template<class dType>
void TrackingDeque<dType>:: pop_front()
{
//	cout<<"POP"<<endl;
  deque<dType>::pop_front();
	--max_size;
}
