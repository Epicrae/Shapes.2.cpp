#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

// structs for all 8 shapes. 
struct SQUARE {
  double side;
};
struct RECTANGLE {
  double length;
  double width;
};
struct CIRCLE {
  double radius;
};
struct TRIANGLE {
  double side;
};
struct CUBE {	
	double side;
};
struct BOX {
  double length;
  double width;
  double height;
};
struct CYLINDER {
  double radius;
  double height;
};
struct PRISM {
  double side;
  double height;
};

//fucntion prototypes
void square_calculation(ostream& out, const SQUARE& square);
void rectangle_calculation(ostream& out, const RECTANGLE& rectangle);
void circle_calculation(ostream& out, const CIRCLE& circle);
void triangle_calculation(ostream& out, const TRIANGLE& triangle);
void cube_calculation(ostream& out, const CUBE& cube);
void box_calculation(ostream& out, const BOX& box);
void cylinder_calculation(ostream& out, const CYLINDER& cylinder);
void prism_calculation(ostream& out, const PRISM& prism);
vector<string> parseString(string str);

int main() {

	ifstream file_in("Shapes.input.txt");
	if (!file_in.is_open()) {
		cout << "Error opeing file" << endl;
		return 1;
	}
	ofstream file_out("Shapes.output.txt");//Open output file stream for writing 
	if (!file_out.is_open()) {
		cout << "Error opening output file";
		return 1;
	}
	string line;
	vector <SQUARE> squares;
	vector <RECTANGLE> rectangles;
	vector <CIRCLE> circles;
	vector <TRIANGLE> triangles;
	vector <CUBE> cubes;
	vector <BOX> boxes;
	vector <CYLINDER> cylinders;
	vector <PRISM> prisms;
	
while (getline(file_in, line)) {//Read lines from input file untill EOF
	if (line.empty()) continue;// skip empty lines
	vector<string> tokens = parseString(line);// parse strings into tokens 
	
	if (tokens[0] == "EOF") {//do not read EOF as error 
		break;
	}
	if (tokens[0] == "SQUARE" && tokens.size()== 2) {
		SQUARE square;
		square.side = { stod(tokens[1]) }; // Convert string to double
		squares.push_back(square);
	}
	else if (tokens[0] == "RECTANGLE" && tokens.size() == 3) {
		RECTANGLE rectangle = { stod(tokens[1]), stod(tokens[2]) };
		rectangles.push_back(rectangle);
	}
	else if (tokens[0] == "CIRCLE" && tokens.size() == 2) {
		CIRCLE circle = { stod(tokens[1]) };
		circles.push_back(circle);
	}
	else if (tokens[0] == "TRIANGLE" && tokens.size() == 2) {
		TRIANGLE triangle = { stod(tokens[1]) };
		triangles.push_back(triangle);
	}
	else if (tokens[0] == "CUBE" && tokens.size() == 2) {
		CUBE cube = { stod(tokens[1]) };
		cubes.push_back(cube);
	}
	else if (tokens[0] == "BOX" && tokens.size() == 4) {
		BOX box = { stod(tokens[1]), stod(tokens[2]), stod(tokens[3]) };
		boxes.push_back(box);
	}
	else if (tokens[0] == "CYLINDER" && tokens.size() == 3) {
		CYLINDER cylinder = { stod(tokens[1]), stod(tokens[2]) };
		cylinders.push_back(cylinder);
	}
	else if (tokens[0] == "PRISM" && tokens.size() == 3) {
		PRISM prism = { stod(tokens[1]), stod(tokens[2]) };
		prisms.push_back(prism);
	}
	else {
		cout << "Invalid shape: " << line << endl;
	}
	
  }
	file_in.close();

	for (const SQUARE& square : squares) {
		square_calculation(cout, square);
		square_calculation(file_out, square);
	}
	for (const RECTANGLE& rectangle : rectangles) {
		rectangle_calculation(cout, rectangle);
		rectangle_calculation(file_out, rectangle);
	}
	for (const CIRCLE& circle: circles) {
		circle_calculation(cout, circle);
		circle_calculation(file_out, circle);
	}
	for (const TRIANGLE& triangle : triangles) {
		triangle_calculation(cout, triangle);
		triangle_calculation(file_out, triangle);
	}
	for (const CUBE& cube : cubes) {
		cube_calculation(cout, cube);
		cube_calculation(file_out, cube);
	}
	for (const BOX& box : boxes) {
		box_calculation(cout, box);
		box_calculation(file_out, box);
	}
	for (const CYLINDER& cylinder : cylinders) {
		cylinder_calculation(cout, cylinder);
		cylinder_calculation(file_out, cylinder);
	}
	for (const PRISM& prism : prisms) {
		prism_calculation(cout, prism);
		prism_calculation(file_out, prism);
	}
	file_out.close();
}


void square_calculation(ostream& out, const SQUARE& square) {

  double area = square.side * square.side;//calculate the area of a square (side^2)
  double perimeter = 4 * square.side;
  out << "SQUARE side=" << square.side << " area=" << area << ", Perimeter =" << perimeter << endl;
}
void rectangle_calculation(ostream& out, const RECTANGLE& rectangle) {

  double area = rectangle.length * rectangle.width;// Calculate the area of the rectangle 
  out << "RECTANGLE length=" << rectangle.length << " width=" << rectangle.width << " area= " << std::fixed << std::setprecision(2) << area << endl;
  }
void circle_calculation(ostream& out, const CIRCLE& circle) {

  double pi = 3.14;
  double area = pi * circle.radius * circle.radius;// Calculate the area 
  out << "CIRCLE Radius=" << circle.radius << " area=" << std::fixed << std::setprecision(2) << area << endl;
}
void triangle_calculation(ostream& out, const TRIANGLE& triangle) {

  double area = (sqrt(3) / 4) * (triangle.side * triangle.side);// Calculate the area
  out << "TRIANGLE side=" << triangle.side << " area=" << std::fixed << std::setprecision(2) << area << endl;
}
void cube_calculation(ostream& out, const CUBE& cube) {

  double surface_area = 6 *cube.side * cube.side;
  double volume = pow(cube.side, 3);
// Output to console and file
  out << "CUBE side=" << cube.side << " surface area=" << surface_area << " volume=" << std::fixed << std::setprecision(2) << volume << endl;
}
void box_calculation(ostream& out, const BOX& box) {

  double surface_area = 2 * (box.length * box.width + box.length * box.height + box.width * box.height);  // Calculate the surface area
  double box_volume = box.length * box.width * box.height; // Calculate the volume 
  out << "BOX length=" << box.length << " width=" << box.width << " height=" << box.height << " surface area=" << surface_area << " volume=" << std::fixed << std::setprecision(2) << box_volume << endl;  
}
void cylinder_calculation(ostream& out, const CYLINDER& cylinder) {

  double surface_area = 2 * 3.14 * cylinder.radius * (cylinder.radius + cylinder.height);// Calculate the surface 
  double volume = 3.14 * cylinder.radius * cylinder.radius * cylinder.height; // Calculate the volume
  out << "CYLINDER radius=" << cylinder.radius << " height=" << cylinder.height << " surface area=" << std::fixed << std::setprecision(2) << surface_area << " volume=" << volume << endl;
}
void prism_calculation(ostream& out, const PRISM& prism) {

  double base_area = (sqrt(3) / 4) * pow(prism.side, 2);  // Calculate the base area
  double volume = base_area * prism.height;// Calculate the volume
  double surface_area = 2 * base_area + 3 * prism.side * prism.height;   // Calculate the surface area
  out << "PRISM side=" << prism.side << " height=" << prism.height << " surface area=" << surface_area << " volume=" << std::fixed << std::setprecision(2) << volume << endl;
 }

vector<string> parseString(string str)
{
	stringstream s(str);
	istream_iterator<string> begin(s), end;
	return vector<string>(begin, end);
}

