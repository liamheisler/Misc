#include "simpletools.h" // Include simple tools
#include "servo.h"
#include "wavplayer.h"
#include "music.h"

int main() 
{
  print("Executing o' christmas tree... \n");
  christmasTree();
  pause(500);  //[ms] 
  print("Executing silent night... \n"); 
  silentNight();   
}
