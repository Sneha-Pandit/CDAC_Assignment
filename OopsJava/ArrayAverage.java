package array;



	public class ArrayAverage {

	    public static void main(String[] args) {

	        Scanner sc = new Scanner(System.in);

	        System.out.print("Enter size: ");
	        int n = sc.nextInt();

	        int[] arr = new int[n];

	        int sum = 0;

	        for (int i = 0; i < n; i++) {

	            arr[i] = sc.nextInt();

	            sum = sum + arr[i];
	        }

	        double average = (double) sum / n;

	        System.out.println("Average = " + average);
	    }
	}

