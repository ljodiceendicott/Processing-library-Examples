int x=360;
void setup(){
size(360,360);
stroke(255);
frameRate(30);
}
void draw() { 
  background(0);   // Clear the screen with a black background
  x = x - 1; 
  if (x < 0) { 
    x = width; 
  } 
  line(0, height, x,0 );  
} 
