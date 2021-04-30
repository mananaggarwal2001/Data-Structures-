import java.util.Arrays;
import java.util.Scanner;

class MyArray implements Arrays_req {
    private int[] Array;

    public MyArray() {
        Array = new int[0];
    }


    public int[] getArray() {
        return Array;
    }

    public void setArray(int[] array) {
        Array = array;
    }

    @Override
    public int addElements(int element, int indexPosition) {
        int[] array = new int[Array.length + 1];
        for (int i = 0; i < array.length; i++) {
            array[i] = 0;
        }
        for (int i = 0; i < array.length; i++) {
            if (i == indexPosition) {
                array[i] = element;
            }
        }
        for (int i = 0, j = 0; (i < array.length - 1 | j < Array.length); i++) {
            if (array[i] == 0) {
                array[i] = Array[j];
                j++;
            }
        }

        Array = array;
        System.out.println(Arrays.toString(Array));
        return 0;
    }

    @Override
    public int[] deleteElements(int num) {
        int[] array = new int[Array.length - 1];
        for (int i = 0, j = 0; (i < Array.length | j < array.length); i++) {
            if (Array[i] == num) {
                continue;
            } else if (Array[i] != num) {
                array[j] = Array[i];
                j++;
            } else {
                System.out.println("Element Not Found in the array");
            }
        }
        System.out.println(Arrays.toString(array));
        Array = array;
        return Array;
    }
}
