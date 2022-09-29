/// @file Authenticator.cpp
/// @brief creates a code authenticator system
/// @author Kentaro Matsuo
#include <iostream>
#include <string>
using namespace std;
int main()
{
  char first_;
  char second_;
  char third_;
  const char k_cAuthenticatorCodeCharacter1	=	'E';
  const char k_cAuthenticatorCodeCharacter2	=	'C';
  const char k_cAuthenticatorCodeCharacter3	=	'A';
  cout << "Enter the first character of the message code:\n";
  cin >> first_;
  cout << "Enter the second character of the message code:\n";
  cin >> second_;
  cout << "Enter the third character of the message code:\n";
  cin >> third_;
  string authenticatorCode;
  string messageCode;
  authenticatorCode = authenticatorCode + k_cAuthenticatorCodeCharacter1 + k_cAuthenticatorCodeCharacter2 + k_cAuthenticatorCodeCharacter3;
  messageCode = messageCode + first_ + second_ + third_;
  cout << "Authenticator code: " << authenticatorCode << endl;
  cout << "Message code: " << messageCode << endl;
  if (k_cAuthenticatorCodeCharacter1 == first_ && k_cAuthenticatorCodeCharacter2 == second_ && k_cAuthenticatorCodeCharacter3 == third_)
  {
    cout << "Message is authentic.\n";
  }
  else
  {
    cout << "Message is invalid\n";
  }
  if (authenticatorCode == messageCode)
  {
    cout << "Concurrence: message is authentic.\n";
  }
  else
  {
    cout << "Concurrence: message is invalid.\n";
  }
  const int k_iValidCodeChecksum	=	5;
  int checksum = (int(first_) + int(second_) + int(third_)) % 7;
  if (k_iValidCodeChecksum == checksum)
  {
    cout << "Message code checksum is valid: " << checksum << endl;
  }
  else
  {
    cout << "Message code checksum is invalid: " << checksum << "; expected: " << k_iValidCodeChecksum << endl;
  }
  cout << "ASCII Values of Message Code Characters: " << int(first_) << ", " << int(second_) << ", " << int(third_)<<endl;
  cout << "Sum of ASCII Values for Message Code Characters: " << int(first_) + int(second_) + int(third_) <<endl;
  if (k_cAuthenticatorCodeCharacter1 != first_)
  {
    cout << "First characters do not match: Message: " << first_ << "; Authenticator: " << k_cAuthenticatorCodeCharacter1 << endl;
  }
  if (k_cAuthenticatorCodeCharacter2 != second_)
  {
    cout << "Second characters do not match: Message: " << second_ << "; Authenticator: " << k_cAuthenticatorCodeCharacter2 << endl;
  }
  if (k_cAuthenticatorCodeCharacter3 != third_)
  {
    cout << "Third characters do not match: Message: " << third_ << "; Authenticator: " << k_cAuthenticatorCodeCharacter3 << endl;
  }


  return 0;
}
