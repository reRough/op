//
// Created by Admin on 02.04.2022.
//

#ifndef LABS_LIBS_TASKS__H
#define LABS_LIBS_TASKS__H

#include "../string_.h"

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

typedef struct BagOfWords{
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

BagOfWords _bag;
BagOfWords _bag2;

char *getEndOfString(char *s);

//удаляет из строки все пробельные символы
void removeNonLetter(char *s);

//Преобразовывает строку, оставляя только один символ в каждой последовательности
//подряд идущих одинаковых символов
void removeAdjacentEqualLetters(char *s);

//Сокращает количество пробелов между словами данного предложения до одного
void removeExtraSpaces(char *s);

//Возвращает значение 0, если слово не было считано, в противном
//случае будет возвращено значение 1
bool getWord ( char *beginSearch , WordDescriptor *word );

//Преобразовывает строку таким образом, чтобы цифры каждого слова были перенесены в начало слова
//и изменяет порядок следования цифр на обратный
void digitToStart(WordDescriptor word);

//Считывает слова с конца строки
bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

int wordcmp(WordDescriptor w1, WordDescriptor w2);

//Заменяет все вхождения слова 𝑤1 на слово 𝑤2
void replaceWord(char *source, char *w1, char *w2);

//Проверяет последовательность слов на правильный порядок
int arrangeInOrder(char *s);

//Сравнивает два слова на равенство
bool areWordsEqual(WordDescriptor w1, WordDescriptor w2);

//Получает позиции начала и конца каждого слова строки
void getBagOfWords(BagOfWords *bag, char *s);

int findWordInBag(BagOfWords *bag, WordDescriptor word);

//Проверяет является ли слово палиндромом
bool isPalindrome(WordDescriptor w);

int getWord2(char *beginSearch, WordDescriptor *word);

//Определить количество слов-палиндромов в строке
int countPalindromes(char *s);

//Перемешивает две строки так, чтобы в получившейся чередовались слова первой и второй строки
void mixStrings(char *s1, char *s2, char *s3);

//Преобразовывает строку, изменив порядок следования слов в строке на обратный
void reverseWordInString(char *s);

//Находит слово данной строки, предшествующее первому из слов,
//содержащих букву "а"
WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *word);

//Выводит слово данной строки, предшествующее первому из слов,
//содержащих букву "а"
void printWordBeforeFirstWordWithA(char *s);

//Переводит WordDescriptor в char*
void wordToString(WordDescriptor word, char *str);

//Определяет последнее из слов первой строки, которое есть во второй строке
int lastWordInFirstStringInSecondString(char *str1, char *str2, WordDescriptor *word);

//Определяет, есть ли в данной строке одинаковые слова
bool hasEqualWords(char *s);

#endif //LABS_LIBS_TASKS__H
