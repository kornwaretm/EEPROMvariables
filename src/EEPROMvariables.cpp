#include "EEPROMvariables.h"


void EEPROMvariables::clear()
{
	int i;
	for (i = 0 ; i <= E2END ; i++) {
		EEPROM.write(i, 0);
	}
}

void EEPROMvariables::dump()
{
	int i;
	for (i = 0 ; i <= E2END ; i++) {
		char c = char(EEPROM.read(i));
		if((c!=13)&&(c!=10)&&(c!=0)&&(c!=118)&&(c!=155))
		{
			Serial.write(c);
		}
		else
		{
			Serial.write('.');
		}
		if(((i + 1) % 64) == 0){Serial.println();}
	}
}

void EEPROMvariables::declare(String n, int l)
{
	int pos = findEmpty();
	if(pos < 0) 
	{
		return;
	}
	
	int s = pos + n.length() + 7;
	int i = 0;
	int nl = n.length();
	
	for(i;i<nl ; i++)
	{
		EEPROM.write(pos + i, n.charAt(i));
	}
	i+= pos;
	EEPROM.write(i, ' ');i++;
	writeInt(i, s); i+= 2;
	EEPROM.write(i, ' ');i++;
	writeInt(i, s + l - 1); i += 2;
	EEPROM.write(i, ' ');i++;
}

void EEPROMvariables::write(String n, String v)
{
	int st = find(n);
	int en = readInt(st - 3);
	
	int nl = st + v.length();
	
	for(int i = st; i<= en ; i++)
	{
		if(i <= nl)
		{
			EEPROM.write(i, v.charAt(i - st));
		}
		else
		{
			EEPROM.write(i, '\0');
			return;
		}
	}
}

String EEPROMvariables::read(String n)
{
	String r = "";
	int st = find(n);
	int en = readInt(st - 3);
	char c;
	for(int i = st; i <= en ; i++)
	{
		c = char(EEPROM.read(i));
		if(c == '\0')break;
		r += c;
	}
	return r;
}

int EEPROMvariables::find(String t)
{
	String b = "";
	int i = 0;
	for(i; i <= E2END; i++)
	{
		char c = EEPROM.read(i);
		if(c == 0)
		{
			return i;
		}
		
		if(c == ' ')
		{
			if(t == b)
			{
				i ++; 
				int st = readInt(i);
				return st;
			}
			else
			{
				i +=4; 
				i = readInt(i);
			}
			b = "";
		}
		else
		{
			b += c;
		}
	}
	return -1;
}

int EEPROMvariables::findEmpty()
{
	String b = "";
	int i = 0;
	for(i; i <= E2END; i++)
	{
		char c = EEPROM.read(i);
		if(c == 0)
		{
			return i;
		}
		
		if(c == ' ')
		{
			i+=4; 
			i = readInt(i);
			b = " ";
		}
		else
		{
			b += c;
		}
	}
	return -1;
}

unsigned int EEPROMvariables::readInt(int a)
{
	byte L = EEPROM.read(a);
	byte H = EEPROM.read(a + 1);
	return ((L << 0) & 0xFF) + ((H << 8) & 0xFF00);
}

void EEPROMvariables::writeInt(int a, int v)
{
	byte L = ((v >> 0) & 0xFF);
	byte H = ((v >> 8) & 0xFF);
	EEPROM.write(a, L);
	EEPROM.write(a + 1, H);
}