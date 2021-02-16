#include "hashquad.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

int main()
{
    int testdata[10000];
    float insert[100];
    float search[100];
    int Insertcollisions[100];
    int Searchcollisions[100];
    

    ifstream inFile;

    inFile.open("dataSetA.csv");

    int id;
    int i = 0;
    while(inFile >> id)
    {
        inFile.ignore(id, ',');
        testdata[i] = id;
        i++;
    }

    HashTable hash(40009);

    
    
    

    int index = 0; // counter for what index of testdata[] we are on
    int timeIndex = 0; // counter for what index of search and insert array we are on
    while(timeIndex < 100)
    {
        int counter = 0;
        // Times insert of 100 elements
        auto insertStart = chrono::steady_clock::now();

        while(counter < 100)
        {
            hash.insert(testdata[index]);
            index++;
            counter++;
        }
        auto insertEnd = chrono::steady_clock::now();
        Insertcollisions[timeIndex] = hash.getNumOfCollision(); // gets number of collisions in 100 inserts we just completed


        int searchCounter = 0;
        
        // Times the search of all the elements in the array so far
        auto searchStart = chrono::steady_clock::now();
        while(searchCounter < 100)
        {
            int x = rand() % index;
            hash.search(testdata[x]);
            searchCounter++;
        }

        auto searchEnd = chrono::steady_clock::now();

        Searchcollisions[timeIndex] = hash.getNumOfCollision(); // gets number of collisions in the search we just completed

        float Inserttime = chrono::duration_cast<chrono::nanoseconds>(insertEnd-insertStart).count() / 100;
        float Searchtime = chrono::duration_cast<chrono::nanoseconds>(searchEnd-searchStart).count() / 100;
        
        

        search[timeIndex] = Searchtime;
        insert[timeIndex] = Inserttime;
        timeIndex++;

    


    }

    //Writing to file
    ofstream outFile;
    outFile.open("insert_search_performance_hash_table_dataSetA.csv");

    outFile << "Insert" << endl;
    for(int i = 0; i < 100; i++)
    {
        cout << insert[i] << ", ";
        outFile << insert[i] << ", ";
    }
    outFile << endl;
    cout << endl;
    cout << endl;

    
    
    outFile << "Search" << endl;
    for(int i = 0; i < 100; i++)
    {
        cout << search[i] << ", ";
        outFile << search[i] << ", ";
               
    }
    outFile << endl;
    cout << endl;
    cout << endl;
   
    outFile << "IColl" << endl;
    for(int i = 0; i < 100; i++)
    {
        cout << Insertcollisions[i] << ", ";
        outFile << Insertcollisions[i] << ", ";
    }
    outFile << endl;
    cout << endl;
    cout << endl;

    outFile << "SColl" << endl;
    for(int i = 0; i < 100; i++)
    {
        cout << Searchcollisions[i] << ", ";
        outFile << Searchcollisions[i] << ", ";
    }
   

    inFile.close();
    outFile.close();

    

}