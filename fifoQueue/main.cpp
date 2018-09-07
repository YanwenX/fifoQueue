#include<iostream>
#include<cstring>
#include"arrayQueue.h"
#include"listQueue.h"
using namespace std;

int main(int argc, char *argv[])
{
	char *a = argv[1];
	/* int i, maxN = atoi(argv[2]), N = strlen(a);
	arrayQueue<char> q(maxN);

	for (i = 0; i < N; ++i){
		if (a[i] == '*')
			cout << q.get();
		else q.put(a[i]);
	}
	cout << endl; */

	Queue<char> q;
	int N = strlen(a);
	cout << "The string is:" << endl;
	for (int i = 0; i < N; ++i){
		if (a[i] == '*')
			cout << q.dequeue();
		else q.enqueue(a[i]);
	}
	cout << endl;

	return 0;
}