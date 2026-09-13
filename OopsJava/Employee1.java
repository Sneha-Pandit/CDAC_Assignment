package assignment;

public class Employee1 {

	    double salary;
	    int hours;

	    void getInfo(double s, int h) {
	        salary = s;
	        hours = h;
	    }

	    void addSal() {
	        if (salary < 500) {
	            salary = salary + 10;
	        }
	    }

	    void addWork() {
	        if (hours > 6) {
	            salary = salary + 5;
	        }
	    }

	    void displaySalary() {
	        System.out.println("Final Salary = $" + salary);
	    }

	    public static void main(String[] args) {

	        Employee1 e = new Employee1();

	        e.getInfo(400, 8);

	        e.addSal();
	        e.addWork();

	        e.displaySalary();
	    }
	}
