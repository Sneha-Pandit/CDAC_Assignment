package assignment;

public class Employee {


	    String name;
	    int year;
	    double salary;
	    String address;

	    Employee(String n, int y, double s, String a) {
	        name = n;
	        year = y;
	        salary = s;
	        address = a;
	    }

	    void display() {
	        System.out.println(
	            name + "\t\t" + year + "\t\t" + salary + "\t\t" + address
	        );
	    }

	    public static void main(String[] args) {

	        Employee e1 = new Employee(
	            "Robert", 1994, 50000, "64C- WallsStreat"
	        );

	        Employee e2 = new Employee(
	            "Sam", 2000, 45000, "68D- WallsStreat"
	        );

	        Employee e3 = new Employee(
	            "John", 1999, 55000, "26B- WallsStreat"
	        );

	        System.out.println("Name\t\tYear of Joining\tSalary\t\tAddress");

	        e1.display();
	        e2.display();
	        e3.display();
	    }
	}

