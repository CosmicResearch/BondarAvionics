/*
 Bondar avionics - tests
 Copyright (C) 2017  Associació Cosmic Research
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SENSCAPE_H_
#define SENSCAPE_H_

#include <ctype.h>
#include <stdint.h>
#include <iostream>
#include <unordered_map>

#define ERROR 1
#define SUCCESS 0

#define HIGH 1
#define LOW 0

#define INPUT 1
#define OUTPUT 0

typedef bool boolean_t;
typedef unsigned char byte_t;
//typedef unsigned char error_t;
typedef float float_t;
//typedef unsigned char error_t;

error_t postTask(void (*function)(void*), void *param);

void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t value);
bool digitalRead(uint8_t pin);

void defineReadingForPin(uint8_t pin, bool reading);

void wait(uint16_t time);

#endif