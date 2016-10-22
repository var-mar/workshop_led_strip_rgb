PImage img;

void setup() {
  size(75, 1); // Canvas size, in this case LED stripe size/pixels
  //tint(50, 50, 50, 255); //Modify to change colors
  serialConect(); //Serial port function
  loadGradient(); //Gradient function
}

void draw() {

  background(0, 255, 255);
  //Modify to change colors
  //tint(50, 50, 50, 255); 
  image(img, 0, 0);

  //Send data function
  sendPixels();
}

void loadGradient() { 
  
  img = loadImage("RGBAline.png");
}