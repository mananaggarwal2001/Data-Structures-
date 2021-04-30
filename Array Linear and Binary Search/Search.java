import java.util.Arrays;

public class Search implements Searches {
    private int[] array = new int[0];
    private int mid;
    private int low;
    private int high;
    @Override
    public int[] Elements_Insertion_In_Array(int[] Array) {
        array = Array;
        return array;
    }

    @Override
    public void LinearSearch(int Element) {
        boolean flag =false;
        int position = 0;
        for (int i = 0; i < array.length; i++) {
            if (array[i] == Element) {
              flag=true;
              position=i;
            }
        }
        if(flag){
            System.out.println("Element: "+ Element +" was Found at: "+ position + " position ");
        }else{
            System.out.println("Element: " + Element + " was not found ");
        }
    }

    @Override
    public void Binary_Search(int Element) {
        low =0;
        high=array.length-1;
        int position= 0;
        boolean flag=false;
        while(low<=high){
            mid=(low+high)/2;
            if(array[mid]<Element){
                low = mid+1;
            }else if(array[mid]>Element){
                high=mid-1;
            }
            if(array[mid]==Element){
                flag=true;
                position=mid;
                break;
            }
        }
        if(flag){
            System.out.println("Element: "+ Element + " was found at: " + position);
            position=0;
            flag=false;
        }else{
            System.out.println("Element: " + Element + " was not found ");
        }
    }
}
