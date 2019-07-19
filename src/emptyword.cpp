#include <iostream>
using namespace std;

const int MAX_WORD_LENGTH = 20;

bool checkEmptyString(const char word[][MAX_WORD_LENGTH + 1], int numOfWords);

int main()
{
    const char dict1[][MAX_WORD_LENGTH + 1] = {"", "", ""};
    const char dict2[][MAX_WORD_LENGTH + 1] = {"Hello", "he", "fdd", "fdkjfkl"};

    if (checkEmptyString(dict1, 3))
         cout << "Dictionary 1 is empty!" << endl;
    else 
         cout << "Dictionary 1 is not empty!" << endl;

    if (checkEmptyString(dict2, 4))
        cout << "Dictionary 2 is empty!" << endl;
    else
        cout << "Dictionary 2 is not empty!" << endl;

    return 0;
}

bool checkEmptyString(const char word[][MAX_WORD_LENGTH + 1], int numOfWords)
{
	for(int i=0; i<numOfWords; i++) {
		int j=0;
		while(word[i][j]) j++;
		cout << j << endl;
		if(!j) return true;
	}
	return false;
}

