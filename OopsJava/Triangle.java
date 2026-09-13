package assignment;

public class Triangle {

	    int side1, side2, side3;

	    Triangle(int a, int b, int c) {
	        side1 = a;
	        side2 = b;
	        side3 = c;
	    }

	    void area() {
	        double s = (side1 + side2 + side3) / 2.0;

	        double area = Math.sqrt(
	            s * (s - side1) * (s - side2) * (s - side3)
	        );

	        System.out.println("Area = " + area);
	    }

	    void perimeter() {
	        int perimeter = side1 + side2 + side3;

	        System.out.println("Perimeter = " + perimeter);
	    }

	    public static void main(String[] args) {

	        Triangle t = new Triangle(3, 4, 5);

	        t.area();
	        t.perimeter();
	    }
	}

