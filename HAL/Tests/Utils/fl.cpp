/*******************************************************************************
* source/logging/FileLogger.t.cpp
* Author: Ángel Pérez
*
* 15/8/2020 - Version 1.0
*******************************************************************************/

/* Include section
*******************************************************************************/
#include <assert.h>
#include "Utils/FileLogger.h"
#include <unistd.h>
#include <thread>

using namespace utils;

/* Defines section
*******************************************************************************/


/* Function definitions
*******************************************************************************/
static void oneMessageTest(std::string message);

static void multipleMessageTest(int nMessages, std::string message);

static void concurrentMessagesTest(int nMessagesPerThread, int nThreads);

static void changingFileName(std::string newFileName, std::string message);

/* Function definitions
*******************************************************************************/


int main2 () {

	oneMessageTest("oneMessageTest.");

	multipleMessageTest(22, "multipleMessageTest.");
	concurrentMessagesTest(5, 30);

	changingFileName("log_cp.txt", "changingFileName.");

	return 0;
}


void oneMessageTest(std::string message){
	FileLogger fileLogger("log.txt");
	fileLogger.LOG(Info, message);
}

void multipleMessageTest(int nMessages, std::string message) {
	FileLogger fileLogger("log.txt");
	for (int i = 0; i < nMessages; ++i) {
		fileLogger.LOG(Alert, message);
		usleep(10000);
	}
}

void concurrentMessagesTest(int nMessagesPerThread, int nThreads) {
	std::thread threads [nThreads];
	for (int i = 0; i < nThreads; ++i) {
		std::string message = "I am thread" + std::to_string(i) + ".";
		threads[i] = std::thread(&multipleMessageTest, nMessagesPerThread, message);
	}

	for (int i = 0; i < nThreads; ++i) {
		threads[i].join();
	}
}

void changingFileName(std::string newFileName, std::string message) {
	FileLogger fileLogger("log.txt");
	fileLogger.LOG(Warning, message);

	fileLogger.setFileName(newFileName);
	fileLogger.LOG(Warning, message);
}
