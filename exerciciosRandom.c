#include <stdio.h>
#define DIM 3



/*
//Write a function int countVowels(char *str1, char *str2) that takes two strings and 
//returns the total number of vowels (a, e, i, o, u, case insensitive) found in both strings combined.

int isVowel(char ch){
    if(ch == 'A' || ch == 'a' || ch == 'E' || ch == 'e' || ch == 'I' || ch == 'i' || ch == 'O' || ch == 'o' || ch == 'U' || ch == 'u'){
        return 1;
    }

    return 0;
}

int countVowels(char * s1, char * s2){
    int i, count = 0;

    for(i = 0; s1[i] != '\0'; i++){
        if(isVowel(s1[i]) == 1){
            count++;
        }
    }

    for(i = 0; s2[i] != '\0'; i++){
        if(isVowel(s2[i]) == 1){
            count++;
        }
    }

    return count;
}

int main(){
    char * s1 = "boas manos";
    char * s2 = "aaaa";

    printf("%d", countVowels(s1, s2));
    return 0;
}
*/

/*

//Implement a function float averageNegatives(int *array, int size) that calculates the arithmetic mean
//of all negative numbers in an integer array. Return 0.0 if no negative numbers are present.
float averageNegatives(int *arr, int size){
    int i, sum = 0, count = 0;

    for(i = 0; i < size; i++){
        if(arr[i] < 0){
            count++;
            sum += arr[i];
        }
    }

    if(count != 0){
        return (float) sum / count;
    }

    return 0.0;
}

int main(){
    int arr[5] =  {12, 12, 12, 12, 6};

    printf("%f", averageNegatives(arr, 5));
    return 0;
}

*/

/*
//write a function int sumMainDiagonal(int matrix[ROWS][COLS], int size) 
//that receives a square matrix and returns the sum of the elements in its main diagonal.

int sumMainDiagonal(int m[DIM][DIM]){
    int i, sum = 0;

    for(i = 0; i < DIM; i++){
        sum+=m[i][i];
    }

    return sum;
}

int main(){
    int m[DIM][DIM] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    printf("%d", sumMainDiagonal(m));
    return 0;
}
*/


/*
//Implement a function int countGreaterThan(int matrix[ROWS][COLS], int rows, int cols, int threshold) 
//that counts the number of elements in a matrix greater than a given threshold value.

int countGreaterThan(int m[DIM][DIM], int threshold){
    int x, y, count = 0;

    for (x = 0; x < DIM; x++){
        for (y = 0; y < DIM; y++){
            if(m[x][y] > threshold){
                count++;
            }
        }
    }

    return count;
}

int main(){
    int m[DIM][DIM] = {{57, 20, 40}, {157, 240, 727}, {1, 15, 39}};

    printf("%d", countGreaterThan(m, 75));
    return 0;
}
*/


/*

//Write a procedure void transposeMatrix(int input[ROWS][COLS], int output[COLS][ROWS], int rows, int cols) that calculates the transpose 
//of a given matrix and stores the result in another matrix.

void transposeMatrix(int m[DIM][DIM], int mT[DIM][DIM]){
    int x, y;

    for (x = 0; x < DIM; x++){
        for(y = 0; y < DIM; y++){
            mT[x][y] = m [y][x];
        }
    }
}

void printMatrix(int m[DIM][DIM]){
    int x, y;

    for(x = 0; x < DIM; x++){
        for(y = 0; y < DIM; y++){
            printf("%d %c", m[x][y], y == DIM - 1 ? '\n': ' ');
        }
    }
}

int main(){
    int m[DIM][DIM] = {{57, 20, 40}, {157, 240, 727}, {1, 15, 39}};
    int mT[DIM][DIM];

    printMatrix(m);

    transposeMatrix(m, mT);

    printMatrix(mT);


    return 0;
}


*/

/*

//Write a function int isPalindrome(char *word) that 
//manually checks if a given word is a palindrome. Do not use string.h functions like strlen.

int isPalindrome(char * word){
    int i, len;

    for (len = 0; word[len] != '\0'; len++);

    for(i = 0, len = len - 1; i < len; i++, len--){
        if(word[i] != word[len]){
            return 0;
        }
    }

    return 1;
}

int main(){
    char * msg = "mimim";

    printf("%d", isPalindrome(msg));

    return 0;
}

*/


/*
//Write a function void reverseString(char *str) that reverses a string in place.

void reserveString(char * s){
    int i, len;
    char temp;

    for (i = 0; s[i] != '\0'; i++);

    len = i - 1;

    for(i = 0; i < len; i++, len--){
        temp = s[i];
        s[i] = s[len];
        s[len] = temp;
    }
}

int main(){
    char msg[30] = "boas manos";

    printf("%s\n", msg);

    reserveString(msg);

    printf("%s\n", msg);
    
}
*/


/*
//Write a function int countVowels(char *str) that counts the number of vowels (a, e, i, o, u) in a given string.

int isVowel(char ch){
    if(ch == 'A' || ch == 'a' || ch == 'E' || ch == 'e' || ch == 'I' || ch == 'i' || ch == 'O' || ch == 'o' || ch == 'U' || ch == 'u'){
        return 1;
    }

    return 0;
}

int countVowels(char * s){
    int i, count = 0;

    for(i = 0; s[i] != '\0'; i++){
        if(isVowel(s[i]) == 1){
            count++;
        }
    }    

    return count;
}

int main(){
    char * s = "boas manos";

    printf("%d", countVowels(s));

    return 0;
}

*/


/* 
//Write a function void replaceSpaces(char *str, char replacement) that replaces all spaces in a string with a specified character.
void replaceSpaces(char * s, char replacement){
    int i;

    for(i = 0; s[i] != '\0'; i++){
        if(s[i] == ' '){
            s[i] = replacement;
        }
    }
}

int main(){
    char s[50] = "eu vou fazer coco";

    replaceSpaces(s, '*');

    printf("%s", s);
}
*/

/*

//Write a function void largestWord(char *sentence, char *largest) that finds the largest word in a 
//sentence and stores it in the provided largest array.


void largestWord(char *s, char *largest) {
    int i = 0;            // Index for traversing the string
    int maxLen = 0;       // Maximum word length
    int currentLen = 0;   // Current word length
    int start = 0;        // Start index of the current word
    int maxStart = 0;     // Start index of the largest word

    for (i = 0; ; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            // End of a word
            if (currentLen > maxLen) {
                maxLen = currentLen;
                maxStart = start; // Update starting index of the largest word
            }
            currentLen = 0;       // Reset length for the next word
            start = i + 1;        // Update start position for the next word
        } else {
            currentLen++;         // Increment current word length
        }

        if (s[i] == '\0') break; // End of the sentence
    }

    // Copy the largest word into the output array
    for (i = 0; i < maxLen; i++) {
        largest[i] = s[maxStart + i];
    }
    largest[maxLen] = '\0'; // Null-terminate the output string
}

int main() {
    char sentence[200] = "Programming is really fun and eduhhhcationalll";
    char largest[200];

    largestWord(sentence, largest);

    printf("The largest word is: %s\n", largest);
    return 0;
}

*/

/*

//write a function void removeVowels(char * s) that removes all bvowels from a 
//given string, shifting the remaining characters to fill the gaps

int isVowel(char ch){
    if(ch == 'A' || ch == 'a' || ch == 'E' || ch == 'e' || ch == 'I' || ch == 'i' || ch == 'O' || ch == 'o' || ch == 'U' || ch == 'u'){
        return 1;
    }

    return 0;
}

void removeVowels(char * s){
    int i, j;

    for(i = j = 0; s[i] != '\0'; i++){
        if(isVowel(s[i]) != 1){
            s[j++] = s[i];
        }
    }

    s[j] = '\0';
}

int main(){
    char msg[30] = "booooOoooas manos";

    removeVowels(msg);

    printf("%s", msg);
}

*/


/*
//write a function int countWords(char * s) that counts the number of words in a string

int countWords(char * s){
    int i, count = 0, inWord = 0;

    for (i = 0; s[i] != '\0'; i++){
        if(s[i] != ' ' && s[i] != '\t' && s[i] != '\n'){
            if(!inWord){
                count++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
    }

    return count;
}

int main(){
    char sentence[200] = "  Hello i guys  wassup ";
    int wordcount = countWords(sentence);

    printf("The number of words is: %d\n", wordcount);
    return 0;
}
*/
