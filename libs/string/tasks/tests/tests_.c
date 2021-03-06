//
// Created by Admin on 02.04.2022.
//

#include "tests_.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "../tasks_.h"

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)

void assertString(const char *expected, const char *got, char const *fileName,
                  const char *funcName, const int line){
    if(strcmp(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

static void testAll_getWordBeforeFirstWordWithA() {
    WordDescriptor word;
    char s1[] = "";
    assert(getWordBeforeFirstWordWithA(s1, &word) ==  EMPTY_STRING);
    char s2[] = " ABC ";
    assert (getWordBeforeFirstWordWithA(s2, &word) == FIRST_WORD_WITH_A);

    char s3[] = "BC A";
    assert(getWordBeforeFirstWordWithA(s3, &word) == WORD_FOUND);
    char got[MAX_WORD_SIZE];
    copy(word.begin, word.end, got);
    got[word.end - word.begin] = '\0';
    ASSERT_STRING ("BC", got);

    char s4[] = "B Q WE YR OW IUWR ";
    assert (getWordBeforeFirstWordWithA(s4, &word) == NOT_FOUND_A_WORD_WITH_A);
}

static void test_removeNonLetters_common() {
    char str[] = "58 ghg 57g g46";

    removeNonLetter(str);

    char res[] = "58ghg57gg46";

    ASSERT_STRING(res, str);
}

static void test_removeNonLetters_none() {
    char str[] = "      ";

    removeNonLetter(str);

    char res[] = "";

    ASSERT_STRING(res, str);
}

static void test_removeNonLetters_empty() {
    char str[] = "";

    removeNonLetter(str);

    char res[] = "";

    ASSERT_STRING(res, str);
}

static void test_removeAdjacentEqualLetters_common() {
    char str[] = "qqqwwweeerrrtttyyyuuuiii111222333444555";
    removeAdjacentEqualLetters(str);

    char assumedStr[] = "qwertyui12345";

    ASSERT_STRING(assumedStr, str);
}

static void test_removeAdjacentEqualLetters_empty() {
    char str[] = "";
    removeAdjacentEqualLetters(str);

    char assumedStr[] = "";

    ASSERT_STRING(assumedStr, str);
}

static void test_removeAdjacentEqualLetters_neverRepeat() {
    char str[] = "qwertyui12345";

    removeAdjacentEqualLetters(str);

    char assumedStr[] = "qwertyui12345";

    ASSERT_STRING(assumedStr, str);
}

static void test_removeAdjacentEqualLetters_oneSymbol() {
    char str[] = "qqqqqqqqqqqqqqq";
    removeAdjacentEqualLetters(str);

    char assumedStr[] = "q";

    ASSERT_STRING(assumedStr, str);
}

static void test_removeExtraSpaces_common() {
    char str[] = "qw  ert     yu      i67";

    removeExtraSpaces(str);

    char assumedStr[] = "qw ert yu i67";

    ASSERT_STRING(assumedStr, str);
}

static void test_removeExtraSpaces_empty() {
    char str[] = "";

    removeExtraSpaces(str);

    char assumedStr[] = "";

    ASSERT_STRING(assumedStr, str);
}

static void test_removeExtraSpaces_solidText() {
    char str[] = "qwertyui";

    removeExtraSpaces(str);

    char assumedStr[] = "qwertyui";

    ASSERT_STRING(assumedStr, str);
}

int isDigit(int x) {
    return x >= '0' && x <= '9';
}

int isNotDigit(int x) {
    return !isDigit(x);
}

void test_strlen_common() {
    char str[] = "qwer";

    int assumedResult = 4;
    int result = strlen(str);

    assert(assumedResult == result);
}

void test_find_common() {
    char str[] = "qwertyui123";

    char *assumedResult = str + 7;
    char *result = find(str, str + 12, 'i');

    assert(assumedResult == result);
}

void test_find_notFound() {
    char str[] = "qwertyuio12345";

    char *assumedResult = str + 14;
    char *result = find(str, str + 14, 'p');

    assert(assumedResult == result);
}

void test_findNonSpace_common() {
    char str[] = "   qwertyui";

    char *assumedResult = str + 3;
    char *result = findNonSpace(str);

    assert(assumedResult == result);
}

void test_findNonSpace_notFound() {
    char str[] = "     ";

    char *assumedResult = str + 5;
    char *result = findNonSpace(str);

    assert(assumedResult == result);
}

void test_findSpace_common() {
    char str[] = "qwer tyu 12";

    char *assumedResult = str + 4;
    char *result = findSpace(str);

    assert(assumedResult == result);
}

void test_findSpace_notFound() {
    char str[] = "qwertyui";

    char *assumedResult = str + 8;
    char *result = findSpace(str);

    assert(assumedResult == result);
}

void test_findNonSpaceReverse_common() {
    char str[] = "  \t  q";

    char *assumedResult = str + 5;
    char *result = findNonSpaceReverse(str + 5, str);

    assert(assumedResult == result);
}

void test_findNonSpaceReverse_notFound() {
    char str[] = "     ";

    char *assumedResult = str;
    char *result = findNonSpaceReverse(str + 4, str);

    assert(assumedResult == result);
}

void test_findSpaceReverse_common() {
    char str[] = "qwe rt y";

    char *assumedResult = str + 6;
    char *result = findSpaceReverse(str + 7, str);

    assert(assumedResult == result);
}

void test_findSpaceReverse_notFound() {
    char str[] = "qwertyu";

    char *assumedResult = str;
    char *result = findSpaceReverse(str + 7, str);

    assert(assumedResult == result);
}

void test_strcmp_equal() {
    char str[] = "qwertyu 12";
    char res[] = "qwertyu 12";

    assert(strcmp(str, res) == 0);
}

void test_strcmp_firstLess() {
    char str[] = "qweb 12";
    char res[] = "qwea 12";

    assert(strcmp(str, res) > 0);
}

void test_strcmp_firstGreater() {
    char str[] = "qwea 12";
    char res[] = "qweb 12";

    assert(strcmp(str, res) < 0);
}

void test_copy_commonCase() {
    char str[] = "qwertyu";

    char *resBegin = malloc(sizeof(char) * 8);

    char *resEnd = copy(str, str + 7, resBegin);
    *resEnd = '\0';

    assert(strcmp(str, resBegin) == 0);

    free(resBegin);
}

void test_copyIf_onlyDigits() {
    char str[] = "qw6r tyu789 x";
    char endStr[] = "6789";
    char *resBegin = malloc(sizeof(char) * 14);

    char *resEnd = copyIf(str, str + 13, resBegin, isDigit);
    *resEnd = '\0';

    assert(strcmp(endStr, resBegin) == 0);

    free(resBegin);
}

void test_copyIf_exceptDigits() {
    char str[] = "d34f 8xwj0q x";
    char endStr[] = "df xwjq x";
    char *resBegin = malloc(sizeof(char) * 14);

    char *resEnd = copyIf(str, str + 13, resBegin, isNotDigit);
    *resEnd = '\0';

    assert(strcmp(endStr, resBegin) == 0);

    free(resBegin);
}

void test_copyIfReverse_onlyDigits() {
    char str[] = "qw1 2 3r4tyu";
    char endStr[] = "4321";
    char *resBegin = malloc(sizeof(char) * 13);

    char *resEnd = copyIfReverse(str + 12, str - 1, resBegin, isDigit);
    *resEnd = '\0';

    assert(strcmp(endStr, resBegin) == 0);

    free(resBegin);
}

void test_copyIfReverse_exceptDigits() {
    char str[] = "qw1 2 3e4rty";
    char endStr[] = "ytre  w";
    char *resBegin = malloc(sizeof(char) * 12);

    char *resEnd = copyIfReverse(str + 11, str, resBegin, isNotDigit);
    *resEnd = '\0';

    assert(strcmp(endStr, resBegin) == 0);

    free(resBegin);
}

void test_countPalindromes_common() {
    char str[] = "chel ti aha hfh aboba";

    int assumedResult = 3;

    assert(countPalindromes(str) == assumedResult);
}

void test_countPalindromes_extraSpace() {
    char str[] = "    chel ti aha hfh aboba    ";

    int assumedResult = 3;

    assert(countPalindromes(str) == assumedResult);
}

void test_countPalindromes_empty() {
    char str[] = "";

    int assumedResult = 0;

    assert(countPalindromes(str) == assumedResult);
}

void test_countPalindromes_none() {
    char str[] = "chel ti aab hhj abobb";

    int assumedResult = 0;

    assert(countPalindromes(str) == assumedResult);
}
void test_mixStrings_common() {
    char str1[] = "qq ee rr";
    char str2[] = "tt yy";
    char str[MAX_STRING_SIZE];

    mixStrings(str1, str2, str);

    char assumedStr[] = "qq tt ee yy rr";

    ASSERT_STRING(assumedStr, str);
}

void test_mixStrings_empty() {
    char str1[] = "";
    char str2[] = "";
    char str[MAX_STRING_SIZE] = "";

    mixStrings(str1, str2, str);

    char assumedStr[] = "";

    ASSERT_STRING(assumedStr, str);
}

void test_mixStrings_empty1() {
    char str1[] = "";
    char str2[] = "qqqq wwewe rtytrurt";
    char str[MAX_STRING_SIZE] = "";

    mixStrings(str1, str2, str);

    char assumedStr[] = "qqqq wwewe rtytrurt";

    ASSERT_STRING(assumedStr, str);
}

void test_mixStrings_empty2() {
    char str1[] = "qqqq wwewe rtytrurt";
    char str2[] = "";
    char str[MAX_STRING_SIZE] = "";

    mixStrings(str1, str2, str);

    char assumedStr[] = "qqqq wwewe rtytrurt";

    ASSERT_STRING(assumedStr, str);
}

void test_reverseWordInString_common() {
    char str[MAX_STRING_SIZE] = "qwe rty uiop";

    reverseWordInString(str);

    char assumedStr[] = "poiu ytr ewq";

    ASSERT_STRING(assumedStr, str);
}

void test_reverseWordInString_singleSymbols() {
    char str[MAX_STRING_SIZE] = "q w e";

    reverseWordInString(str);

    char assumedStr[] = "e w q";

    ASSERT_STRING(assumedStr, str);
}

void test_reverseWordInString_empty() {
    char str[MAX_STRING_SIZE] = "";

    reverseWordInString(str);

    char assumedStr[] = "";

    ASSERT_STRING(assumedStr, str);
}

void test_lastWordInFirstStringInSecondString_common() {
    char str1[] = "qwe rtyu iopa";
    char str2[] = "sdfg rtyu hjkl zxc";

    WordDescriptor word;
    lastWordInFirstStringInSecondString(str1, str2, &word);

    char result[MAX_STRING_SIZE];
    wordToString(word, result);

    char assumedStr[] = "rtyu";

    ASSERT_STRING(assumedStr, result);
}

void test_lastWordInFirstStringInSecondString_empty() {
    char str1[] = "";
    char str2[] = "qwer tyui op asd";

    WordDescriptor word;
    bool status = lastWordInFirstStringInSecondString(str1, str2, &word);

    assert(status == false);
}

void test_lastWordInFirstStringInSecondString_noWord() {
    char str1[] = "qwer tyuio op";
    char str2[] = "asdf ghj kl";

    WordDescriptor word;
    bool status = lastWordInFirstStringInSecondString(str1, str2, &word);

    assert(status == false);
}

void test_hasEqualWords_common() {
    char str[] = "qwer tyui op qwer asd";

    assert(hasEqualWords(str) == true);
}

void test_hasEqualWords_empty() {
    char str[] = "";

    assert(hasEqualWords(str) == false);
}

void test_hasEqualWords_oneWord() {
    char str[] = "qwer";

    assert(hasEqualWords(str) == false);
}

void test_hasEqualWords_notFound() {
    char str[] = "qwer tyui op asdf ghjk";

    assert(hasEqualWords(str) == false);
}

void test_hasEqualWords_onlySpace() {
    char str[] = "                   ";

    assert(hasEqualWords(str) == false);
}

void test_string_() {
    test_removeNonLetters_common();
    test_removeNonLetters_empty();
    test_removeNonLetters_none();
    test_removeAdjacentEqualLetters_common();
    test_removeAdjacentEqualLetters_empty();
    test_removeAdjacentEqualLetters_neverRepeat();
    test_removeAdjacentEqualLetters_oneSymbol();
    test_removeExtraSpaces_common();
    test_removeExtraSpaces_empty();
    test_removeExtraSpaces_solidText();
    test_strlen_common();
    test_find_common();
    test_find_notFound();
    test_findNonSpace_common();
    test_findNonSpace_notFound();
    test_findSpace_common();
    test_findSpace_notFound();
    test_findNonSpaceReverse_common();
    test_findNonSpaceReverse_notFound();
    test_findSpaceReverse_common();
    test_findSpaceReverse_notFound();
    test_strcmp_equal();
    test_strcmp_firstLess();
    test_strcmp_firstGreater();
    test_copy_commonCase();
    test_copyIf_onlyDigits();
    test_copyIf_exceptDigits();
    test_copyIfReverse_onlyDigits();
    test_copyIfReverse_exceptDigits();
    test_countPalindromes_common();
    test_countPalindromes_extraSpace();
    test_countPalindromes_empty();
    test_countPalindromes_none();
    test_mixStrings_common();
    test_mixStrings_empty();
    test_mixStrings_empty1();
    test_mixStrings_empty2();
    test_reverseWordInString_common();
    test_reverseWordInString_singleSymbols();
    test_reverseWordInString_empty();
    test_lastWordInFirstStringInSecondString_common();
    test_lastWordInFirstStringInSecondString_empty();
    test_lastWordInFirstStringInSecondString_noWord();
    test_hasEqualWords_common();
    test_hasEqualWords_empty();
    test_hasEqualWords_oneWord();
    test_hasEqualWords_notFound();
    test_hasEqualWords_onlySpace();
}