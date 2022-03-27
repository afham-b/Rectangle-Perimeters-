#include <iostream>
#include <string> 
using namespace std; 

class Rectangle{
protected:
  double length, width; 

public: 
  double get_length() const {return length;} 
  double get_width() const {return width;} 
  double area() const {return length*width; }
  double perimeter() const {return 2* (get_length()+width);}
  void set_length(double l) {if (l>0){ length = l;}}
  void set_width(double w) { if (w>0){ width=w;};}
  string str() const; 
};

class Square: public Rectangle {   //public inheritance 
  public:
    void set_length(double l)
        { Rectangle::set_length(l); Rectangle::set_width(l); } //using rectangle scope becuase length and width are private parts of Rectangle class. 
    void set_width (double w) {set_length(w);} 
    string str() const; 
}; 

string Rectangle::str() const{
  string s = "Rectangle"; 
  s+= to_string(length) + "x" + to_string(width); 
  return s; 
}

string Square:: str() const{
  string s= "Rectangle"; 
  s+= to_string(length) + "x" + to_string(width); 
  return s;
}

void print_shape (const Rectangle& rect) {
  cout << rect.str() <<endl;
  cout << "  area= " << rect.area() << "perimeter=" 
      << rect.perimeter() << endl;   
}

int main(){
  Rectangle r1, r2; 
  r1.set_length(2);
  r1.set_width(3);
  r2.set_length(5.1);
  r2.set_width(0.5);

  cout << r1.area() << " " << r1.perimeter() <<endl; 
  cout << r2.area() << " " << r2.perimeter() <<endl; 

  Square s1, s2; 
  s1.set_length(3);
  s2.set_width(2.5);
  cout << s1.area() << " " << s1.perimeter() <<endl; 
  //cout << s1.str() << endl;
  cout << s2.area() << " " << s2.perimeter() <<endl; 
  //cout << s2.str() << endl;
return 0; 
}
