/*
    Bondar avionics
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

#ifndef BONDAR_LISTENER
#define BONDAR_LISTENER

#include "events.h"
#include "Variant.h"

class Listener {

public:
    virtual error_t start() = 0;

    virtual error_t stop() = 0;

    virtual bool isStarted() = 0;

    virtual void execute(Event e, Variant data) = 0;

};

#endif
