#ifndef _SCHEDULE_H
#define _SCHEDULE_H

#include "ofMain.h"
#include "ofxTime.h"
#include "ofThread.h"
#include "extern.h"
#include "ofxTimerEventTable.h"

class SCHEDULE : public ofThread {
	void setup();
	void update();
	void draw();

	void threadedFunction() {
		while (isThreadRunning() != 0) {
			if (lock()) {
				SCHEDULE::update();
				unlock();
			}
			ofSleepMillis(180);                  
		}
	}
private:
};

#endif
