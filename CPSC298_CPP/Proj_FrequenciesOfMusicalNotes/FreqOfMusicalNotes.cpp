/// @file FreqOfMusicalNotes.cpp
/// @brief computes tyhe frequency and wavelength of 6 notes
/// @author Kentaro Matsuo
#include<math.h>
#include <iostream>
using namespace std;
int main()
{
  double freq;
  double referenceFreq = 16.35;
  double v = 0;
  double k = 0;
  double wavelength;

  freq = referenceFreq*pow(2,v)*pow(2,(k/12));
  wavelength = 345/freq;
  cout << "C0; v: " << v << " k: " << k << "; frequency: " << freq << " Hz; wavelength: " << wavelength << " cm\n";

  v = 0;
  k = 1;
  freq = referenceFreq*pow(2,v)*pow(2,(k/12));
  wavelength = 345/freq;
  cout << "C#0; v: " << v << " k: " << k << "; frequency: " << freq << " Hz; wavelength: " << wavelength << " cm\n";

  v = 0;
  k = 2;
  freq = referenceFreq*pow(2,v)*pow(2,(k/12));
  wavelength = 345/freq;
  cout << "D0; v: " << v << " k: " << k << "; frequency: " << freq << " Hz; wavelength: " << wavelength << " cm\n";

  v = 4;
  k = 0;
  freq = referenceFreq*pow(2,v)*pow(2,(k/12));
  wavelength = 345/freq;
  cout << "C4; v: " << v << " k: " << k << "; frequency: " << freq << " Hz; wavelength: " << wavelength << " cm\n";

  v = 7;
  k = 3;
  freq = referenceFreq*pow(2,v)*pow(2,(k/12));
  wavelength = 345/freq;
  cout << "D#7; v: " << v << " k: " << k << "; frequency: " << freq << " Hz; wavelength: " << wavelength << " cm\n";

  v = 8;
  k = 0;
  freq = referenceFreq*pow(2,v)*pow(2,(k/12));
  wavelength = 345/freq;
  cout << "C8; v: " << v << "k: " << k << "; frequency: " << freq << " Hz; wavelength: " << wavelength << " cm\n";

  return 0;
}
