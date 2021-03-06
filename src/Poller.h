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

#ifndef BONDAR_POLLER
#define BONDAR_POLLER

#include "Bondar.h"
#include "GPS.h"
#include "Accelerometer.h"
#include "Magnetometer.h"
#include "Gyroscope.h"
#include "Barometer.h"
#include "SensTimer.h"

class Poller {

private:

    Poller(uint32_t intervalMs, SensTimer* timer);
    Poller(Poller& p) {}

    GPS* gps;
    Accelerometer* accel;
    Magnetometer* magne;
    Gyroscope* gyro;
    Barometer* bar;

    int32_t interval;
    SensTimer* timer;

    bool started;

    static void tick();

    static void onGPSRead(sensor_data_t* data, error_t error);
    static void onAccelerometerRead(sensor_data_t* data, error_t error);
    static void onMagnetometerRead(sensor_data_t* data, error_t error);
    static void onGyroscopeRead(sensor_data_t* data, error_t error);
    static void onBarometerRead(sensor_data_t* data, error_t error);

    static void onGPSStartDone(error_t error);
    static void onAccelerometerStartDone(error_t error);
    static void onMagnetometerStartDone(error_t error);
    static void onGyroscopeStartDone(error_t error);
    static void onBarometerStartDone(error_t error);

    void readSensors();

public:

    static Poller& instance();

    error_t start();
    error_t stop();

    bool isStarted();

    void attachGPS(GPS* gps);
    void attachAccelerometer(Accelerometer* accel);
    void attachMagnetometer(Magnetometer* magne);
    void attachGyroscope(Gyroscope* gyro);
    void attachBarometer(Barometer* bar);

    GPS* getGPS();
    Accelerometer* getAccelerometer();
    Magnetometer* getMagnetometer();
    Gyroscope* getGyroscope();
    Barometer* getBarometer();


};

#endif
