#include <iostream>

class ElectronicControlUnit
{
  public:
    ElectronicControlUnit();
    ~ElectronicControlUnit();
    void handleCommand(char cCommand);

  private:
    bool m_bActivatedHydraulicJacks;
    bool m_bActivatedBeltTires;
    bool m_bActivatedIRIllumination;
};

ElectronicControlUnit::ElectronicControlUnit()
{
  m_bActivatedHydraulicJacks = false;
  m_bActivatedBeltTires = false;
  m_bActivatedIRIllumination = false;
}

ElectronicControlUnit::~ElectronicControlUnit()
{
  m_bActivatedHydraulicJacks = false;
  m_bActivatedBeltTires = false;
  m_bActivatedIRIllumination = false;
}

void ElectronicControlUnit::handleCommand(char cCommand)
{
  switch (cCommand)
  {
    case 'a':
      m_bActivatedHydraulicJacks = true;
      std::cout << "Hydraulic Jacks Activated" << std::endl;
      break;
    case 'e':
      m_bActivatedIRIllumination = true;
      std::cout << "Infrared Illumination Activated" << std::endl;
      break;
    case 'b':
      m_bActivatedBeltTires = true;
      std::cout << "Belt Tires Activated" << std::endl;
      break;
    case 'x':
      std::cout << "Ignition turned off" << std::endl;
      break;
    default:
    std::cout << "Invalid input" << std::endl;

  }
}

int main()
{
  ElectronicControlUnit ECU;
  char a = 'a';
  std::cout << "Press x to turn off or enter a steering wheel button(a, b, or e)" << std::endl;

  while (a != 'x'){
    std::cin >> a;
    ECU.handleCommand(a);
  }
  return 0;
}
