
// declare polyline, an ArrayList made out of PVector elements
ArrayList<PVector> polyline = new ArrayList<PVector>();

// declare resampled, an ArrayList made out of PVector elements
ArrayList<PVector> resampled = new ArrayList<PVector>();

void setup() {

  // create canvas
  size(1024, 768);

  // noStroke, red fill
  noStroke();
  fill(255, 0, 0);
}

void draw() {

  // black background
  background(0, 0, 0);

  for (int i = 0; i < resampled.size(); i++) {
    ellipse(resampled.get(i).x, resampled.get(i).y, 20, 20);
  }
}

// while mouse is dragged, create PVector with current mouse position and add to polyline
void mouseDragged() {

  polyline.add(new PVector(mouseX, mouseY));

  //println("polyline.size() : " + polyline.size());
  //println("resampled.size() : " + resampled.size());

  // if resampled is empty, add first element
  if (resampled.size() == 0) {
    resampled.add(new PVector(polyline.get(0).x, polyline.get(0).y));
  }
  // in other case
  else {

    int resampledLast = resampled.size() - 1;
  
    // x1, y1 is newest PVector in resampled 
    float x1 = resampled.get(resampledLast).x;
    float y1 = resampled.get(resampledLast).y;

    // x2, y2 is last PVector in polyline 
    float x2 = polyline.get(polyline.size() - 1).x;
    float y2 = polyline.get(polyline.size() - 1).y;
    
    // variable for storing the distance between x1,y1 and x2,y2
    float measure = 0;

    if (x1 != x2 && y1 != y2) {
      measure = dist(x1, y1, x2, y2);
    }

    // if distance is bigger than 20, append new PVector to resampled
    if (measure > 20) {
      
      // calculate angle
      float theta = atan2(y2 - y1, x2 - x1);

      // calculate x,y of new PVector in resampled
      float newX = x1 + 20 * cos(theta);
      float newY = y1 + 20 * sin(theta);

      resampled.add(new PVector(newX, newY));
    }
  }
}

// when mouse is pressed, clear polyline
void mousePressed() {

  while (polyline.size() > 0) {
    polyline.remove(0);
  }

  while (resampled.size() > 0) {
    resampled.remove(0);
  }
}
