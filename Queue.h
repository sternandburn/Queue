#include <iostream>
using namespace std;
const int MAX_QUEUE = 5;

template <class Type>
class Queue
{
	private:
		int front;
		int rear;
	    int count;
		int item[MAX_QUEUE];
	
	public:
		Queue();
		bool full() const;
		bool empty() const;
		void enqueue(Type person);
		bool dequeue(Type &value);
		void print() const;
};

template <class Type>
Queue<Type>::Queue()
{
	front = 0;
	rear = -1;
	count = 0;
}

template <class Type>
bool Queue<Type>::full() const
{
	return (count == MAX_QUEUE);
}

template <class Type>
bool Queue<Type>::empty() const
{
	return (count == 0);
}

template <class Type>
void Queue<Type>::enqueue(Type name)
{
	if (!full())
	{
		rear = (rear + 1) % MAX_QUEUE;
		item[rear] = name;
		count++;
	}
	else
	  cout << "Person Rejected - cannot add to a full queue" << endl;
}

template <class Type>
bool Queue<Type>::dequeue(Type &value)
{
  bool ok=false;
  if (!empty())
    {
      value = item[front];
      front = (front + 1) % MAX_QUEUE;
      count--;
      ok=true;
    }
  else
    cout << "Cannot remove from an empty queue" << endl;
  return ok;
}

template <class Type>
void Queue<Type>::print() const
{
	cout << "FRONT: ";
	int spot = front;
	for (int i=0; i<count; i++)
	  {
	    cout << spot << ":" << item[spot] << " ";
	    spot = (spot + 1) % MAX_QUEUE;
      }  
    cout << "END" << endl;
}


int main()
{
 
  Queue queue;
  
  cout << "A queue example using a queue with max size of " << MAX_QUEUE << endl << endl;
  
  cout << "bob is entering the queue" << endl;
  queue.enqueue("bob");
  cout << "jill is entering the queue" << endl;
  queue.enqueue("jill");
  cout << "mike is entering the queue" << endl;  
  queue.enqueue("mike");
  cout << "renee is entering the queue" << endl;  
  queue.enqueue("renee");
  cout << "dave is entering the queue" << endl << endl;  
  queue.enqueue("dave");
  
  cout << "crystal is trying to enter the queue" << endl;  
  queue.enqueue("crystal");    
  
  cout << endl;
  string person="";
  if (queue.dequeue(person))
    cout << person << " has just left the queue" << endl;
  if (queue.dequeue(person))
    cout << person << " has just left the queue" << endl << endl;
  
  cout << "Updated queue contents:" << endl;
  queue.print();
  cout << endl;
  
  if (queue.dequeue(person))
    cout << person << " has just left the queue" << endl;
  if (queue.dequeue(person))
    cout << person << " has just left the queue" << endl;
  if (queue.dequeue(person))
    cout << person << " has just left the queue" << endl << endl;  
   
  cout << "Time for another queue removal" << endl;    
  if (queue.dequeue(person))
    cout << person << " has just left the queue" << endl << endl;  
  return 0;
}
