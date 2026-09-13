package inheritance;

public class Rectange {


	    int length;
	    int breadth;

	    Rectangle(int l, int b) {
	        length = l;
	        breadth = b;
	    }

	    void area() {
	        System.out.println("Area = " + (length * breadth));
	    }

	    void perimeter() {
	        System.out.println("Perimeter = " + (2 * (length + breadth)));
	    }
	}

	class Square extends Rectangle {

	    Square(int side) {
	        super(side, side);
	    }
	}

	public class Main {

	    public static void main(String[] args) {

	        Rectangle r = new Rectangle(10, 5);

	        r.area();
	        r.perimeter();

	        Square s = new Square(5);

	        s.area();
	        s.perimeter();
	    }
	}

