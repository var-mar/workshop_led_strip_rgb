import processing.serial.*; //Library Serial

Serial myPort; //Serial port name

void serialConect(){
  
  // Print list of available serial ports (Useful for debugging).
  println ("Available serial ports:  ");
  printArray(Serial.list());
  println (" ");
  
  // Serial port to be used.  Change number in [brackets] as needed.
  String portName = Serial.list()[1]; // <--- *port number*
  
  // Serial port conected.
  println("Conected: ");
  println("Port " + portName);
  println (" ");
  myPort = new Serial(this,portName, 115200);  // Create the serial port.
  myPort.clear();   // Clear the serial port buffer.
}