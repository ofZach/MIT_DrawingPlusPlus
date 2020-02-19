// declare arrays for storing lines
let polyline = [];
let resampled = [];

function setup() {

  // create canvas
  createCanvas(1024, 768);

  // noStroke, red fill
  noStroke();
  fill(255, 0, 0);
}

function draw() {
  // black background
  background(0, 0, 0);

    for (let i = 0; i < resampled.length; i++) {
    ellipse(resampled[i].x, resampled[i].y, 20, 20);
  }
}

// while mouse is dragged, create PVector with current mouse position and add to polyline
function mouseDragged() {

  polyline.push(createVector(mouseX, mouseY));

    // if resampled is empty, add first element
  if (resampled.length == 0) {
    resampled.push(createVector(polyline[0].x, polyline[0].y));
  }
  // in other case
  else {
      
    let resampledLast = resampled.length - 1;

    // x1, y1 is newest PVector in resampled 
    let x1 = resampled[resampledLast].x;
    let y1 = resampled[resampledLast].y;

    // x2, y2 is last PVector in polyline 
    let x2 = polyline[polyline.length - 1].x;
    let y2 = polyline[polyline.length - 1].y;
    
    // variable for storing the distance between x1,y1 and x2,y2
    let measure = 0;

    if (x1 != x2 && y1 != y2) {
      measure = dist(x1, y1, x2, y2);
    }

    // if distance is bigger than 20, append new PVector to resampled
    if (measure > 20) {
        
        // calculate angle
        let theta = atan2(y2 - y1, x2 - x1);

        // calculate x,y of new PVector in resampled
        let newX = x1 + 20 * cos(theta);
        let newY = y1 + 20 * sin(theta);

        resampled.push(createVector(newX, newY));
    }
  }
}

// when mouse is pressed, clear lines
function mousePressed() {
  if (polyline.length > 0) {
    polyline = [];
  }
  if (resampled.length > 0) {
    resampled = [];
  }
}
  

