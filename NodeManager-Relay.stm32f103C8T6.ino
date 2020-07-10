/*
 * The MySensors Arduino library handles the wireless radio link and protocol
 * between your home built sensors/actuators and HA controller of choice.
 * The sensors forms a self healing radio network with optional repeaters. Each
 * repeater and gateway builds a routing tables in EEPROM which keeps track of
 * the network topology allowing messages to be routed to nodes.
 *
 * Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
 * Copyright (C) 2013-2017 Sensnology AB
 * Full contributor list:
 * https://github.com/mysensors/Arduino/graphs/contributors
 *
 * Documentation: http://www.mysensors.org
 * Support Forum: http://forum.mysensors.org
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 */

#define ARDUINO_ARCH_STM32F1

// #define BATTERY_PIN A0
// #define BATTERY_VOLTS_PER_BIT 0.004336918
#define BATTERY_MIN_VOLTAGE 2.0 // Voltage at 0% battery level
#define BATTERY_MAX_VOLTAGE 3.6 // Voltage at 100% battery level

/**********************************
 * MySensors node configuration
 */

// General settings
#define SKETCH_NAME "NodeManager-Relay"
#define SKETCH_VERSION "1.0"
#define MY_DEBUG
//#define MY_NODE_ID 99

// NRF24 radio settings
#define MY_RADIO_NRF24
//#define MY_RF24_ENABLE_ENCRYPTION
#define MY_RF24_CHANNEL (10)
#define MY_RF24_PA_LEVEL RF24_PA_MAX
// #define MY_DEBUG_VERBOSE_RF24
#define MY_RF24_DATARATE RF24_250KBPS

// Message signing settings
//#define MY_SIGNING_SOFT
//#define MY_SIGNING_SOFT_RANDOMSEED_PIN 7
//#define MY_SIGNING_REQUEST_SIGNATURES
//#define MY_SIGNING_ATSHA204
//#define MY_SIGNING_ATSHA204_PIN 4
//#define MY_SIGNING_REQUEST_SIGNATURES

// OTA Firmware update settings
//#define MY_OTA_FIRMWARE_FEATURE
//#define OTA_WAIT_PERIOD 300
//#define FIRMWARE_MAX_REQUESTS 2
//#define MY_OTA_RETRY 2

// OTA debug output
//#define MY_DEBUG_OTA (0)
//#define MY_OTA_LOG_SENDER_FEATURE
//#define MY_OTA_LOG_RECEIVER_FEATURE
//#define MY_DEBUG_OTA_DISABLE_ACK

// Advanced settings
#define MY_BAUD_RATE 115200
//#define MY_SMART_SLEEP_WAIT_DURATION_MS 500
// #define MY_SPLASH_SCREEN_DISABLED
//#define MY_DISABLE_RAM_ROUTING_TABLE_FEATURE
//#define MY_SIGNAL_REPORT_ENABLED

// Optimizations when running on 2032 Coin Cell. Also set
// nodeManager.setSleepBetweenSend(500) and run the board at 1Mhz
//#define MY_TRANSPORT_UPLINK_CHECK_DISABLED
//#define MY_TRANSPORT_WAIT_READY_MS  5000
// #define MY_TRANSPORT_WAIT_READY_MS  3000
//#define MY_SLEEP_TRANSPORT_RECONNECT_TIMEOUT_MS 2000
// #define MY_PARENT_NODE_ID 0
// #define MY_PARENT_NODE_IS_STATIC

/***********************************
 * NodeManager configuration
 */

#define NODEMANAGER_DEBUG ON
#define NODEMANAGER_INTERRUPTS OFF
#define NODEMANAGER_SLEEP ON
#define NODEMANAGER_RECEIVE ON
#define NODEMANAGER_DEBUG_VERBOSE OFF
#define NODEMANAGER_POWER_MANAGER OFF
#define NODEMANAGER_CONDITIONAL_REPORT ON
#define NODEMANAGER_EEPROM ON
#define NODEMANAGER_TIME OFF
#define NODEMANAGER_RTC OFF
#define NODEMANAGER_SD OFF
#define NODEMANAGER_HOOKING OFF
#define NODEMANAGER_OTA_CONFIGURATION ON
#define NODEMANAGER_SERIAL_INPUT OFF

#define MY_REPEATER_FEATURE

// import NodeManager library (a nodeManager object will be then made available)
#include <MySensors_NodeManager.h>

/***********************************
 * Add your sensors
 */

// PowerManager power(5,6);

#include <sensors/SensorBattery.h>
SensorBattery battery;

#include <sensors/SensorRelay.h>
SensorRelay relay1(PA10, 1);
SensorRelay relay2(PA11, 2);
SensorRelay relay3(PA12, 3);
SensorRelay relay3(PA15, 4);

/***********************************
 * Main Sketch
 */

// before
void before() {

  /***********************************
   * Configure your sensors
   */

  // EXAMPLES:
  // report measures of every attached sensors every 10 seconds
  // nodeManager.setReportIntervalSeconds(10);
  // report measures of every attached sensors every 10 minutes
  // nodeManager.setReportIntervalMinutes(10);
  // set the node to sleep in 30 seconds cycles
  // nodeManager.setSleepSeconds(30);
  // set the node to sleep in 5 minutes cycles
  // nodeManager.setSleepMinutes(5);
  // report battery level every 10 minutes
  // battery.setReportIntervalMinutes(10);
  // set an offset to -1 to a thermistor sensor
  // thermistor.setOffset(-1);
  // change the id of a the first child of a sht21 sensor
  // sht21.children.get(1)->setChildId(5);
  // report only when the analog value is above 40%
  // analog.children.get(1)->setMinThreshold(40);
  // power all the nodes through dedicated pins
  // nodeManager.setPowerManager(power);

  // battery.setBatteryInternalVcc(false);
  // battery.setBatteryPin(BATTERY_PIN);
  // battery.setBatteryVoltsPerBit(BATTERY_VOLTS_PER_BIT);
  battery.setBatteryInternalVcc(true);
  battery.setMinVoltage(BATTERY_MIN_VOLTAGE);
  battery.setMaxVoltage(BATTERY_MAX_VOLTAGE);

  // set reporting interval for all the sensors to 10 minutes
  nodeManager.setReportIntervalSeconds(600);

  // call NodeManager before routine
  nodeManager.before();
}

// presentation
void presentation() {
  // call NodeManager presentation routine
  nodeManager.presentation();
}

// setup
void setup() {
  // call NodeManager setup routine
  nodeManager.setup();
}

// loop
void loop() {
  // call NodeManager loop routine
  nodeManager.loop();
}

#if NODEMANAGER_RECEIVE == ON
// receive
void receive(const MyMessage &message) {
  // call NodeManager receive routine
  nodeManager.receive(message);
}
#endif

#if NODEMANAGER_TIME == ON
// receiveTime
void receiveTime(unsigned long ts) {
  // call NodeManager receiveTime routine
  nodeManager.receiveTime(ts);
}
#endif
