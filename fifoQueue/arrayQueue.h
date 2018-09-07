#ifndef ARRAYQUEUE_H_INCLUDED
#define ARRAYQUEUE_H_INCLUDED

template <class Item>
class arrayQueue
{
private:
	Item *q;
	int N, head, tail;		// indices
	int isEmpty() const;
	int isFull() const;
	void error() const;
public:
	arrayQueue(int);
	void put(Item);
	Item get();
};

template <class Item>
arrayQueue<Item>::arrayQueue(int maxN)
{
	q = new Item[maxN + 1];
	N = maxN + 1;
	head = 0;
	tail = 0;
}

template <class Item>
int arrayQueue<Item>::isEmpty() const
{
	return head % N == tail;
}

template <class Item>
int arrayQueue<Item>::isFull() const
{
	return (tail + 1) % N == head;
}

template <class Item>
void arrayQueue<Item>::error() const
{
	if (isEmpty())
		cout << '\n' << "The queue is empty." << endl;
	if (isFull())
		cout << '\n' << "The queue is full." << endl;
	return;
}

template <class Item>
void arrayQueue<Item>::put(Item item)
{
	if (isFull())
		error();
	else{
		q[tail++] = item;
		tail = tail % N;
	}
}

template <class Item>
Item arrayQueue<Item>::get()
{
	if (isEmpty()){
		error();
	}
	else{
		head = head % N;
		return q[head++];
	}
}

#endif // ARRAYQUEUE_H_INCLUDED