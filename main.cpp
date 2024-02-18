#include "TRIES.h"
#include<windows.h>
void SetConsoleColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void ResetConsoleColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
int main()
{
	Tries dictionary;
	int opt;
	do
	{
		SetConsoleColor(12);
		cout << endl;
		cout << "1.Load Dictionary" << endl;
		cout << "2.Add Word" << endl;
		cout << "3.Search Word" << endl;
		cout << "4.Delete Word" << endl;
		cout << "5.Update Word" << endl;
		cout << "6.Word Suggestion" << endl;
		cout << "8.Display Dictionary" << endl;
		cout << "9.exit" << endl;
		cout << "Option : ";
		cin >> opt;
		ResetConsoleColor();
		switch (opt)
		{
			SetConsoleColor(2);
		case 1:
		{
			string file;
			cout << "Enter File name like (Dictionary.txt)" << endl;
			cin >> file;
			dictionary.importDictionary(file);
			break;
		}
		case 2:
		{
			string word, mean;
			cout << "Enter Word : ";
			cin >> word;
			cout << "Enter meaning : ";
			cin >> mean;
			dictionary.insert(word, mean);            // Stored in	Dictionary
			break;
		}
		case 3:
		{
			string word;
			cout << "Enter Word to search : ";
			cin >> word;
			dictionary.search(word);
			break;
		}
		case 4:
		{
			string word;
			cout << "Enter word to delete : ";
			cin >> word;
			dictionary.deleteWord(word);
			break;
		}
		case 5:
		{
			string word, mean;
			cout << "Enter word to Update : ";
			cin >> word;
			cout << "Enter Meaning to Update : ";
			cin >> mean;
			dictionary.insert(word, mean);
			break;
		}
		case 6:
		{
			string word;
			cout << "Enter Word for Suggestions: ";
			cin >> word;
			dictionary.suggestion(word);    //Display similar words meaning exist in dictionary
			break;
		}
		case 7:
		{
			dictionary.deleteAll();
			if (dictionary.isEmpty())
			{
				cout << "Dictionary is Empty";
			}
			break;
		}
		case 8:
		{
			dictionary.display();
			break;
		}
		case 9:
		{
			exit(0);
			break;
		}
		}
		cout << endl;
	} while (opt != 9);
	ResetConsoleColor();
	cout << endl;
	system("pause");
	return 0;
}

