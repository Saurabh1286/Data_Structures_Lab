import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Sort1 {
    int[] arr;

    Sort1 (int[] arr){
        this.arr = arr;
    }

    static void printarr (int[] arr) {
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }

    static void swap (int a, int b, int[] arr) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    void selectionsort () {
        int[] temp = arr;
        for (int i = 0; i < arr.length; i++) {
            int min = i;
            for (int j = i; j < arr.length; j++) {
                if (temp[j] < temp[min]) {
                    min = j;
                }
            }
            swap(min, i, temp);
        }
        System.out.println("\nSelection Sort :");
        System.out.print("Sorted Array : ");
        printarr(temp);
    }

    void insertionsort () {
        int[] temp = arr;
        for  (int i = 1; i < arr.length; i++) {
            for (int j = i; j > 0; j--) {
                if (temp[j] < temp[j-1]) {
                    swap(j, j-1, temp);
                }
            }
        }
        System.out.println("\nInsertion Sort :");
        System.out.print("Sorted Array : ");
        printarr(temp);
    }

    void mergesort () {
        int[] temp = arr;
        mergesort_priv(temp);
        System.out.println("\nMerge Sort :");
        System.out.print("Sorted Array : ");
        printarr(temp);
    }

    private void mergesort_priv (int[] temp) {
        if (temp.length < 2) {
            return;
        }
        int mid = temp.length / 2;
        int[] left = Arrays.copyOfRange(temp, 0, mid);
        int[] right = Arrays.copyOfRange(temp, mid, temp.length);

        mergesort_priv(left);
        mergesort_priv(right);

        merge(temp, left, right);
    }

    private void merge (int[] array, int[] left, int[] right) {
        int i = 0, j = 0, k = 0;
        while (i < left.length && j < right.length) {
            if (left[i] <= right[j]) {
                array[k++] = left[i++];
            }
            else {
                array[k++] = right[j++];
            }
        }

        while (i < left.length) {
            array[k++] = left[i++];
        }

        while (j < right.length) {
            array[k++] = right[j++];
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
        System.out.print("Unsorted Array : ");
        int[] array = Arrays.stream(in.readLine().replaceAll("\\s+", " ").split(" ")).mapToInt(Integer::parseInt).toArray();
        Sort1 sortarr = new Sort1 (array);
        sortarr.selectionsort();
        System.out.println();
        sortarr.insertionsort();
        System.out.println();
        sortarr.mergesort();
    }
}
