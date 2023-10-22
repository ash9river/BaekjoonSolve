#include <iostream>
#include <string.h>
#include <memory.h>
#include <memory>
#include <string>
#include <queue>

template <typename T>
struct MyNode
{
	MyNode() :_Data(T()), _Prev(nullptr), _Next(nullptr) {}
	MyNode(T _Data) :_Data(_Data), _Prev(nullptr), _Next(nullptr) {}

	T _Data;
	MyNode<T>* _Prev;
	MyNode<T>* _Next;
};

template <typename T>
class MyQueue
{
#pragma region CONSTRUCTOR, DESTRUCTOR
public:
	MyQueue() : m_Head(nullptr), m_Tail(nullptr), m_Count(0) {}
	~MyQueue() { Release(); }
#pragma endregion

#pragma region PUBLIC_METHOD
public:
	void Push(MyNode<T>* _Node)
	{
		if (_Node == nullptr)
			return;

		if (m_Head == nullptr)
		{
			m_Head = _Node;
			m_Tail = _Node;

			m_Count++;
			return;
		}

		m_Tail->_Next = _Node;
		_Node->_Prev = m_Tail;

		m_Tail = _Node;

		m_Count++;
	}

	MyNode<T>* Pop()
	{
		if (m_Head == nullptr)
			return nullptr;

		MyNode<T>* popNode = m_Head;

		if (popNode->_Next == nullptr)
			m_Head = nullptr;
		else
		{
			m_Head = popNode->_Next;
			m_Head->_Prev = nullptr;
		}

		m_Count--;

		return popNode;
	}

	bool Empty()
	{
		if (m_Count <= 0)
			return true;

		return false;
	}

	T Front()
	{
		if (m_Count <= 0)
			return -1;

		if (m_Head == nullptr)
			return -1;

		return m_Head->_Data;
	}

	T Back()
	{
		if (m_Count <= 0)
			return -1;

		if (m_Tail == nullptr)
			return -1;

		return m_Tail->_Data;
	}
	
	unsigned int Size() { return m_Count; }

#pragma endregion

#pragma region PRIVATE_METHOD
	void Release()
	{
		if (m_Head == nullptr)
			return;

		while (true)
		{
			MyNode<T>* popNode = this->Pop();

			if (popNode == nullptr)
				break;

			delete popNode;
		}

		m_Head = nullptr;
		m_Tail = nullptr;
		m_Count=0;
	}
#pragma endregion
private:
	MyNode<T>* m_Head;
	MyNode<T>* m_Tail;

	unsigned int m_Count;
};

void Process(std::string& _cmd, MyQueue<int>& _queue)
{
	if (_cmd == "push")
	{
		int element = 0;
		std::cin >> element;

		MyNode<int>* node = new MyNode<int>(element);
		_queue.Push(node);

		return;
	}
	else if (_cmd == "pop")
	{
		MyNode<int>* node = _queue.Pop();

		if (node == nullptr) 
		{
			std::cout << "-1\n";
			return;
		}

		std::cout << node->_Data<<"\n";
		delete node;

		return;
	}
	else if (_cmd == "size")
		std::cout << _queue.Size()<<"\n";
	else if (_cmd == "empty")
		std::cout << _queue.Empty()<<"\n";
	else if (_cmd == "front")
		std::cout << _queue.Front()<<"\n";
	else if (_cmd == "back")
		std::cout << _queue.Back()<<"\n";
}


int main() 
{
	std::ios_base::sync_with_stdio(NULL);
	std::cin.tie(NULL); std::cout.tie(NULL);

	unsigned int cmdCount = 0;
	std::cin >> cmdCount;

	MyQueue<int> myQueue;

	for (int i = 0; i < (int)cmdCount; ++i)
	{
		std::string strCmd;
		std::cin >> strCmd;
		Process(strCmd, myQueue);
	}

	return 0;
}