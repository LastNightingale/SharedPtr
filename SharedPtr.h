#pragma once
#include <iostream>

template <typename T>
class SharedPtr
{
private:
	T* m_Data = nullptr;
	unsigned int* m_Counter = new unsigned int;
public:
	SharedPtr() = delete;
	SharedPtr(T& data)
	{
		m_Data = new T(data);
		*m_Counter = 1;
	}
	SharedPtr(SharedPtr<T>& ptr)
	{
		m_Data = ptr.m_Data;
		m_Counter = ptr.m_Counter;
		(* m_Counter)++;
	}
	void operator =( const SharedPtr<T>& ptr)
	{
		this->m_Data = ptr.m_Data;
		this->m_Counter = ptr.m_Counter;
		(*m_Counter)++;
	}
	~SharedPtr()
	{
		(* m_Counter)--;
		if(!*m_Counter)
		{
			delete m_Data;
			delete m_Counter;
			std::cout << "Deleted";
		}
	}
	T& operator *()
	{
		return *m_Data;
	}
};

