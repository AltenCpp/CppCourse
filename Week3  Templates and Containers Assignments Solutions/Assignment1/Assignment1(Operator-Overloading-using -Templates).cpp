
/*
Write a function template which receives two of any shapes from last week’s assignment, compares them, and
prints out the result.
Main Editors:TaycirLouati, Can and Ahmed Ibrahim

*/

#include "Assignment1.hpp"



int main()
{
    Circle circle_object;
    Triangle triagnle_object;
    Rectangle rectangle_object;
    Square square_object;

    std::cout<<"**Circle**\n";
    circle_object.SetShapeProperties();
    std::cout<<"**Triangle**\n"; 
    triagnle_object.SetShapeProperties();
    std::cout<<"**Rectangle**\n";
    rectangle_object.SetShapeProperties();
    std::cout<<"**Square**\n";
    square_object.SetShapeProperties();

    bool comparaison_overload_result; 

    std::cout<<"comparaison between shape1 circle and shape2 triangle\n";
    ShapeComparaison(circle_object, triagnle_object);

    std::cout<<"comparaison between shape1 rectangle and shape2 square\n";
    ShapeComparaison(rectangle_object, square_object);
    return 0; 
}
template <typename T1, typename T2>
static void ShapeComparaison(T1 shape1, T2 shape2)
{
    if((shape1.Area()==shape2.Area())&&(shape1.Perimeter()==shape2.Perimeter())){
        std::cout<<"Same Area. \n";
    }else if(shape1.Area()>shape2.Area()){
        std::cout<<"The area of "<<shape1.name()<< " is bigger than the area of "<< shape2.name()<<".\n";
    }else{
        std::cout<<"The area of "<<shape2.name()<< " is bigger than the area of "<< shape1.name()<<".\n";
    }

}