#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void ClearScreen()
{
    cout << string(30, '\n');
}

int main()
{
    int filesCount;
    string extension = ".txt";
    cout << "Enter count of files to read: "; cin >> filesCount;
    string* names = new string[filesCount];
    for (int i = 0; i < filesCount; i++) {
        cout << "File #" << i << ": ";
        cin >> names[i];
        names[i] += extension;
    }

    for (int i = 0; i < filesCount; i++) {
        ifstream file(names[i]);
        cout << "Name: " << names[i] << ". Page: " << i << endl << endl;
        cout << file.rdbuf() << endl;
        file.close();
        ClearScreen();
    }
    return 0;
}