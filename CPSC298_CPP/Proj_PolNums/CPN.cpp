#include <iostream>
#include <fstream>

class CentralPolygonalNumbers
{
public:
  CentralPolygonalNumbers();
  CentralPolygonalNumbers(int Max);
  ~CentralPolygonalNumbers();
  void display();
  bool save(std::string strFilename);

private:
  int m_nMax;
  int* mp_iNumbers;
};

CentralPolygonalNumbers::CentralPolygonalNumbers()
{
  m_nMax = 0;
  mp_iNumbers = new int[m_nMax];
}

CentralPolygonalNumbers::CentralPolygonalNumbers(int max)
{
  m_nMax = max;
  mp_iNumbers = new int[m_nMax];

  for (int i = 0; i < m_nMax; i++)
  {
    mp_iNumbers[i] = (i*i + i + 2)/2;
  }
}

CentralPolygonalNumbers::~CentralPolygonalNumbers()
{
  delete[] mp_iNumbers;
  std::cout << "~CentralPolygonalNumbers called" << std::endl;
}

void CentralPolygonalNumbers::display()
{
  for (int i = 0; i < m_nMax; i++)
  {
    std::cout << mp_iNumbers[i] << std::endl;
  }
}

bool CentralPolygonalNumbers::save(std::string strFilename)
{
  std::ofstream ofsNumbers;
  ofsNumbers.open(strFilename);
  for (int i = 0; i < m_nMax; i++)
  {
    ofsNumbers << mp_iNumbers[i] << std::endl;
  }
  ofsNumbers.close();
}

int main()
{
  CentralPolygonalNumbers cpn(10);
  cpn.display();
  cpn.save("CPN");

  return 0;
}
