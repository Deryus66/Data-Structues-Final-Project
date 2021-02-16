#include "hashquad.hpp"
#include <iostream>
#include <string>

using namespace std;

HashTable::HashTable(int bsize)
{
    tableSize = bsize;
    table = new int[tableSize];
    for(int i = 0; i < tableSize; i++)
    {
        table[i] = -1;
    }
    
    
    
}
unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}
int HashTable::getNumOfCollision()
{
    return numOfcolision;
}

int HashTable::search(int key)
{
    numOfcolision = 0;
    int index = hashFunction(key);
    if(table[index] == key)
    {
        return table[index];
    }
    else
    {
        int tracker = 0;
        for(int i = 1; i < tableSize; i++)
        {
            numOfcolision++;
            int counter = (index + (i*i));
            if(counter > tableSize)
            {
                tracker = counter -tableSize;
                counter = tracker - 1;
            }
            if(table[counter] == key)
            {
                return table[counter];
            }
            
            
        }

        return 0;
    }
    
    
    
}

bool HashTable::insert(int key)
{
    numOfcolision = 0;
    int index = hashFunction(key);
    if(table[index] == -1)
    {
        table[index] = key;
        
        return true;
    }
    else
    {
        int index = hashFunction(key);
        int tracker = 0;
        for(int i = 1; i < tableSize; i++)
        {
            numOfcolision++;
            int counter = (index + (i*i));
            if(counter > tableSize)
            {
                tracker = counter - tableSize;
                counter = tracker - 1;
            }
            if(table[counter] == -1)
            {
                
                
                table[counter] = key;
                
                return true;
                
            }
            
        }

        return false;
    }
    
}    
void HashTable::printTable()
{
    for(int i = 0; i < tableSize; i++)
    {
        cout << i << "|| ";
        
        cout << table[i];
        cout << endl;



    }
}


    
    
    
