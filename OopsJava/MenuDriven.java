package calender;


import java.util.Scanner;
public class MenuDriven{

 

    private int day;
    private int month;
    private int year;

    // Constructor
    MenuDriven () {
        day = 1;
        month = 1;
        year = 2025;
    }

    // Set Day
    public void setDay(int day) {

        if (day >= 1 && day <= daysInMonth()) {
            this.day = day;
        } else {
            this.day = 1;
        }
    }

    // Get Day
    public int getDay() {
        return day;
    }

    // Set Month
    public void setMonth(int month) {

        if (month >= 1 && month <= 12) {
            this.month = month;
        } else {
            this.month = 1;
        }
    }

    // Get Month
    public int getMonth() {
        return month;
    }

    // Set Year
    public void setYear(int year) {

        if (year >= 2025 && year <= 2027) {
            this.year = year;
        } else {
            this.year = 2025;
        }
    }

    // Get Year
    public int getYear() {
        return year;
    }

    // Check Leap Year
    public boolean isLeapYear() {

        if (year % 400 == 0) {
            return true;
        }

        if (year % 100 == 0) {
            return false;
        }

        if (year % 4 == 0) {
            return true;
        }

        return false;
    }

    // Find number of days in current month
    public int daysInMonth() {

        if (month == 2) {

            if (isLeapYear()) {
                return 29;
            } else {
                return 28;
            }
        }

        if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        }

        return 31;
    }

    // Display Date
    public void display() {
        System.out.println(day + "/" + month + "/" + year);
    }

    // Add one day
    public void addDay() {

        day++;

        if (day > daysInMonth()) {
            day = 1;
            month++;
        }

        if (month > 12) {
            month = 1;
            year++;
        }
    }





    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        MenuDriven c1 = new MenuDriven ();

        int choice;

        do {

            System.out.println("\n1. Enter Day");
            System.out.println("2. Enter Month");
            System.out.println("3. Enter Year");
            System.out.println("4. Display Date");
            System.out.println("5. Add Day");
            System.out.println("6. Exit");

            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {

                case 1:
                    System.out.print("Enter Day: ");
                    c1.setDay(sc.nextInt());
                    System.out.println("Day: " + c1.getDay());
                    break;

                case 2:
                    System.out.print("Enter Month: ");
                    c1.setMonth(sc.nextInt());
                    System.out.println("Month: " + c1.getMonth());
                    break;

                case 3:
                    System.out.print("Enter Year: ");
                    c1.setYear(sc.nextInt());
                    System.out.println("Year: " + c1.getYear());
                    break;

                case 4:
                    System.out.print("Date: ");
                    c1.display();
                    break;

                case 5:
                    c1.addDay();
                    c1.display();
                    break;

                case 6:
                    System.out.println("Exiting");
                    break;

                default:
                    System.out.println("Invalid choice");
            }

        } while (choice != 6);

        sc.close();
    }
}




