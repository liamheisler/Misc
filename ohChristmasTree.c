/*
Oh Christmas Tree
This Program will allow the programmer to easily change the tempo, key and pin wiring for this melody
This will also serve as a template for easily programming new melodies into the Propeller
*/

#include "simpletools.h"

int qnt = 550; //sets the standard for a quarter note

float BaseNote = 300; //establishes the key of the melody

int PIN = 4; //This determines which pin the speaker is wired to.

//double Asharp,B,C,Csharp,D,Dsharp,E,F,Fsharp,G,Gsharp;

#define A 0
#define Asharp 1
#define B 2
#define C 3
#define Csharp 4
#define D 5
#define Dsharp 6
#define E 7
#define F 8
#define Fsharp 9
#define G 10
#define Gsharp 11

void Octave(float Abase, int *notes);      //   declares the function Octave.

int main()
{
  int notes[12];                              //establishes an array called “notes”  with 12 elements

  Octave(BaseNote,notes);          //calls the octave function and sets the base frequency

   //These print statements verify note values that the   Propeller is using
  print("the freq of notes[B] is %d\n",notes[B]);
  print("the freq of notes[A] is %d\n",notes[A]);
  print("the freq of notes[E] is %d\n",notes[E]);
  print("the freq of A2 is %d\n",2*(int)notes[A]);

  while(1)
  {
    freqout(PIN,qnt,notes[C]);
    freqout(PIN,qnt/2,notes[F]);
    freqout(PIN,qnt/2,notes[F]);
    freqout(PIN,qnt,notes[F]);
    freqout(PIN,qnt,notes[G]);
    freqout(PIN,qnt/2,2*notes[A]);
    freqout(PIN,qnt/2,2*notes[A]);
    freqout(PIN,3*qnt/2,2*notes[A]);
    freqout(PIN,qnt/4,2*notes[A]);

    freqout(PIN,qnt/2,notes[G]);
    //freqout(PIN,qnt,notes[F]);
    freqout(PIN,qnt/2,2*notes[A]);
    freqout(PIN,qnt,2*notes[Asharp]);
    freqout(PIN,qnt,notes[E]);
    freqout(PIN,qnt/2,notes[G]);
    freqout(PIN,qnt/2,notes[F]);
    freqout(PIN,qnt,notes[F]);
    freqout(PIN,qnt/2,notes[F]);
    //freqout(PIN,qnt/2,notes[Csharp]);
    freqout(PIN,qnt/2,notes[F]);
    freqout(PIN,qnt/2,notes[F]);
    freqout(PIN,qnt,notes[F]);
    freqout(PIN,qnt,notes[G]);

    freqout(PIN,qnt/2,2*notes[A]);
    freqout(PIN,qnt/2,2*notes[A]);
    freqout(PIN,3*qnt/2,2*notes[A]);
    freqout(PIN,qnt/4,2*notes[A]);
    freqout(PIN,qnt,notes[G]);
    //freqout(PIN,qnt,notes[F]);
    freqout(PIN,qnt/2,2*notes[A]);
    freqout(PIN,qnt,2*notes[Asharp]);
    freqout(PIN,qnt,notes[E]);
    freqout(PIN,qnt/2,notes[G]);
    freqout(PIN,qnt/2,notes[F]);
    freqout(PIN,qnt,notes[F]);
    freqout(PIN,qnt,2*notes[C]);

   
    freqout(PIN,qnt/2,2*notes[C]);
    freqout(PIN,qnt/2,2*notes[A]);
    freqout(PIN,3*qnt/2,2*notes[D]);
    freqout(PIN,qnt/4,2*notes[C]);
    freqout(PIN,qnt/2,2*notes[C]);
    freqout(PIN,qnt/2,notes[Asharp]);
    freqout(PIN,qnt,2*notes[Asharp]);
    freqout(PIN,3*qnt/2,2*notes[Asharp]);  
    freqout(PIN,qnt/2,notes[G]);
    freqout(PIN,3*qnt/2,2*notes[C]);
    freqout(PIN,qnt/4,2*notes[Asharp]);

    freqout(PIN,qnt/2,2*notes[Asharp]);
    freqout(PIN,qnt/2,2*notes[A]);
    freqout(PIN,qnt,2*notes[A]);
    freqout(PIN,qnt,notes[C]);
    freqout(PIN,qnt/2,notes[F]);
    freqout(PIN,qnt/2,notes[F]);
    freqout(PIN,qnt,notes[F]);
    freqout(PIN,qnt,notes[G]);
    freqout(PIN,qnt/2,2*notes[A]);
    freqout(PIN,qnt/2,2*notes[A]);
    freqout(PIN,3*qnt/2,2*notes[A]);
    freqout(PIN,qnt/4,2*notes[A]);//MF
    
    freqout(PIN,qnt/2,notes[G]);
    //freqout(PIN,qnt,notes[F]);
    freqout(PIN,qnt,2*notes[Asharp]);
    freqout(PIN,qnt,2*notes[E]);
    freqout(PIN,qnt/2,notes[G]);
    freqout(PIN,qnt/2,notes[F]);
    freqout(PIN,2*qnt,notes[F]);

    freqout(PIN,qnt/2,notes[G]);
    freqout(PIN,qnt/2,notes[F]);
    freqout(PIN,2*qnt,notes[F]);
    freqout(PIN,qnt/2,notes[G]);
    freqout(PIN,qnt/2,notes[F]);
    freqout(PIN,2*qnt,notes[F]);

  }
}

void Octave(float Abase, int *notes)
{
  float n = 0.083333; //  This decimal is 1/12  that is 12 steps in an octave.
   for (int i = 0; i < 12; i++)
  {
    notes[i] = (int)(Abase * pow(2, i * n));
  }
}

/*void Octave(float Abase, int *notes)  // this accomplishes the same thing without using a for loop. 

{
  float n = 0.083333; // set the power function

  notes[0] = Abase*pow(2,0*n);                //all of the notes A#-G# in the octave above
  notes[1] = Abase*pow(2,n);
  notes[2] = Abase*pow(2,2*n);
  notes[3] = Abase*pow(2,3*n);
  notes[4] = Abase*pow(2,4*n);
  notes[PIN] = Abase*pow(2,PIN*n);
  notes[6] = Abase*pow(2,6*n);
  notes[7] = Abase*pow(2,7*n);
  notes[8] = Abase*pow(2,8*n);
  notes[9] = Abase*pow(2,9*n);
  notes[10] = Abase*pow(2,10*n);
  notes[11] = Abase*pow(2,11*n);
}
*/
