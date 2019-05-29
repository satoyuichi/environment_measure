#include <LedControl.h>

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,11,10,1);

void setup() {
	lc.shutdown(0,false);
	lc.setIntensity(0,8);
	lc.clearDisplay(0);
}

void loop() {
	lc.clearDisplay(0);

	int a2 = analogRead (A2);
	int a5 = analogRead (A5);

	float map_temp = ((5.0f * a5) / 1024.0f) * 100.0f;

	String atmos = String(a2);
	String temp = String(map_temp, 2);

	int c;
	for (int i = 0, len = temp.length(); i < len; i++) {
		c = temp[len - i - 1];
		if (i >= 3) {
			lc.setChar(0, 3 - i + 1, c, i == 3);
		}
		else {
			lc.setChar(0, 3 - i, c,false);
		}
	}

	for (int i = 0, len = atmos.length(); i < len; i++) {
		c = atmos[len - i - 1];
		lc.setChar(0, 7 - i, c, false);
	}

	delay (500);
}
