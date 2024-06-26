import java.util.Random;

public class QuickSort {
    static Random rand = new Random();

    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static int partition(int[] arr, int low, int high) {
        int pivotIndex = low + rand.nextInt(high - low + 1);
        int pivot = arr[pivotIndex];
        swap(arr, pivotIndex, high);
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, high);
        return i + 1;
    }

    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    public static void main(String[] args) {
        int n = 100000;
        int[] arr = new int[n];

        Random rand = new Random();
        for (int i = 0; i < n; i++) {
            arr[i] = rand.nextInt();
        }

        long startTime = System.nanoTime();
        quickSort(arr, 0, n - 1);
        long endTime = System.nanoTime();

        double timeTaken = (endTime - startTime) / 1e9;
        System.out.println("QuickSort executed in " + timeTaken + " seconds");
    }
}
