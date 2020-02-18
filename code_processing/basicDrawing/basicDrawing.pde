// declare diameter
int diameter = 20;


void setup() {
  
  // create canvas
  size(1024, 768);
  
  // black background
  background(0, 0, 0);
  
  // by default drawing of shapes uses
  // black stroke, 1 px wide
  // white filling
  // noStroke() disables the drawing stroke
  // https://processing.org/reference/noStroke_.html
  noStroke();
}

void draw() {
}

void mouseDragged() {
  // https://processing.org/reference/ellipse_.html
  ellipse(mouseX, mouseY, diameter, diameter);
}
