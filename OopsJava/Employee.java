package employee1;

import java.util.Scanner;
import java.io.FileWriter;
import java.io.File;
import java.io.FileNotFoundException;

class Employee
{
    int id;
    String name;
    String phone;
    String type;

    Employee(int id, String name, String phone, String type)
    {
        this.id = id;
        this.name = name;
        this.phone = phone;
        this.type = type;
    }

    void show()
    {
        System.out.println("ID : " + id);
        System.out.println("Name : " + name);
        System.out.println("Phone : " + phone);
        System.out.println("Type : " + type);
        System.out.println("----------------");
    }
}


class Node
{
    Employee employee;
    Node next;
    Node previous;

    Node(Employee employee)
    {
        this.employee = employee;
        next = null;
        previous = null;
    }
}


class EmployeeList
{
    Node head;
    Node tail;
    Node current;

    void add(Employee e)
    {
        Node n = new Node(e);

        if(head == null)
        {
            head = n;
            tail = n;
            current = head;
        }
        else
        {
            tail.next = n;
            n.previous = tail;
            tail = n;
        }

        System.out.println("Employee Added");
    }


    void displayAll()
    {
        Node temp = head;

        if(temp == null)
        {
            System.out.println("No Employee");
        }

        while(temp != null)
        {
            temp.employee.show();
            temp = temp.next;
        }
    }


    void first()
    {
        if(head == null)
        {
            System.out.println("No Employee");
        }
        else
        {
            current = head;
            current.employee.show();
        }
    }


    void next()
    {
        if(current == null)
        {
            System.out.println("No Employee");
        }
        else if(current.next == null)
        {
            System.out.println("No Next Employee");
        }
        else
        {
            current = current.next;
            current.employee.show();
        }
    }


    void previous()
    {
        if(current == null)
        {
            System.out.println("No Employee");
        }
        else if(current.previous == null)
        {
            System.out.println("No Previous Employee");
        }
        else
        {
            current = current.previous;
            current.employee.show();
        }
    }


    void last()
    {
        if(tail == null)
        {
            System.out.println("No Employee");
        }
        else
        {
            current = tail;
            current.employee.show();
        }
    }


    void showType(String type)
    {
        Node temp = head;

        while(temp != null)
        {
            if(temp.employee.type.equals(type))
            {
                temp.employee.show();
            }

            temp = temp.next;
        }
    }


    void sortAscending()
    {
        Node i = head;

        while(i != null)
        {
            Node j = i.next;

            while(j != null)
            {
                if(i.employee.name.compareTo(j.employee.name) > 0)
                {
                    Employee temp = i.employee;
                    i.employee = j.employee;
                    j.employee = temp;
                }

                j = j.next;
            }

            i = i.next;
        }

        System.out.println("Sorted Ascending");
    }


    void sortDescending()
    {
        Node i = head;

        while(i != null)
        {
            Node j = i.next;

            while(j != null)
            {
                if(i.employee.name.compareTo(j.employee.name) < 0)
                {
                    Employee temp = i.employee;
                    i.employee = j.employee;
                    j.employee = temp;
                }

                j = j.next;
            }

            i = i.next;
        }

        System.out.println("Sorted Descending");
    }


    void save()
    {
        try
        {
            FileWriter f = new FileWriter("employee.txt");

            Node temp = head;

            while(temp != null)
            {
                f.write(temp.employee.id + "\n");
                f.write(temp.employee.name + "\n");
                f.write(temp.employee.phone + "\n");
                f.write(temp.employee.type + "\n");

                temp = temp.next;
            }

            f.close();

            System.out.println("File Saved");
        }
        catch(Exception e)
        {
            System.out.println("File Error");
        }
    }


    void load()
    {
        try
        {
            File f = new File("employee.txt");
            Scanner s = new Scanner(f);

            while(s.hasNextLine())
            {
                int id = Integer.parseInt(s.nextLine());
                String name = s.nextLine();
                String phone = s.nextLine();
                String type = s.nextLine();

                Employee e = new Employee(id, name, phone, type);

                add(e);
            }

            s.close();

            System.out.println("File Loaded");
        }
        catch(FileNotFoundException e)
        {
            System.out.println("File Not Found");
        }
    }
}


 public class EmployeeManagement
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        EmployeeList list = new EmployeeList();

        int choice;

        do
        {
            System.out.println("\n===== EMPLOYEE MENU =====");
            System.out.println("1. Add Employee");
            System.out.println("2. Display");
            System.out.println("3. Sort");
            System.out.println("4. Save to File");
            System.out.println("5. Load from File");
            System.out.println("6. Exit");

            System.out.print("Enter choice : ");
            choice = sc.nextInt();


            // ADD MENU

            if(choice == 1)
            {
                int ch;

                do
                {
                    System.out.println("\n1. Manager");
                    System.out.println("2. Engineer");
                    System.out.println("3. Sales Person");
                    System.out.println("4. Exit");

                    System.out.print("Enter choice : ");
                    ch = sc.nextInt();

                    if(ch >= 1 && ch <= 3)
                    {
                        System.out.print("Enter ID : ");
                        int id = sc.nextInt();

                        sc.nextLine();

                        System.out.print("Enter Name : ");
                        String name = sc.nextLine();

                        System.out.print("Enter Phone : ");
                        String phone = sc.nextLine();

                        String type = "";

                        if(ch == 1)
                        {
                            type = "Manager";
                        }
                        else if(ch == 2)
                        {
                            type = "Engineer";
                        }
                        else if(ch == 3)
                        {
                            type = "Sales Person";
                        }

                        Employee e = new Employee(id, name, phone, type);

                        list.add(e);
                    }

                }while(ch != 4);
            }


            // DISPLAY MENU

            else if(choice == 2)
            {
                int ch;

                do
                {
                    System.out.println("\n1. All Employees");
                    System.out.println("2. First Employee");
                    System.out.println("3. Next Employee");
                    System.out.println("4. Previous Employee");
                    System.out.println("5. Last Employee");
                    System.out.println("6. Exit");

                    System.out.print("Enter choice : ");
                    ch = sc.nextInt();

                    if(ch == 1)
                    {
                        list.displayAll();
                    }
                    else if(ch == 2)
                    {
                        list.first();
                    }
                    else if(ch == 3)
                    {
                        list.next();
                    }
                    else if(ch == 4)
                    {
                        list.previous();
                    }
                    else if(ch == 5)
                    {
                        list.last();
                    }

                }while(ch != 6);
            }


            // SORT MENU

            else if(choice == 3)
            {
                int ch;

                do
                {
                    System.out.println("\n1. All Managers");
                    System.out.println("2. All Engineers");
                    System.out.println("3. All Sales Person");
                    System.out.println("4. All Employees Ascending");
                    System.out.println("5. All Employees Descending");
                    System.out.println("6. Exit");

                    System.out.print("Enter choice : ");
                    ch = sc.nextInt();

                    if(ch == 1)
                    {
                        list.showType("Manager");
                    }
                    else if(ch == 2)
                    {
                        list.showType("Engineer");
                    }
                    else if(ch == 3)
                    {
                        list.showType("Sales Person");
                    }
                    else if(ch == 4)
                    {
                        list.sortAscending();
                        list.displayAll();
                    }
                    else if(ch == 5)
                    {
                        list.sortDescending();
                        list.displayAll();
                    }

                }while(ch != 6);
            }


            // SAVE

            else if(choice == 4)
            {
                list.save();
            }


            // LOAD

            else if(choice == 5)
            {
                list.load();
            }


            else if(choice == 6)
            {
                System.out.println("Program End");
            }

        }while(choice != 6);

        sc.close();
    }
}


