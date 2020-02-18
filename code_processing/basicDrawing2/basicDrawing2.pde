
// declare polyline, an ArrayList made out of PVector elements
ArrayList<PVector> polyline = new ArrayList<PVector>();

void setup() {

  // create canvas
  size(1024, 768);

  // white stroke
  stroke(255);
}

void draw() {
  
  // black background
  background(0, 0, 0);
  
  // go through every PVector element in the Arraylist polyline
  for (int i = 0; i < polyline.size(); i++) {
    // for all elements except for the last one
    if (i + 1 < polyline.size()) {
      // draw a line between current element and the next one
      line(polyline.get(i).x, polyline.get(i).y, polyline.get(i+1).x, polyline.get(i+1).y);
    }
  }
}

// while mouse is dragged, create PVector with current mouse position and add to polyline
void mouseDragged() {
  polyline.add(new PVector(mouseX, mouseY));
}

// when mouse is pressed, clear polyline
void mousePressed() {
  while (polyline.size() > 0) {
    polyline.remove(0);
  }
}
