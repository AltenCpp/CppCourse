#include <iostream>
#include<cmath>

const float  PI_F=3.0f;

class Shape
{
    protected: 
        float width; 
        float length; 
    public: 
        void SetShapeProperties() 
        {
            std::cout<<"Enter the width of the shape\n";
            std::cin>>width;
            std::cout<<"Enter the length of the shape\n";
            std::cin>>length;
        }

        virtual float Area() = 0; 
        virtual float Perimeter() = 0;

        // Overload < operator.
        bool operator<(Shape& shape) 
        {
            bool equality_test = (this->Area() == shape.Area()); 
            bool operation_result;
            if (equality_test)
            {
                operation_result = this->Perimeter() < shape.Perimeter(); 
            }
            else 
            {
                operation_result = this->Area() < shape.Area();
            }
            
            return (bool)operation_result;
        }
        bool operator>(Shape& shape) 
        {
            bool equality_test = (this->Area() == shape.Area()); 
            bool operation_result;
            if (equality_test)
            {
                operation_result = this->Perimeter() > shape.Perimeter(); 
            }
            else 
            {
                operation_result = this->Area() > shape.Area();
            }
            
            return  (bool)operation_result;
        }
        bool operator==(Shape& shape) 
        {
            bool area_equality = (this->Area() == shape.Area()); 
            bool perimeter_equality = (this->Perimeter() == shape.Perimeter());
            bool operation_result = false;
            
            if (area_equality && perimeter_equality)
                operation_result = true;
            return  (bool)operation_result;
        }
        
};

class Circle : public Shape
{
    public: 
        void SetShapeProperties() 
        {
            std::cout<<"Enter the radius of the circle\n";
            std::cin>>width;
            length = width;
        }
        float Area()
        {
            //PI*r^2
            float area = PI_F*(width*width);
            std::cout<<"Circle  Area = "<<area<<"\n";
            return area;
        }
        float Perimeter()
        {
            //2πr
            float perimeter = 2*PI_F*width;
            std::cout<<"Circle Perimeter = "<<perimeter<<"\n";
            return perimeter;
        }
        std::string name(){
        return "Circle";
    }
}; 
class Triangle : public Shape
{
    public: 
        float Area()
        {
            //w*l/2
            float area = width*length/2;
            std::cout<<"Triangle Area = "<<area<<"\n";
            return area;
        }
        float Perimeter()
        {
            //width+length + sqrt(sqr(width)+sqr(length))
            float perimeter = width+length + sqrt((width*width)+(length*length));
            std::cout<<"Triangle Perimeter = "<<perimeter<<"\n";
            return perimeter;
        }
        std::string name(){
        return "Triangle";
    }
};
class Rectangle : public Shape
{
    public: 
        float Area()
        {
            float area = width*length;
            std::cout<<"Rectangle Area = "<<area<<"\n";
            return area;
        }
        float Perimeter()
        {
            //
            float perimeter = 2*width + 2*length;
            std::cout<<"Rectangle Perimeter  = "<<perimeter<<"\n";
            return perimeter;
        }
        std::string name(){
        return "Rectangle";
    }
};
class Square : public Rectangle
{
    public: 
        void SetShapeProperties() 
            {
                std::cout<<"Enter the width of the square\n";
                std::cin>>width;
                length = width;
            }
        float Area()
        {
            //w*l
            float area = width*width;
            std::cout<<"Square Area  = "<<area<<"\n";
            return area;
        }
        float Perimeter()
        {
            //
            float perimeter = 4*width;
            std::cout<<"Square Perimeter = "<<perimeter<<"\n";
            return perimeter;
        }
        std::string name(){
        return "Square";
    }
};

template <typename T1, typename T2>
static void ShapeComparaison(T1 shape1, T2 shape2);