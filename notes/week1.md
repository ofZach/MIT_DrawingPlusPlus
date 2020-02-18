# Notes from class MAS.S62 DrawingPlusPlus, by Zach Lieberman

## Class 1: Tuesday February 18 2020

Assignment for next class:

* Readings 
* Install and setup openFrameworks
* Document all the drawings you encounter until next class.

Programming notes:

```cpp
// set background
ofBackground(0);

// draw a circle on mouse position if mouse is pressed
if (ofGetMousePressed()) {
  ofDrawCircle(mouseX, mouseY, 20);
}
```

If we need objects to be accesible across multiple frames or methods, we can declare them on the header .h file.

```cpp
// declare a line
ofPolyline line;
// draw a line
line.draw();
// delete a line
line.clear();
```

```cpp
// add random noise to a line
for (int i = 0; i < line.size(); i++) {
  line[i].x += ofRandom(-1, 1);
  line[i].y += ofRandom(-1, 1);
}
```


```cpp
// retrieve time
float time = ofGetElapsedTimef();
```

```cpp
// resample a line
ofPolyline resampled = line.getResampledBySpacing(10);
```

## Class 2: Wednesday February 19 2020

## Class 3: Thursday February 20 2020

## Class 4: Friday February 20 2020
