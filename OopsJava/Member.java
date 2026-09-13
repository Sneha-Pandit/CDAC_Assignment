package inheritance;

public class Member {


	    String name;
	    int age;
	    String phone;
	    String address;
	    double salary;

	    void printSalary() {
	        System.out.println("Salary: " + salary);
	    }
	}

	class PrimeMembers extends Member {

	    int joiningYear;
	    double joiningFees;
	    boolean isActive;

	    void display() {

	        System.out.println("Name: " + name);
	        System.out.println("Age: " + age);
	        System.out.println("Phone: " + phone);
	        System.out.println("Address: " + address);
	        System.out.println("Salary: " + salary);

	        System.out.println("Joining Year: " + joiningYear);
	        System.out.println("Joining Fees: " + joiningFees);
	        System.out.println("Active: " + isActive);
	    }
	}

	public class Main {

	    public static void main(String[] args) {

	        PrimeMembers p = new PrimeMembers();

	        p.name = "Sneha";
	        p.age = 22;
	        p.phone = "9876543210";
	        p.address = "Mumbai";
	        p.salary = 50000;

	        p.joiningYear = 2026;
	        p.joiningFees = 2000;
	        p.isActive = true;

	        p.printSalary();
	        p.display();
	    }
	}

