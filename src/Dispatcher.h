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

#ifndef BONDAR_DISPATHCER
#define BONDAR_DISPATHCER

#include "Listener.h"
#include "events.h"
#include "task.h"

class Dispatcher {

private:

    /**
     * 5 actuators, printers and middleware per event
     */

    Listener* listeners[N_MAX_EVENTS][N_PER_EVENT];

    process_t processes[MAX_NUMBER_OF_TASKS_PER_DEVICE];

    void markStoppedRunning(uint8_t process_id);
    const process_t getProcessData(uint8_t process_id);

    Dispatcher();
    Dispatcher(Dispatcher& d) {}

    bool started;

    static void listenerTask(void* eventStruct);

    uint8_t findFirstEventProcess(boolean_t& found);

public:

    static Dispatcher& instance();

    static void reset();

    error_t start();

    /**
     * Events are defined in the events.h file
     */

    void subscribe(Event event, Listener* actuator);

    bool isStarted();

    void dispatch(Event event, void* data);

};

#endif
