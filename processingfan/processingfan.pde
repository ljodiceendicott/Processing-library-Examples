import processing.serial.*;

Serial myPort;    

void setup(){
  size(640,480);
   // List all the available serial ports:
  printArray(Serial.list());

  // Open the port you are using at the rate you want:
  if(Serial.list().length == 0){
    // print unhappy message to user: "plug in your Arduino"
  }
  myPort = new Serial(this, Serial.list()[2], 9600);
}

void draw(){
  textSize(32);
  if(myPort.available()>0){
  char num=myPort.readChar();
  //if the port reads that the ultrasonic sensor is too far away
  if(num=='0'){
    background(0);
    text("too far", width/2, height/2);
  }
  else{
    //if the sensor is within the set distance
    background(100);
    text("good", width/2, height/2);
  }
  }
}
