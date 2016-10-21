byte[] stripe = new byte[225];  // 75 Leds * 3 RGB = 225

void sendPixels() {

  // send pixels to serial port when arduino send an signal
  if ( myPort.available() > 0) { 
    capturePixels(); // get pixels from screen
    myPort.clear(); // Clear the serial port buffer.
    myPort.write(stripe);
    print ("Status: ");
    println("Sending");
  }
}

void capturePixels() {
  
  loadPixels();
  // pass pixels to byte buffer to send
  for (int i = 0; i < 75; i++) { 
    stripe[i*3]= (byte)(color(pixels[i])>> 16 & 0xFF);// Red
    stripe[(i*3)+2]= (byte)(color(pixels[i]) & 0xFF);// Blue
    stripe[(i*3)+1]= (byte)(color(pixels[i]) >> 8 & 0xFF); // Green
  }
}