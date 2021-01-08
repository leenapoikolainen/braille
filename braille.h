#ifndef BRAILLE_H
#define BRAILLE_H

#include <fstream>
#include <iostream>

int encode_character(char ch, char *braille);
void encode(const char *text, char *braille);
void print_braille(const char *text, std::ostream &out);
#endif
