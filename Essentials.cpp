// Essentials.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

template<class T>
class Node
{
public:

	Node(T value) : value(value) {}
	
	void deleteNode()
	{
		this->next->setPrev(prev);
		this->prev->setNext(next);
	}

	void setPrev(Node* newPrev)
	{
		this->prev = newPrev;
	}

	void setNext(Node* newNext)
	{
		this->next = newNext;
	}

	Node* getPrev() const
	{
		return this->prev;
	}

	Node* getNext() const
	{
		return this->next;
	}

	bool hasPrev()
	{
		return this->prev != nullptr;
	}

	bool hasNext()
	{
		return  this->next != nullptr;
	}
	

	T getValue()
	{
		return  value;
	}
	
private:
	Node* prev;
	Node* next;
	T value;
};


template<class T>
class LinkedList
{

public:
	
	/// <summary>
	/// Adds the specified node at the back of the list;
	/// </summary>
	/// <param name="node">The node.</param>
	void add(Node<T>* node)
	{

		if (!list.empty())
		{
			if (list.back() != nullptr)
			{
				//set the last node as previous node
				node->setPrev(list.back());
			}
		}
		list.push_back(node);
		
	}

	
	/// <summary>
	/// Adds a node after a particular node.
	/// </summary>
	/// <param name="node">The node.</param>
	/// <param name="prev">The previous.</param>
	/// <returns>returns true if next node was found and placed after it, otherwise returns false</returns>
	bool add_after(Node<T>* node, Node<T>* prev)
	{
		
		auto result = std::find(list.begin(), list.end(), prev);
		if (result!=list.end())
		{
			node->setNext(prev->getNext());
			prev->setNext(node);
			node->setPrev(prev);
			list.insert(result+1, node);
			return true;
		}

		return false;
	}
	

	/// <summary>
	/// Adds a Node before a particular node
	/// </summary>
	/// <param name="node">The node.</param>
	/// <param name="next">The next.</param>
	/// <returns>true if success, otherwise if previous node was not found returns false</returns>
	bool add_before(Node<T>* node, Node<T>* next)
	{
		auto result = std::find(list.begin(), list.end(), next);
		if (result != list.end())
		{
			node->setNext(next);
			node->setPrev(next->getPrev());
			next->setPrev(node);
			list.insert(result, node);
			return true;
		}

		return false; 
	}


	std::vector<Node<T>*> getList() const
	{
		return  this->list;
	}
	
private:

	std::vector<Node<T>*> list;

	
};


int main() 
{

	Node<int> one(1);
	Node<int> two(2);
	Node<int> five(5);

	LinkedList<int> list;
	list.add(&one);
	list.add(&two);
	list.add(&five);

	Node<int> three(3);
	list.add_after(&three, &two);

	Node<int> four(4);
	list.add_before(&four, &five);
	

	for (Node<int>* n : list.getList())
	{

		std::cout << "My value = " << n->getValue();
		if (n->hasPrev())
			std::cout << " and I come after " << n->getPrev()->getValue();
		if (n->hasNext())
			std::cout << " and I come before " << n->getNext()->getValue();

		std::cout << std::endl;
	}


	
	
	system("pause");

}


