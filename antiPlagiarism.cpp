#include <iostream>
#include <string>

using namespace std;

double antiPlagiarism(string text, string fragment);
void createStringArray(string text, string arrayString[]);
double counterOfTrueShingles(string text[], string fragment[]);
double counterOfAllShingles(string fragment[]);
double percentOriginality(double allShingles, double trueShingles);
bool isSeparator(char c);

const int NUMBER_OF_WORDS = 3;
const int N = 1024;

int main() {
    string text = "I am going to the shop";
    string fragment = "I am going to the home and will be sleep";

    cout << "original text = " << antiPlagiarism(text, fragment) << "%";

    return 0;
}

double antiPlagiarism(string text, string fragment) {
    string originalText[N];
    string fragmentText[N];

    createStringArray(text, originalText);
    createStringArray(fragment, fragmentText);

    double numberOfTrueShingles = counterOfTrueShingles(originalText, fragmentText);
    double numberOfShingles = counterOfAllShingles(fragmentText);

    return percentOriginality(numberOfShingles, numberOfTrueShingles);
}

void createStringArray(string text, string arrayString[]) {
    char word[N];
    int indexWord = 0;
    int indexArrayString = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (!isSeparator(text[i])) {
            word[indexWord] = text[i];
            indexWord++;
            if (isSeparator(text[i + 1]) or text[i + 1] == '\0') {
                word[indexWord] = '\0';
                indexWord = 0;
                arrayString[indexArrayString] = word;
                indexArrayString++;
            }
        }
    }
}

double counterOfTrueShingles(string text[], string fragment[]) {
    double numberOfTrueShingles = 0.0;
    for (int i = 0; i < N; i++) {
        int counter = 1;
        for (int j = i; j < N; j++) {
            if (text[j] != "\0" or fragment[j] != "\0") {
                if (text[j] == fragment[j]) {
                    if (counter == NUMBER_OF_WORDS) {
                        numberOfTrueShingles++;
                    }
                    counter++;
                }
            }
        }
    }
    return numberOfTrueShingles;
}

double counterOfAllShingles(string fragment[]) {
    double numberOfShingles = 0.0;
    for (int i = 0; i < N; i++) {
        int counter = 1;
        for (int j = i; j < N; j++) {
            if (fragment[j] != "\0") {
                if (counter == NUMBER_OF_WORDS) {
                    numberOfShingles++;
                }
                counter++;
            }
        }
    }
    return numberOfShingles;
}

double percentOriginality(double allShingles, double trueShingles) {
    return 100.0 * (1.0 - trueShingles / allShingles);
}

bool isSeparator(char c) {
    char separator[] = "., !;?";
    for (int i = 0; i < separator[i] != '\0'; i++)
        if (separator[i] == c)
            return true;
    return false;
}