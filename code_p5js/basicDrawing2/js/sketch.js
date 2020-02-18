// declare array called polyline
let polyline = [];

function setup() {

  // create canvas
  createCanvas(1024, 768);

  // white stroke
  stroke(255);

}

function draw() {

  // black background
  background(0, 0, 0);

    // go through every vector element in the array polyline
    for (let i = 0; i < polyline.length; i++) {
      // for all elements except for the last one
      if (i + 1 < polyline.length) {
        // draw a line between current element and the next one
        line(polyline[i].x, polyline[i].y, polyline[i+1].x, polyline[i+1].y);
      }
    }
}

// while mouse is dragged
// create vector with current mouse position and add to polyline
function mouseDragged() {
  polyline.push(createVector(mouseX, mouseY));
}

// when mouse is pressed, clear polyline
function mousePressed() {
  if (polyline.length > 0) {
    polyline = [];
  }
}
