import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static MyArray myArray = new MyArray();
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int option;

        do {
            System.out.println("1.Add Elements in the array");
            System.out.println("2.Addition of the element");
            System.out.println("3.Deletion of the element");
            System.out.println("4.Exit");
            option = scanner.nextInt();
            switch (option) {
                case 1: {
                    creatingArray();
                    break;
                }
                case 2: {
                    addition();
                    break;
                }
                case 3: {
                    deletion();
                    break;
                }
                case 4: {
                    break;
                }
                default:
                    System.out.println("WRONG CHOICE!!!!!!!!!!!!!!!!!!!!");

            }
        } while (option != 5);
    }

    public static void creatingArray() {
        int [] array;
        int no_of_elements;
        System.out.println("Enter the number of the elements");
        no_of_elements=scanner.nextInt();
        array=new int[no_of_elements];
        System.out.println("Enter the " + no_of_elements + " in the array ");
        for(int i=0;i<no_of_elements;i++){
            array[i]=scanner.nextInt();
        }
        myArray.setArray(array);
    }
    public static void addition(){
        int element;
        int indexposition;
        System.out.println("Enter the index position ");
        indexposition=scanner.nextInt();
        System.out.println("Enter the element ");
        element=scanner.nextInt();
        myArray.addElements(element,indexposition);
    }
    public static void deletion(){
        int num;
        System.out.println("Enter the Element which you want to delete");
        num=scanner.nextInt();
        myArray.deleteElements(num);
        System.out.print("DELETED ELEMENT IN THE ARRAY: " + num );
        System.out.print(" REMAINING ELEMENTS IN THE ARRAY: " + Arrays.toString(myArray.getArray()));
        System.out.println();
    }

}
