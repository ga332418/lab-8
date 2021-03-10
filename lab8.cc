/*
 *        File: lab8.cc
 *      Author: Gabriel Avink
 *        Date: 3/10/2021
 * Description: git lab 8
 */

#include<iostream>
#include<fstream>
#include<string>
using namespace std;



void displayMenu()
{
        cout << "1. Set the shift key value" << endl;
        cout << "2. Encrypt a file" << endl;
        cout << "3. Decrypt a file" << endl;
        cout << "4. Quit" << endl;
}

void setKey(int &key)
{
        cout << "Please enter key value.-> ";
        cin >> key;
}

void encrypt(int key)
{
        string inputFile;
        string outputFile;

        ifstream inStream;
        char ch;
        char ch1;
        ofstream outStream;


        cout << "Enter file name to be encrypted.-> ";
        cin >> inputFile;

        cout << "Enter file name for output text to be saved.-> ";
        cin >> outputFile;

        inStream.open(inputFile);            

        if (!inStream.is_open())
        {
                cout << " File failed to open. " << endl;
                return;
        }

        outStream.open(outputFile);
        if (!outStream.is_open())
        {
                cout << " File failed to open. " << endl;
                return;
        }

        while (inStream.get(ch),!inStream.eof()) 
        {
                int shiftValue = (int)ch;
                shiftValue = shiftValue + key;
                ch1 = (char)shiftValue;
                outStream.put(ch1);
        }

        inStream.close();
        outStream.close();
}


void decrypt(int key)
{
        string inputFile;
        string outputFile;

        ifstream inStream;
        char ch;
        ofstream outStream;


        cout << "Enter file name to be decrypted.-> ";
        cin >> inputFile;

        cout << "Enter file name for output text to be saved.-> ";
        cin >> outputFile;

        inStream.open(inputFile);

        if (!inStream.is_open())
        {
                cout << " File failed to open. " <<endl;
                return;
        }

        outStream.open(outputFile);
        if (!outStream.is_open())
        {
                cout << " File failed to open. " <<endl;
                return;
        }

        while (inStream.get(ch),!inStream.eof())
        {       
                int shiftValue = (int)ch;
                shiftValue = shiftValue - key;
                ch = (char)shiftValue;
                outStream.put(ch);
        }

        inStream.close();
        outStream.close();
}

int main()
{
        int key = 3;
        int choice;
        do
        {
                displayMenu();  
                cin >> choice;
                if (choice == 1)
                {
                        setKey(key);
                }
                else if (choice == 2)
                {
                        encrypt(key);
                }
                else if (choice == 3)
                {
                        decrypt(key);
                }
                else if (choice == 4)
                {
                        break;
                }
                else
                {
                        cout << "Error: Please choose one of the options below." << endl;
                }

        } while (choice != 4);
        return 0;
}