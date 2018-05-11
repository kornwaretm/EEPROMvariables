#include <EEPROMvariables.h>

EEPROMvariables eevars;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  eevars.clear();
  
  eevars.declare("host", 15);
  eevars.write("host","172.168.101.120");
  
  eevars.declare("port", 2);
  eevars.write("port", "80");

  eevars.declare("db_host", 15);
  eevars.write("db_host", "172.168.101.120");

  eevars.declare("db_user", 4);
  eevars.write("db_user", "root");

  eevars.declare("db_password", 8);
  eevars.write("db_passwordt", "db_pass1");

  eevars.declare("db_name", 15);
  eevars.write("db_name", "super_cloud");

  eevars.dump();

  
}

void loop() {
  // put your main code here, to run repeatedly:

}
