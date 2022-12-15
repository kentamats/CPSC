#include <iostream>

class Shape
{

public:
  Shape(double dHeight, double dWidth)
  {
    m_dHeight = dHeight;
    m_dWidth = dWidth;
    m_strType = "";
  }
  virtual ~Shape()
  {
    m_dHeight = 0;
    m_dWidth = 0;
    m_strType = "";
  }
  virtual void scale(double dScaleFactor) = 0;
  virtual double area() = 0;
  virtual double perimeter() = 0;
  virtual void displayProperties()
  {
    std::cout << "shape type: " << m_strType << ", height: " << m_dHeight << ", width: " << m_dWidth << std::endl;
  }

protected:
  double m_dHeight;
  double m_dWidth;
  std::string m_strType;
};

class Rectangle : public Shape
{
  public:
    Rectangle(double dHeight, double dWidth)
    {
      m_dHeight = dHeight;
      m_dWidth = dWidth;
      m_strType = "Rectangle";
    }
    virtual ~Rectangle();
    void scale(double dScaleFactor)
    {
      m_dHeight *= dScaleFactor;
      m_dWidth *= dScaleFactor;
    }

    double area()
    {
      return m_dHeight*m_dWidth;
    }

    double perimeter()
    {
      return m_dHeight*2 + m_dWidth*2;
    }
};

class Circle : public Shape
{
public:
  Circle(double dHeight, double dWidth)
  {
    m_dHeight = dHeight;
    m_dWidth = dWidth;
    m_strType = "Circle";
  }

  virtual ~Circle();

  void scale(double dScaleFactor)
  {
    m_dHeight *= dScaleFactor;
    m_dWidth *= dScaleFactor;
  }

  double area()
  {
    return (m_dWidth/2)*(m_dWidth/2)*3.14;
  }

  double perimeter()
  {
    return m_dWidth*3.14;
  }
};

int main()
{
  Rectangle* p_shapeRectangle = new Rectangle(2.0, 3.0);
  Circle* p_shapeCircle = new Circle(2.0, 2.0);

  Shape* p_shapes[2];

  p_shapes[0] = p_shapeCircle;
  p_shapes[1] = p_shapeRectangle;

  for (int i = 0; i<2 ; i++)
  {
    p_shapes[i]->displayProperties();
    std::cout <<"Area: " << p_shapes[i]->area() << ", perimeter: " << p_shapes[i]->perimeter() << std::endl;;
  }
  return 0;
}
