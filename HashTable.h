#include "SimpleList.h"
#pragma once

class Item
{
public:
	String key;
	int value;
};

class HashTable
{
public:
	SimpleList<Item> List;
	void add(String key, int value);
	int get(String key);
	~HashTable();
};

