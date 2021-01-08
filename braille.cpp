#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include "braille.h"

using namespace std;

// Function that converst a text into braille & prints it out in ASCII
// into defined output stream
void print_braille(const char *text, ostream &out) {
  char braille[100];
  strcpy(braille,"");
  encode(text, braille);
  int size = strlen(braille);
  int space = 0;
  // starting from 0, print every 3rd char
  for (int i = 0; i < size; i = i + 3) {
    out << braille[i];
    space++;
    if (space % 2 == 0) {
      out << ' ';
    }
  }
  out << endl;
  // starting from 1, print every 3rd char
  for (int i = 1; i < size; i = i + 3) {
    out << braille[i];
    space++;
    if (space  % 2 == 0)
      out << ' ';
  }
  out << endl;
  // starting from 2, print every 3rd char
  for (int i = 2; i < size; i = i + 3) {
    out << braille[i];
    space++;
    if (space % 2 == 0)
      out << ' ';
  }
  out << endl;

  char word[100];
  int word_size = strlen(text);
  int index = 0;
  for (int i = 0; i < word_size && index < 100 ; i++) {
    if (isupper(text[i]) || isdigit(text[i])) {
      word[index++] = ' ';
      word[index++] = ' ';
      word[index++] = ' ';
      word[index++] = text[i];
    }
    else {
      word[index++] = text[i];
    }
    word[index++] = ' ';
    word[index++] = ' ';
  }
  word[index] = '\0';
  out << word;
}

// Function to encode a text into braille string
void encode(const char *text, char *braille){
  if (*text == '\0')
    return;
  else {
    char encoded[20];
    strcpy(encoded,"");
    encode_character(*text, encoded);
    strcat(braille, encoded);
    encode(text + 1, braille);
  }
}

// Function to encode into braille string and return it's size
int encode_character(char ch, char *braille){
  // Ensure the braille string is empty
  strcpy(braille, "");

  // 1. If ch is an alphabet
  if(isalpha(ch)){
    // Add capital letter braille, if it is a capital letter
    if(isupper(ch)) {
      strcat(braille, ".....O");
    }
    // Convert to lower
    ch = tolower(ch);
    switch (ch) {
    case 'a': strcat(braille, "O....."); break;
    case 'b': strcat(braille, "OO...."); break;
    case 'c': strcat(braille, "O..O.."); break;
    case 'd': strcat(braille, "O..OO."); break;
    case 'e': strcat(braille, "O...O."); break;
    case 'f': strcat(braille, "OO.O.."); break;
    case 'g': strcat(braille, "OO.OO."); break;
    case 'h': strcat(braille, "OO..O."); break;
    case 'i': strcat(braille, ".O.O.."); break;
    case 'j': strcat(braille, ".O.OO."); break;
    case 'k': strcat(braille, "O.O..."); break;
    case 'l': strcat(braille, "OOO..."); break;
    case 'm': strcat(braille, "O.OO.."); break;
    case 'n': strcat(braille, "O.OOO."); break;
    case 'o': strcat(braille, "O.O.O."); break;
    case 'p': strcat(braille, "OOOO.."); break;
    case 'q': strcat(braille, "OOOOO."); break;
    case 'r': strcat(braille, "OOO.O."); break;
    case 's': strcat(braille, ".OOO.."); break;
    case 't': strcat(braille, ".OOOO."); break;
    case 'u': strcat(braille, "O.O..O"); break;
    case 'v': strcat(braille, "OOO..O"); break;
    case 'w': strcat(braille, ".O.OOO"); break;
    case 'x': strcat(braille, "O.OO.O"); break;
    case 'y': strcat(braille, "O.OOOO"); break;
    case 'z': strcat(braille, "O.O.OO"); break;
    }
  }
  if(isdigit(ch)) {
    // If it is digit, add the digit braille string first
    strcat(braille, "..OOOO");
    switch(ch) {
    case '1': strcat(braille, "O....."); break;
    case '2': strcat(braille, "OO...."); break;
    case '3': strcat(braille, "O..O.."); break;
    case '4': strcat(braille, "O..OO."); break;
    case '5': strcat(braille, "O...O."); break;
    case '6': strcat(braille, "OO.O.."); break;
    case '7': strcat(braille, "OO.OO."); break;
    case '8': strcat(braille, "OO..O."); break;
    case '9': strcat(braille, ".O.O.."); break;
    case '0': strcat(braille, ".O.OO."); break;
    }
  }
  if(ispunct(ch)){
    switch (ch) {
    case '.': strcat(braille, ".O..OO"); break;
    case ',': strcat(braille, ".O...."); break;
    case ';': strcat(braille, ".OO..."); break;
    case '-': strcat(braille, "..O..O"); break;
    case '!': strcat(braille, ".OO.O."); break;
    case '?': strcat(braille, ".OO..O"); break;
    case '(': 
    case ')': strcat(braille, ".OO.OO"); break;
    }
  }
  int size = strlen(braille);
  return size;
}

