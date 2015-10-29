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
  cout<<"SIZE:"<<max_size<<endl;
}
template<class dType>
void TrackingDeque<dType>:: push_back(const dType& value)
{
deque<dType>::push_back(value);
++max_size;
}
template<class dType>
void TrackingDeque<dType>:: pop_back()
{
  deque<dType>::pop_back();
}

template<class dType>
void TrackingDeque<dType>:: push_front(const dType& value)
{
  deque<dType>::push_front(value);
  ++max_size;
}
template<class dType>
void TrackingDeque<dType>:: pop_front()
{
  deque<dType>::pop_front();
}

int main()
{
  TrackingDeque<char> mybuffer;
  mybuffer.push_front('A');
  mybuffer.push_back('B');
  cout << "Front of deque is: " << mybuffer.front() << endl;
  mybuffer.pop_front();
  cout << "Front of deque is: " << mybuffer.front() << endl;
  mybuffer.pop_front();
return 0;
}
