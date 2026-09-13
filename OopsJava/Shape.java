package inheritance;

public class Shape {

	    void shapeMethod() {
	        System.out.println("This is shape");
	    }
	}

	class Rectangle extends Shape {

	    void rectangleMethod() {
	        System.out.println("This is rectangular shape");
	    }
	}

	class Circle extends Shape {

	    void circleMethod() {
	        System.out.println("This is circular shape");
	    }
	}

	class Square extends Rectangle {

	    void squareMethod() {
	        System.out.println("Square is a rectangle");
	    }
	}

	public class Main {

	    public static void main(String[] args) {

	        Square s = new Square();

	        s.shapeMethod();

	        s.rectangleMethod();

	        s.squareMethod();
	    }
	}

