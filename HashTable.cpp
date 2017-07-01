#include "HashTable.h"

HashTable::~HashTable()
{
	List.clear();
}

void HashTable::add(String key, int value)
{
	Item item;
	item.key = key;
	item.value = value;
	List.push_back(item);
}

int HashTable::get(String key)
{
	for (SimpleList<Item>::iterator i = List.begin(); i != List.end(); ++i)
	{
		if (i->key == key)
			return i->value;
	}
	return -1;
}