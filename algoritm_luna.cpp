#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
   string word;
   string new_word = "";
   cout << "Write your number: ";
   getline(cin, word); //присваиваем word значение, которое мы вводим
   
   for (int i = 0; i < word.size(); i++) { //удаление пробелов из word
        if (!isspace(word[i])) {
            new_word += word[i];
        }
    }
   
    char num[new_word.length()]; //char arr[word.length()]; // создаем массив символов длиной равной длине введенного слова
   
   for (int i = 0; i < new_word.length(); i++) {
		num[i] = new_word[i]; // заполняем массив символами из введенного слова
   }

   
   //for (int i = 0; i < new_word.length(); i++){
	   //int z = i;
	   //z++;
	   //if (z % 2 == 0){
		   //new_word[i] = new_word[i] * 2;
	   //}
   //}
   
   
   cout << "Array of words: ";
   for (int i = 0; i < new_word.length(); i++) {
      cout << num[i] << "|"; // выводим массив символов на экран
   }
   
   cout << endl << new_word.length() << endl << new_word;
   
   return 0;
}