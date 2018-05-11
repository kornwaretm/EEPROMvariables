# EEPROMvariables
arduino library for managing data inside EEPROM.

## Data format
a very simple data format implemented, further improvement required. inside EEPROM data are looke like this :
```
[variable name][space][2 byte integer start][space][2 byte integer end][space][data sequence]
```

## Usage
to use the library simply include the header file, and declare an instance
```
#include <EEPROMvariables.h>
EEPROMvariables eevars;
```

## Functions
the library helps to write and edit the data using very simple functions.

- ### clear();
clear entire content of EEPROM
```
eevars.clear();
```

- ### declare([variable name],[data length])
declaring a variable with name identification and desired data length
```
eevars.declare("ip", 15);
```

- ### write([variable name], [content])
writing string to a variable.
```
eevars.write("ip","192.168.101.191");
```

- ### read([variable name])
read the content of variable from the EEPROM
```
String data = eevars.read("ip");
```

- ### dump()
output all content of EEPROM to serial. Don't forget to call Serial.begin(9600);
```
eevars.dump();
```