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

#ifndef BONDAR_MIDDLEWARE
#define BONDAR_MIDDLEWARE

#include "events.h"
#include "Senscape.h"

class Middleware : Listener {

    /**
     * 
     * Middleware take data dispatched with events and transforms it before being dispatched
     * to Printers and Actuators.
     * 
     */

public:

    /**
     * Any *expensive* operation should be done here and not in the constructor
     * Returns: SUCCESS if it has been started or any error defined in error.h otherwise
    */
    virtual error_t start() = 0;

    /**
     * event: one of the event codes defined in events.h
     * data: pointer to data about the event or NULL
    */ 
    virtual void* execute(Event event, void* data) = 0;

};

#endif