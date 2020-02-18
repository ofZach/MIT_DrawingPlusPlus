let diameter = 20;

function setup() {

  // create canvas
  createCanvas(1024, 768);

  // black background
  background(0, 0, 0);

  noStroke();

}

function draw() {
}

function mouseDragged() {
  ellipse(mouseX, mouseY, diameter, diameter);
}
