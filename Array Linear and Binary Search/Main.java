import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static Searches myArray = new Search();
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int option;
        do {
            System.out.println("1.Add Elements in the array");
            System.out.println("2.Do Linear Search");
            System.out.println("3.Do Binary Search");
            System.out.println("4.Exit");
            option = scanner.nextInt();
            switch (option) {
                case 1: {
                    ElementsIntheArray();
                    break;
                }
                case 2: {
                    LinearSearch();
                    break;
                }
                case 3: {
                    BinarySearch();
                    break;
                }
                case 4:{
                    break;
                }
                default:
                    System.out.println("WRONG CHOICE!!!!!!!!!!!!!!!!!!!!");

            }
        } while (option != 4);
    }

    public static void ElementsIntheArray() {
        int[] array;
        int no_of_elements;
        System.out.println("Enter the number of the elements");
        no_of_elements = scanner.nextInt();
        array = new int[no_of_elements];
        System.out.println("Enter the " + no_of_elements + " in the array ");
        for (int i = 0; i < no_of_elements; i++) {
            array[i] = scanner.nextInt();
        }
        myArray.Elements_Insertion_In_Array(array);
    }

    public static void LinearSearch() {
        int element;
        System.out.println("Enter the element Which you Want to Search:");
        element = scanner.nextInt();
        myArray.LinearSearch(element);
    }

    public static void BinarySearch(){
        int element;
        System.out.println("Enter the element Which you Want to do Binary Search: ");
        element = scanner.nextInt();
        myArray.Binary_Search(element);

    }

}


