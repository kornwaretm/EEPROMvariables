#ifndef EEPROM_VARIABLES
#define EEPROM_VARIABLES

#include "Arduino.h"
#include "EEPROM.h"

class EEPROMvariables
{
	public:
		void clear();
		void dump();
		void declare(String n, int l);
		void write(String n, String v);
		String read(String n);
		
	private:
		int findEmpty();
		int find(String n);
		unsigned int readInt(int a);
		void writeInt(int a, int v);
};

#endif