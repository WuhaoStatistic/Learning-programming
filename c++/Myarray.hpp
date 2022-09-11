#pragma once
#include <iostream>


template<class T>
class Myarray
{
public:
	
	int capacity;
	int size;
	Myarray(int capacity)
	{
		this->capacity = capacity;
		this->arrayaddress = new T[this->capacity];
		size = 0;
	}

	//¿½±´¹¹Ôì
	Myarray(const Myarray& arr)
	{
		this->capacity = arr.capacity;
		this->size = arr.size;

		//Éî¿½±´
		this->arrayaddress = new T[arr.capacity];
		for (size_t i = 0; i < arr.size; i++)
			this->arrayaddress[i] = arr[i];
	}

	Myarray& operator&=(const Myarray& arr)
	{
		if (this->arrayaddress != NULL)
		{
			delete[] this->arrayaddress;
			this->arrayaddress = NULL;
			this->capacity = 0;
			this->size = 0;
		}
		this->capacity = arr.capacity;
		this->size = arr.size;
		this->arrayaddress = new T[this->capacity];
		for (size_t i = 0; i < arr.size; i++)
			this->arrayaddress[i] = arr[i];
	}

	~Myarray()
	{
		if (this->arrayaddress != NULL)
		{
			delete[] arrayaddress;
			arrayaddress = NULL;
		}
	}
private:
	T* arrayaddress;
};